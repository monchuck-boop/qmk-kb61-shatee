# MCU specifications
# (rp2040用のサブディレクトリ構成を読み込ませるための元々の設定を維持)
include $(DIRECTORY_PATH)/rp2040/rules.mk

# Features
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = yes
NKRO_ENABLE = yes
LTO_ENABLE = yes

# Split keyboard settings
SPLIT_KEYBOARD = yes

# Pointing Device (光学センサーの切り替え)
POINTING_DEVICE_ENABLE = yes
PMW3360_ENABLE = no
PMW3610_ENABLE = yes
V_BIT_REDUCTION_ENABLE = yes

