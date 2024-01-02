# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

#SHARED_EP_ENABLE = yes
#KEYBOARD_SHARED_EP = yes
# Build Options
#   change yes to no to disable
#

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

# ENCODER
ENCODER_ENABLE = yes

# OLED
OLED_ENABLE = no
OLED_DRIVER = SSD1306

# trackpoint
PS2_MOUSE_ENABLE = no
PS2_ENABLE = no
PS2_DRIVER = usart
