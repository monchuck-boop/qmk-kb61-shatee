/*
Copyright 2021 @Yowkees
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

#pragma once

// Key matrix parameters (Keyball61 is duplex matrix)
#define MATRIX_ROWS         (5 * 2)  // split keyboard
#define MATRIX_COLS         (4 * 2)  // duplex matrix
#define MATRIX_ROW_PINS     { GP4, GP5, GP6, GP7, GP8 }
#define MATRIX_COL_PINS     { GP29, GP28, GP27, GP26 }
#define MATRIX_MASKED
#define DEBOUNCE            10

// Duplex crosstalk: O/U/I are on opposite scan phases (cols 0-3 vs 4-7).
// Inhibit only after a stable (2+ scan) release — 1-scan ghosts must not arm it.
// Same-key min-interval merges press-edge ghost+real doubles; first press is eager.
#define DUPLEX_MATRIX_SETTLE_US            250
#define DUPLEX_MATRIX_OPPOSITE_INHIBIT_MS   20

// Split parameters
#define SERIAL_USART_TX_PIN GP1
#define SPLIT_HAND_MATRIX_GRID  GP26, GP6
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT
// #define SPLIT_USB_DETECT
// #define SPLIT_USB_TIMEOUT       500


#define SPLIT_TRANSACTION_IDS_KB KEYBALL_GET_INFO

// RGB LED settings
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LED_COUNT      74
#    define RGBLED_SPLIT    { 37, 37 }
#    ifndef RGBLIGHT_LIMIT_VAL
#        define RGBLIGHT_LIMIT_VAL  120 // limitated for power consumption
#    endif
#    ifndef RGBLIGHT_VAL_STEP
#        define RGBLIGHT_VAL_STEP   12
#    endif
#    ifndef RGBLIGHT_HUE_STEP
#        define RGBLIGHT_HUE_STEP   17
#    endif
#    ifndef RGBLIGHT_SAT_STEP
#        define RGBLIGHT_SAT_STEP   17
#    endif
#endif
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_SPLIT    { 37, 37 }
#endif
#define MASTER_RIGHT

#ifdef OLED_ENABLE
#    define SPLIT_OLED_ENABLE
#endif

#define SPLIT_HAND_PIN GP22 
#define PMW3610_DPI 1600
#define MASTER_RIGHT
#pragma once

// 1. PMW3610用の設定（GP11をセンサー通信から外す）
#undef PMW3360_CS_PIN
#define PMW3610_CS_PIN GP12
#define PMW3610_SPI_SCLK GP10
#define PMW3610_SPI_MOSI GP11 // 1線式にするため、MOSIとMISOを同じGP11にする方法もありますが、
#define PMW3610_SPI_MISO GP11 // もしGP11をCOL3に使うなら、センサーはGP10等で1線通信させる必要があります。

#pragma once

// 既存のPMW3360ピン定義をすべてクリア（無効化）
#undef PMW3360_CS_PIN
#undef PMW3360_SPI_SCLK
#undef PMW3360_SPI_MOSI
#undef PMW3360_SPI_MISO

// === PMW3610 1線通信（SDIO）用のピンアサイン ===
#define PMW3610_CS_PIN    GP12  // チップセレクト
#define PMW3610_SPI_SCLK  GP10  // クロック
#define PMW3610_SPI_MOSI  GP10  // データ線（SDIO）をGP10に割り当て
#define PMW3610_SPI_MISO  GP10  // MISOも同じGP10を指定することでQMK側が1線モードで動作

// 必要に応じて初期DPIを設定
#define PMW3610_DPI 1600

