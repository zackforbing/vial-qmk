POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = custom
SRC += iqs5xx.c i2c_master.c
HAPTIC_ENABLE = yes
HAPTIC_DRIVER += DRV2605L
DYNAMIC_TAPPING_TERM_ENABLE = yes
NO_USB_STARTUP_CHECK = yes
//WS2812_DRIVER = vendor
