# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

ENCODER_ENABLE = yes		# Enable encoder
BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite
MOUSEKEY_ENABLE =yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no       # Enable keyboard RGB underglow
# WS2812_DRIVER = vendor
# RGB_MATRIX_ENABLE = yes
# RGB_MATRIX_DRIVER = WS2812
AUDIO_ENABLE = no           # Audio output
LTO_ENABLE = no

# Duplex matrix.
# CUSTOM_MATRIX = lite
# SRC += lib/duplexmatrix/duplexmatrix.c

# Sprit keybord. Use
#SPLIT_KEYBOARD = yes
#SERIAL_DRIVER = vendor

#  Trackball.
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3389

SERIAL_DRIVER = vendor
# BOARD = GENERIC_RP_RP2040
SPI_DRIVER_REQUIRED = yes
USE_DEVICE_pmw3389 = yes