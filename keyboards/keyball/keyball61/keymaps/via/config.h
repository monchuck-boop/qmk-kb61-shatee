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

// Ignore re-press of the same physical key within this window (ms).
// First press stays immediate; blocks ghost→real doubles like O→U → "ouu".
#define KEYBALL_SAME_KEY_MIN_INTERVAL 100

// Scroll tuning (linear, proportional to ball displacement):
//   SPEED    - motion units per wheel tick (higher = slower scroll)
//   MAX_TICK - max ticks per USB report (0 = unlimited; burst on fast flicks)
#define KEYBALL_SCROLL_LAYER_SPEED 24
#define KEYBALL_SCROLL_MAX_TICK    8

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
