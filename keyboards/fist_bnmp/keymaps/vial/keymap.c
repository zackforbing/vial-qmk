#include QMK_KEYBOARD_H

#define KC_FNSPC LT(1, KC_SPC)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_default(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y, KC_U,    KC_I,    KC_O,
		KC_A,    KC_S,    KC_D,    KC_SF,   KC_G,     KC_H, KC_SJ,   KC_K,    KC_L,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N, KC_M,    KC_P, KC_DOT,
		KC_LALT, KC_LGUI, KC_LCTL, KC_BSPC, KC_FNSPC, KC_FNSPC, KC_RALT, KC_RGUI, KC_RCTL
    ),

[1] = LAYOUT_default(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y, KC_U,    KC_I,    KC_O,
		KC_A,    KC_S,    KC_D,    KC_SF,   KC_G,     KC_H, KC_SJ,   KC_K,    KC_L,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N, KC_M,    KC_P, KC_DOT,
		KC_LALT, KC_LGUI, KC_LCTL, KC_BSPC, KC_FNSPC, KC_FNSPC, KC_RALT, KC_RGUI, KC_RCTL
    ),

[2] = LAYOUT_default(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y, KC_U,    KC_I,    KC_O,
		KC_A,    KC_S,    KC_D,    KC_SF,   KC_G,     KC_H, KC_SJ,   KC_K,    KC_L,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N, KC_M,    KC_P, KC_DOT,
		KC_LALT, KC_LGUI, KC_LCTL, KC_BSPC, KC_FNSPC, KC_FNSPC, KC_RALT, KC_RGUI, KC_RCTL
    ),

[3] = LAYOUT_default(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y, KC_U,    KC_I,    KC_O,
		KC_A,    KC_S,    KC_D,    KC_SF,   KC_G,     KC_H, KC_SJ,   KC_K,    KC_L,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N, KC_M,    KC_P, KC_DOT,
		KC_LALT, KC_LGUI, KC_LCTL, KC_BSPC, KC_FNSPC, KC_FNSPC, KC_RALT, KC_RGUI, KC_RCTL
    )

};
