/*
Copyright 2022 @Yowkees
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

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
// Layers 0-2: keyball61_20260704.vil
// Layer 3: Mouse (hold MO(3) on bottom-right thumb)
//   H/J = BTN4/1, I/O/P = BTN3/2/5, K = scroll while held
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_BSPC  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_MINS  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_LNG2  ,            KC_LNG1  , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
    _______  , KC_LCTL  , KC_LALT  , KC_LALT  , KC_LGUI  , LT(1,KC_LNG2), KC_SPC   ,        KC_ENT   , LT(2,KC_LNG1), KC_NO    , KC_NO    , KC_NO    , KC_NO    , MO(3)
  ),

  [1] = LAYOUT_universal(
    S(KC_ESC), KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  _______  , _______  , S(KC_RBRC), S(KC_NUHS), S(KC_9)  , KC_DEL   ,
    S(KC_DEL), KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,                                  _______  , _______  , _______  , _______  , _______  , KC_LBRC  ,
    S(KC_TAB), KC_F11   , KC_F12   , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , KC_QUOT  , S(KC_2)  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , KC_RBRC  , KC_NUHS  , S(KC_SLSH), A(KC_INT3),
    _______  , S(KC_LCTL), S(KC_LALT), S(KC_LGUI), _______, _______  , _______  ,            _______  , _______  , KC_NO    , KC_NO    , KC_NO    , _______  , _______
  ),

  [2] = LAYOUT_universal(
    SSNP_FRE , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    SSNP_VRT , KC_F6    , KC_F7    , KC_F8    , KC_EQL   , S(KC_EQL),                                  KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    SSNP_HOR , KC_F11   , KC_F12   , _______  , _______  , S(KC_SCLN),                                 KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , S(KC_MINS), _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , KC_NO    , KC_NO    , KC_NO    , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , KC_BTN3  , KC_BTN2  , KC_BTN5  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  KC_BTN4  , KC_BTN1  , SCRL_MO  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , KC_NO    , KC_NO    , KC_NO    , _______  , _______
  ),

  [4] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , KC_NO    , KC_NO    , KC_NO    , _______  , _______
  ),

  [5] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , KC_NO    , KC_NO    , KC_NO    , _______  , _______
  ),

  [6] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , KC_NO    , KC_NO    , KC_NO    , _______  , _______
  ),

  [7] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , KC_NO    , KC_NO    , KC_NO    , _______  , _______
  ),
};
// clang-format on

static int16_t scroll_speed_h = 0;
static int16_t scroll_speed_v = 0;
static bool    scroll_mod_held = false;

static void update_scroll_mode(layer_state_t state) {
    // LT1 押しっぱなし、または Layer3 の K (SCRL_MO) 押しっぱなしでスクロール
    bool want_scroll = layer_state_cmp(state, 1) || scroll_mod_held;
    if (want_scroll) {
        keyball_set_scroll_mode(true);
    } else {
        if (keyball_get_scroll_mode()) {
            scroll_speed_h = 0;
            scroll_speed_v = 0;
        }
        keyball_set_scroll_mode(false);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Same-key refractory: first press is immediate; a second press of the
    // same matrix position within KEYBALL_SAME_KEY_MIN_INTERVAL is dropped.
    // Catches duplex ghosts (O→U → ouu) without delaying the initial key.
    if (record->event.pressed) {
        static uint16_t last_press_time[MATRIX_ROWS][MATRIX_COLS];
        uint8_t row = record->event.key.row;
        uint8_t col = record->event.key.col;
        if (row < MATRIX_ROWS && col < MATRIX_COLS) {
            uint16_t last = last_press_time[row][col];
            if (last != 0 && timer_elapsed(last) < KEYBALL_SAME_KEY_MIN_INTERVAL) {
                return false;
            }
            last_press_time[row][col] = timer_read();
        }
    }

    switch (keycode) {
        case SCRL_MO:
            scroll_mod_held = record->event.pressed;
            update_scroll_mode(layer_state);
            break;
    }
    return true;
}

void keyboard_post_init_user(void) {
    keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_FREE);
#ifdef RGBLIGHT_ENABLE
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
    rgblight_sethsv_noeeprom(0, 255, 255);
#endif
}

#ifdef RGBLIGHT_ENABLE
static void layer_rgb_update(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 3:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_CYAN);
            break;
        case 2:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_BLUE);
            break;
        case 1:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            rgblight_sethsv_noeeprom(HSV_RED);
            break;
        default:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
            rgblight_sethsv_noeeprom(0, 255, rgblight_get_val());
            break;
    }
}
#endif

// Scroll: linear proportion to ball displacement (like cursor movement).
// Wheel HID is discrete, but motion→ticks mapping stays linear so speed
// feels consistent; accumulator keeps sub-tick precision across reports.
static int8_t clip2int8(int16_t v) {
    return (v) < -127 ? -127 : (v) > 127 ? 127 : (int8_t)v;
}

static int16_t scroll_consume_axis(int16_t *acc, int16_t delta) {
    if (delta == 0) {
        return 0;
    }

    *acc += delta;

    int16_t ticks = *acc / KEYBALL_SCROLL_LAYER_SPEED;
    *acc -= ticks * KEYBALL_SCROLL_LAYER_SPEED;

#if KEYBALL_SCROLL_MAX_TICK > 0
    if (ticks > KEYBALL_SCROLL_MAX_TICK) {
        *acc += (ticks - KEYBALL_SCROLL_MAX_TICK) * KEYBALL_SCROLL_LAYER_SPEED;
        ticks = KEYBALL_SCROLL_MAX_TICK;
    } else if (ticks < -KEYBALL_SCROLL_MAX_TICK) {
        *acc += (ticks + KEYBALL_SCROLL_MAX_TICK) * KEYBALL_SCROLL_LAYER_SPEED;
        ticks = -KEYBALL_SCROLL_MAX_TICK;
    }
#endif
    return ticks;
}

void keyball_on_apply_motion_to_mouse_scroll(report_mouse_t *report, report_mouse_t *output, bool is_left) {
    int16_t x = scroll_consume_axis(&scroll_speed_h, report->x);
    int16_t y = scroll_consume_axis(&scroll_speed_v, report->y);
    report->x = 0;
    report->y = 0;

#if KEYBALL_MODEL == 61 || KEYBALL_MODEL == 39 || KEYBALL_MODEL == 147 || KEYBALL_MODEL == 44
    output->h = clip2int8(-x);
    output->v = clip2int8(y);
    if (is_left) {
        output->h = -output->h;
        output->v = -output->v;
    }
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // スクロール: LT1 / SCRL_MO 押しっぱなし
    update_scroll_mode(state);
#ifdef RGBLIGHT_ENABLE
    layer_rgb_update(state);
#endif
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
