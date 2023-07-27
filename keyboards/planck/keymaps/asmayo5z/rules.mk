ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
SPLIT_KEYBOARD = no
ENCODER_ENABLE = no
RGB_MATRIX_ENABLE = no
TRI_LAYER_ENABLE = no
COMBO_ENABLE = yes

LTO_ENABLE = yes
