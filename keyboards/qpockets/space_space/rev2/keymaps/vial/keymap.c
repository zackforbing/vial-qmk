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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [3] =   { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    //                  Encoder 1                                     Encoder 2
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_default(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_DEL,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,
    KC_A,   KC_S,   KC_D,  KC_F,   KC_G,   KC_TAB,  KC_H,   KC_J,  KC_K,    KC_L,   KC_QUOT,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_LSFT,  KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,
                  KC_LGUI, KC_LCTL, KC_SPC,    KC_BSPC, KC_RALT,   KC_MPLY
  ),

 [1] = LAYOUT_default(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS,
    KC_PIPE, KC_BSLS, KC_LPRN, KC_LBRC, KC_SCLN, KC_TRNS, KC_COLN, KC_RBRC, KC_RPRN, KC_PLUS,  KC_UNDS,
                    KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_TRNS,      KC_TRNS,    KC_TRNS
  ),

  [2] = LAYOUT_default(
    KC_TRNS, KC_HOME, KC_UP,   KC_END,   KC_PGUP,  QK_BOOT,   KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_BSPC,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,  KC_TRNS, KC_F4, KC_F5,  KC_F6,  KC_F7,  KC_TAB,
    KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT,  KC_TRNS,  KC_LCAP, KC_F9, KC_F10, KC_F11, KC_F12, KC_ENT,
                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
  ),

    [3] = LAYOUT_default(
    KC_TRNS, KC_HOME, KC_UP,   KC_END,   KC_PGUP,  QK_BOOT,   KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_BSPC,
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,  KC_TRNS, KC_F4, KC_F5,  KC_F6,  KC_F7,  KC_TAB,
    KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT,  KC_TRNS,  KC_LCAP, KC_F9, KC_F10, KC_F11, KC_F12, KC_ENT,
                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
  )
};
