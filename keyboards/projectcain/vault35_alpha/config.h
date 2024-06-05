#pragma once

#define MATRIX_ROWS 4
#define MATRIX_COLS 11

#define MATRIX_ROW_PINS { F1, B3, F5, F4 }
#define MATRIX_COL_PINS { F0, B0, C7, C6, B6, D3, B5, B4, D7, D6, D4 }

#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// OLED
//#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
//#define OLED_TIMEOUT 300000

// ENCODER
#define ENCODERS_PAD_A { B2 }
#define ENCODERS_PAD_B { B1 }
#define ENCODER_RESOLUTION 4


// combo
#define COMBO_TERM 50
