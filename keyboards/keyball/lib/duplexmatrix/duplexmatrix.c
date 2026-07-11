/*
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string.h>
#include "quantum.h"
#include "matrix.h"
#include "debounce.h"
#include "timer.h"

#ifdef SPLIT_KEYBOARD
#    include "split_common/split_util.h"
#    include "split_common/transactions.h"
#endif

#define PINNUM_ROW (MATRIX_ROWS / 2)
#define ROWS_PER_HAND (MATRIX_ROWS / 2)
#define PINNUM_COL (MATRIX_COLS / 2)

#define MATRIXSIZE_PER_HAND (ROWS_PER_HAND * sizeof(matrix_row_t))

static pin_t row_pins[PINNUM_ROW] = MATRIX_ROW_PINS;
static pin_t col_pins[PINNUM_COL] = MATRIX_COL_PINS;

static inline void set_pin_input(pin_t pin) {
    setPinInputHigh(pin);
}

static void set_pins_input(pin_t* pins, uint8_t n) {
    for (uint8_t i = 0; i < n; i++) {
        set_pin_input(pins[i]);
    }
}

static inline void set_pin_output(pin_t pin) {
    setPinOutput(pin);
    writePinLow(pin);
}

static inline bool get_pin(pin_t pin) {
    return readPin(pin);
}

__attribute__((weak)) void duplex_scan_raw_post_kb(matrix_row_t out_matrix[]) {}

// Extra settle between opposite scan directions. Shared row/col pins can
// otherwise false-trigger on rolls like O→I / U→O / P→I.
#ifndef DUPLEX_MATRIX_SETTLE_US
#    define DUPLEX_MATRIX_SETTLE_US 100
#endif

// After a *stable* key release, ignore NEW opposite-phase keys on the same row.
// Only keys held across 2+ scans arm this — 1-scan ghosts must not arm inhibit
// (that previously blocked real keys and caused "out"→"otu" / "tou").
#ifndef DUPLEX_MATRIX_OPPOSITE_INHIBIT_MS
#    define DUPLEX_MATRIX_OPPOSITE_INHIBIT_MS 0
#endif

#define DUPLEX_PHASE_A_MASK (((matrix_row_t)1 << PINNUM_COL) - 1)
#define DUPLEX_PHASE_B_MASK (DUPLEX_PHASE_A_MASK << PINNUM_COL)

#if DUPLEX_MATRIX_OPPOSITE_INHIBIT_MS > 0
static matrix_row_t duplex_prev[PINNUM_ROW];
static matrix_row_t duplex_stable[PINNUM_ROW];
static matrix_row_t duplex_inhibit_mask[PINNUM_ROW];
static uint16_t     duplex_inhibit_start[PINNUM_ROW];

static void duplex_filter_opposite_inhibit(matrix_row_t out_matrix[]) {
    for (uint8_t row = 0; row < PINNUM_ROW; row++) {
        matrix_row_t raw           = out_matrix[row];
        matrix_row_t released_stable = duplex_stable[row] & ~raw;
        matrix_row_t result          = raw;

        // Arm only when a key that was held for 2+ scans releases.
        if (released_stable & DUPLEX_PHASE_A_MASK) {
            duplex_inhibit_mask[row]  = DUPLEX_PHASE_B_MASK;
            duplex_inhibit_start[row] = timer_read();
        } else if (released_stable & DUPLEX_PHASE_B_MASK) {
            duplex_inhibit_mask[row]  = DUPLEX_PHASE_A_MASK;
            duplex_inhibit_start[row] = timer_read();
        }

        if (duplex_inhibit_mask[row] != 0 && timer_elapsed(duplex_inhibit_start[row]) < DUPLEX_MATRIX_OPPOSITE_INHIBIT_MS) {
            // Keep already-held opposite keys; drop only new ones (release ghosts).
            result &= ~(duplex_inhibit_mask[row] & ~duplex_prev[row]);
        } else {
            duplex_inhibit_mask[row] = 0;
        }

        duplex_stable[row] = duplex_prev[row] & result;
        duplex_prev[row]   = result;
        out_matrix[row]    = result;
    }
}
#endif

static void duplex_scan_raw(matrix_row_t out_matrix[]) {
    // Phase A: drive rows, read cols (matrix bits 0-3)
    for (uint8_t row = 0; row < PINNUM_ROW; row++) {
        bool key_pressed = false;
        set_pin_output(row_pins[row]);
        matrix_output_select_delay();
        for (uint8_t col = 0; col < PINNUM_COL; col++) {
            if (!get_pin(col_pins[col])) {
                out_matrix[row] |= (matrix_row_t)1 << col;
                key_pressed = true;
            }
        }
        set_pin_input(row_pins[row]);
        matrix_output_unselect_delay(row, key_pressed);
    }

    // Release all lines and wait before reversing drive direction
    set_pins_input(row_pins, PINNUM_ROW);
    set_pins_input(col_pins, PINNUM_COL);
    wait_us(DUPLEX_MATRIX_SETTLE_US);

    // Phase B: drive cols, read rows (matrix bits 4-7)
    for (uint8_t col = 0; col < PINNUM_COL; col++) {
        bool         key_pressed = false;
        set_pin_output(col_pins[col]);
        matrix_output_select_delay();
        matrix_row_t shifter = ((matrix_row_t)1) << (col + PINNUM_COL);
        for (uint8_t row = 0; row < PINNUM_ROW; row++) {
            if (!get_pin(row_pins[row])) {
                out_matrix[row] |= shifter;
                key_pressed = true;
            }
        }
        set_pin_input(col_pins[col]);
        matrix_output_unselect_delay(col, key_pressed);
    }

#if DUPLEX_MATRIX_OPPOSITE_INHIBIT_MS > 0
    duplex_filter_opposite_inhibit(out_matrix);
#endif
    duplex_scan_raw_post_kb(out_matrix);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool         changed = false;
    matrix_row_t tmp[MATRIX_ROWS] = {0};

    duplex_scan_raw(tmp);
    for (uint8_t row = 0; row < PINNUM_ROW; row++) {
        if (tmp[row] != current_matrix[row]) {
            changed = true;
            current_matrix[row] = tmp[row];
        }
    }
    return changed;
}

void matrix_init_custom(void) {
    set_pins_input(col_pins, PINNUM_COL);
    set_pins_input(row_pins, PINNUM_ROW);
}
