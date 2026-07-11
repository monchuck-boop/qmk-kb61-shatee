/*
Copyright 2021 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

RP2040 native config (holykeebs keyball61 compatible)
*/

#pragma once

// Key matrix (duplex)
#define MATRIX_ROWS (5 * 2)
#define MATRIX_COLS (4 * 2)
#define MATRIX_ROW_PINS { GP4, GP5, GP6, GP7, GP8 }
#define MATRIX_COL_PINS { GP29, GP28, GP27, GP26 }
#define MATRIX_MASKED
#define DEBOUNCE 10

#define DUPLEX_MATRIX_SETTLE_US 250
#define DUPLEX_MATRIX_OPPOSITE_INHIBIT_MS 20

// Split (holykeebs keyball61/config.h)
#define SERIAL_USART_TX_PIN GP1
#define SPLIT_HAND_MATRIX_GRID GP26, GP6
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT

#undef SPLIT_TRANSACTION_IDS_KB
#define SPLIT_TRANSACTION_IDS_KB KEYBALL_GET_INFO

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LED_COUNT 74
#    define RGBLED_SPLIT { 37, 37 }
#    ifndef RGBLIGHT_LIMIT_VAL
#        define RGBLIGHT_LIMIT_VAL 120
#    endif
#    ifndef RGBLIGHT_VAL_STEP
#        define RGBLIGHT_VAL_STEP 12
#    endif
#    ifndef RGBLIGHT_HUE_STEP
#        define RGBLIGHT_HUE_STEP 17
#    endif
#    ifndef RGBLIGHT_SAT_STEP
#        define RGBLIGHT_SAT_STEP 17
#    endif
#endif

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_SPLIT { 37, 37 }
#endif
