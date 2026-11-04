name: Force Fix Keyball61 Right Thumb Only

on:
  workflow_dispatch: # 手動実行用

jobs:
  build:
    runs-on: ubuntu-latest
    container: ghcr.io/qmk/qmk_cli:latest

    steps:
      # 1. リポジトリのチェックアウト
      - name: Checkout repository
        uses: actions/checkout@v4
        with:
          submodules: recursive

      # 2. パーミッションエラー防止
      - name: Disable git safe directory checks
        run: git config --global --add safe.directory '*'

      # 3. Pythonスクリプトのバグ修正（ast.Numエラー対策）
      - name: Patch repository qmk math script
        run: |
          if [ -f "lib/python/qmk/math.py" ]; then
            sed -i 's/ast.Num/ast.Constant/g' lib/python/qmk/math.py
            sed -i 's/node.n/node.value/g' lib/python/qmk/math.py
          fi

      # 4. 【回路修正】回路の初期化は残し、トラックボールのエラー原因だけを消去
      - name: Force Rewrite for Pure Keyboard Matrix
        run: |
          CONFIG_FILE="keyboards/keyball/keyball61/config.h"
          RULES_FILE="keyboards/keyball/keyball61/rules.mk"
          KEYMAP_FILE="keyboards/keyball/keyball61/keymaps/default/keymap.c"
          KEYBALL_C="keyboards/keyball/lib/keyball/keyball.c"
          
          # A. config.h の設定（右手を主役にし、左手との通信を完全遮断）
          if [ -f "$CONFIG_FILE" ]; then
            echo "Configuring config.h..."
            echo "#define MASTER_RIGHT" >> "$CONFIG_FILE"
            echo "#define SPLIT_USB_DETECT" >> "$CONFIG_FILE"
            echo "#define FORWARD_EECONFIG" >> "$CONFIG_FILE"
          fi
          
          # B. rules.mk の設定（RP2040への切り替えと、エラーの原因をオフ）
          if [ -f "$RULES_FILE" ]; then
            echo "Configuring rules.mk..."
            sed -i 's/MCU =.*/MCU = RP2040/g' "$RULES_FILE"
            sed -i 's/BOOTLOADER =.*/BOOTLOADER = rp2040/g' "$RULES_FILE"
            
            sed -i 's/SPLIT_KEYBOARD_ENABLE =.*/SPLIT_KEYBOARD_ENABLE = no/g' "$RULES_FILE"
            sed -i 's/POINTING_DEVICE_ENABLE =.*/POINTING_DEVICE_ENABLE = no/g' "$RULES_FILE"
            sed -i 's/PMW3360_ENABLE =.*/PMW3360_ENABLE = no/g' "$RULES_FILE"
            sed -i 's/RGBLIGHT_ENABLE =.*/RGBLIGHT_ENABLE = no/g' "$RULES_FILE"
            sed -i 's/VIA_ENABLE =.*/VIA_ENABLE = no/g' "$RULES_FILE"
          fi
          
          # C. 【重要】keyball.c からトラックボールのエラーを吐く行（pmw33xxなど）だけをピンポイントで消去
          # キー回路の初期化（duplexmatrix_init）は絶対に消さずに残します
          if [ -f "$KEYBALL_C" ]; then
            echo "Removing pointing device codes from keyball.c but keeping matrix init..."
            sed -i '/pmw33xx/d' "$KEYBALL_C"
            sed -i '/pointing_device/d' "$KEYBALL_C"
            sed -i '/keyball_set_scroll_mode/d' "$KEYBALL_C"
          fi
          
          # D. keymap.c 内のトラックボール命令をコメントアウト
          if [ -f "$KEYMAP_FILE" ]; then
            echo "Patching keymap.c to remove keyball_set_scroll_mode..."
            sed -i 's/keyball_set_scroll_mode/\/\/ keyball_set_scroll_mode/g' "$KEYMAP_FILE"
          fi

      # 5. コンパイルの実行
      - name: Compile Keyball61
        run: qmk compile -kb keyball/keyball61 -km default

      # 6. 生成されたファームウェア (.uf2) を保存
      - name: Upload firmware artifact
        uses: actions/upload-artifact@v4
        with:
          name: keyball61-rp2040-thumb-only
          path: |
            *.uf2
            .build/*.uf2
          if-no-files-found: error
