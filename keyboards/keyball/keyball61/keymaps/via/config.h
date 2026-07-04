/*
This is the c configuration file for the keymap

Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)
*/

#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_STATIC_LIGHT
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_SLEEP
#endif

#define TAP_CODE_DELAY 5

// Scroll tuning (distance-based, no time throttle):
//   SPEED      - motion units per wheel tick
//   MAX_TICK   - max ticks emitted per USB report
//   INPUT_MAX  - motion credited when delta >= LIGHT_MAX (fast-path cap only)
//   LIGHT_MAX  - below this, LIGHT_GAIN adds a bonus that shrinks as delta grows
//   LIGHT_GAIN - only affects slow moves; fast path is always exactly INPUT_MAX
#define KEYBALL_SCROLL_LAYER_SPEED 128
#define KEYBALL_SCROLL_MAX_TICK    1
#define KEYBALL_SCROLL_INPUT_MAX   2
#define KEYBALL_SCROLL_LIGHT_MAX   5
#define KEYBALL_SCROLL_LIGHT_GAIN  10

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 3
#define AUTO_MOUSE_TIME 2000

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#undef DYNAMIC_KEYMAP_MACRO_COUNT
#define DYNAMIC_KEYMAP_MACRO_COUNT 32

#define VIAL_KEYBOARD_UID {0x8F, 0x6B, 0x21, 0xCB, 0xA9, 0x6C, 0x92, 0x91}
#define VIAL_UNLOCK_COMBO_ROWS {0, 0}
#define VIAL_UNLOCK_COMBO_COLS {0, 1}

#define VIAL_COMBO_ENTRIES 16
#define VIAL_TAP_DANCE_ENTRIES 16
#define VIAL_KEY_OVERRIDE_ENTRIES 16
#define VIAL_ALT_REPEAT_KEY_ENTRIES 32
