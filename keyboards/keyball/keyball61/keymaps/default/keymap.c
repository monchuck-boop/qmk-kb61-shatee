name: Build Keyball61 Right Hand Only

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

      # 4. 右手単独環境の定義 ＆ 汚れている keyball61.c をビルド直前に100%強制リセット
      - name: Configure Right Hand Master Single Mode
        run: |
          CONFIG_FILE="keyboards/keyball/keyball61/config.h"
          RULES_FILE="keyboards/keyball/keyball61/rules.mk"
          TARGET_C="keyboards/keyball/keyball61/keyball61.c"
          
          # コンパイラが怒っていた keyball61.c のファイル汚れを完全に上書きリセットします
          echo "==== Force Overwriting and Resetting keyball61.c ===="
          echo '#include "keyball61.h"' > "$TARGET_C"
          
          if [ -f "$CONFIG_FILE" ]; then
            echo "#define MASTER_RIGHT" >> "$CONFIG_FILE"
            echo "#define SPLIT_USB_DETECT" >> "$CONFIG_FILE"
            echo "#define FORWARD_EECONFIG" >> "$CONFIG_FILE"
            echo "#define NO_TRACKBALL" >> "$CONFIG_FILE"
          fi
          
          if [ -f "$RULES_FILE" ]; then
            sed -i 's/MCU =.*/MCU = RP2040/g' "$RULES_FILE"
            sed -i 's/BOOTLOADER =.*/BOOTLOADER = rp2040/g' "$RULES_FILE"
            sed -i 's/SPLIT_KEYBOARD_ENABLE =.*/SPLIT_KEYBOARD_ENABLE = no/g' "$RULES_FILE"
            sed -i 's/POINTING_DEVICE_ENABLE =.*/POINTING_DEVICE_ENABLE = no/g' "$RULES_FILE"
            sed -i 's/PMW3360_ENABLE =.*/PMW3360_ENABLE = no/g' "$RULES_FILE"
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
