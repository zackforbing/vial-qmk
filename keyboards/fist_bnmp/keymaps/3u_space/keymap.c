/* Copyright 2021 qpockets
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
	_NUM
};

enum combo_events {
 COMBO_BSC,
 COMBO_ENT,
 COMBO_TAB,
 COMBO_ESC,
 COMBO_DEL
};

#define KC_FNSPC LT(_NUM, KC_SPC)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_3u_space(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y, KC_U,    KC_I,    KC_O,
		KC_A,    KC_S,    KC_D,    KC_SF,   KC_G,     KC_H, KC_SJ,   KC_K,    KC_L,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N, KC_M,    KC_COMM, KC_DOT,
		KC_LALT, KC_LGUI, KC_LCTL,      KC_FNSPC,   KC_RALT, KC_RGUI, KC_RCTL
    ),
	    [_NUM] = LAYOUT_3u_space(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y, KC_U,    KC_I,    KC_O,
		KC_A,    KC_S,    KC_D,    KC_SF,   KC_G,     KC_H, KC_SJ,   KC_K,    KC_L,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N, KC_M,    KC_COMM, KC_DOT,
		KC_LALT, KC_LGUI, KC_LCTL,      KC_FNSPC,   KC_RALT, KC_RGUI, KC_RCTL
    )
	
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bsc[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_X, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSC] = COMBO(combo_bsc,KC_BSPC),
  [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL)
};
#endif