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

#include "pointing_device_auto_mouse.h"
#include "quantum.h"

// clang-format off
// Layers 0-2: keyball61_20260703.vil
// Layer 3: Auto Mouse (trackball movement, H/J/K/L/; = mouse buttons)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_BSPC  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_MINS  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_LNG2  ,              KC_LNG1  , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
    _______  , KC_LCTL  , KC_LALT  , KC_LALT  , KC_LGUI  , LT(1,KC_LNG2), KC_SPC ,            KC_ENT   , LT(2,KC_LNG1), KC_NO , KC_NO    , KC_NO    , KC_NO    , KC_NO
  ),

  [1] = LAYOUT_universal(
    S(KC_ESC), KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_EQL   , S(KC_6)  , S(KC_RBRC), S(KC_NUHS), S(KC_9)  , S(KC_INT1),
    S(KC_DEL), KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)  , KC_LBRC  ,
    S(KC_TAB), KC_F11   , KC_F12   , _______  , _______  , _______  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  , KC_QUOT  , S(KC_2)  ,
    _______  , _______  , _______  , _______  , _______  , _______  , S(KC_RBRC),           S(KC_NUHS), S(KC_N)  , S(KC_M)  , KC_RBRC  , KC_NUHS  , S(KC_SLSH), A(KC_INT3),
    _______  , S(KC_LCTL), S(KC_LALT), S(KC_LGUI), _______, _______  , _______  ,            _______  , _______  , KC_NO    , KC_NO    , KC_NO    , S(KC_RALT), _______
  ),

  [2] = LAYOUT_universal(
    SSNP_FRE , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    SSNP_VRT , KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,                                  KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , KC_F12   ,
    SSNP_HOR , KC_F11   , KC_F12   , KC_5     , KC_6     , S(KC_SCLN),                                 KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_BTN3  , _______  ,
    _______  , _______  , KC_1     , KC_2     , KC_3     , S(KC_MINS), S(KC_8)  ,            S(KC_9)  , KC_PGDN  , _______  , _______  , _______  , _______  , KC_INT3  ,
    _______  , _______  , KC_0     , KC_DOT   , _______  , _______  , _______  ,            KC_DEL   , _______  , KC_NO    , KC_NO    , KC_NO    , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  KC_BTN4  , KC_BTN1  , KC_BTN3  , KC_BTN2  , KC_BTN5  , _______  ,
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

// Right-hand home row physical positions: H J K L ;
static bool is_mouse_nav_key(keypos_t key) {
    if (key.row != 7) {
        return false;
    }
    switch (key.col) {
        case 1: // ;
        case 2: // L
        case 4: // K
        case 5: // J
        case 6: // H
            return true;
        default:
            return false;
    }
}

// Right-hand , (comma): hold = scroll, tap = ","
// Works before mouse mode (no need to enter layer 3 first)
static bool is_scroll_mod_key(keypos_t key) {
    return key.row == 8 && key.col == 4;
}

static bool     scroll_mod_held  = false;
static uint16_t scroll_mod_timer = 0;
static int16_t  scroll_speed_h   = 0;
static int16_t  scroll_speed_v   = 0;

// LT1 / LT2 / , 長押し中は Auto Mouse を解除し、離すまで再発動しない
static uint8_t am_suppress_count = 0;

static void am_suppress_on(void) {
    if (am_suppress_count == 0) {
        set_auto_mouse_enable(false);
    }
    am_suppress_count++;
    if (layer_state_is(3)) {
        layer_off(3);
    }
}

static void am_suppress_off(void) {
    if (am_suppress_count == 0) {
        return;
    }
    am_suppress_count--;
    if (am_suppress_count == 0) {
        set_auto_mouse_enable(true);
    }
}

static void update_scroll_mode(layer_state_t state) {
    // LT1 または , 押しっぱなしでスクロール（マウスレイヤー不要）
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

bool is_mouse_record_user(uint16_t keycode, keyrecord_t *record) {
    // Auto Mouse 中だけ H/J/K/L/; をマウスキー扱い（通常入力時は文字として送る）
    // , は process_record_user でスクロール修飾として処理（マウスレイヤー不要）
    if (is_auto_mouse_active() && is_mouse_nav_key(record->event.key)) {
        return true;
    }
    if (IS_MOUSEKEY(keycode)) {
        return true;
    }
    switch (keycode) {
        case KC_MS_BTN1 ... KC_MS_BTN8:
        case KC_WH_U ... KC_WH_R:
            return true;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // , : 押しっぱなしでスクロール、タップで ","
    if (is_scroll_mod_key(record->event.key)) {
        if (record->event.pressed) {
            scroll_mod_held  = true;
            scroll_mod_timer = timer_read();
            am_suppress_on();
            update_scroll_mode(layer_state);
        } else {
            bool was_tap = timer_elapsed(scroll_mod_timer) < TAPPING_TERM;
            scroll_mod_held = false;
            am_suppress_off();
            update_scroll_mode(layer_state);
            if (was_tap) {
                tap_code(KC_COMM);
            }
        }
        return false;
    }

    if (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) {
        uint8_t layer = QK_LAYER_TAP_GET_LAYER(keycode);
        if ((layer == 1 || layer == 2) && record->tap.count == 0) {
            if (record->event.pressed) {
                am_suppress_on();
            } else {
                am_suppress_off();
            }
        }
    }
    return true;
}

void keyboard_post_init_user(void) {
    set_auto_mouse_enable(true);
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

// Scroll output is slowed by KEYBALL_SCROLL_LAYER_SPEED
static int8_t clip2int8(int16_t v) {
    return (v) < -127 ? -127 : (v) > 127 ? 127 : (int8_t)v;
}

void keyball_on_apply_motion_to_mouse_scroll(report_mouse_t *report, report_mouse_t *output, bool is_left) {
    int16_t x = report->x;
    int16_t y = report->y;
    report->x = 0;
    report->y = 0;

    scroll_speed_h += x;
    scroll_speed_v += y;

    x = scroll_speed_h / KEYBALL_SCROLL_LAYER_SPEED;
    y = scroll_speed_v / KEYBALL_SCROLL_LAYER_SPEED;
    scroll_speed_h -= x * KEYBALL_SCROLL_LAYER_SPEED;
    scroll_speed_v -= y * KEYBALL_SCROLL_LAYER_SPEED;

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
    // LT1 / LT2 中はマウスレイヤーを解除する
    if (layer_state_cmp(state, 1) || layer_state_cmp(state, 2)) {
        state = remove_auto_mouse_layer(state, true);
    }

    // スクロール: LT1、またはマウスレイヤー中の , 押しっぱなし
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
