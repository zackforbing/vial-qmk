 /* Copyright 2021 Caleb Lightfoot
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT(
  	  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
  	  LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_QUOTE),
  	  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH,
  	  TD(0), KC_MPLY, KC_TRNS, LT(1, KC_SPACE), KC_TRNS, KC_SPACE, LT(2, KC_BACKSPACE), KC_TRNS, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT))
    ),

     [1] = LAYOUT(
  	  KC_1, KC_2, KC_3, KC_4, KC_5, LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINUS), LSFT(KC_EQUAL), LSFT(KC_GRAVE),
  	  LGUI_T(KC_6), LALT_T(KC_7), LCTL_T(KC_8), LSFT_T(KC_9), KC_0, KC_LEFT_BRACKET, RSFT_T(KC_RIGHT_BRACKET), RCTL_T(KC_MINUS), RALT_T(KC_EQUAL), RGUI_T(KC_GRAVE),
  	  KC_KP_DOT, KC_KP_PLUS, KC_KP_MINUS, KC_KP_ASTERISK, KC_KP_SLASH, LSFT(KC_LEFT_BRACKET), LSFT(KC_RIGHT_BRACKET), KC_SEMICOLON, LSFT(KC_SEMICOLON), KC_BACKSLASH,
  	  KC_TRNS, KC_SPACE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENTER, KC_TRNS, KC_TRNS, KC_TRNS
    ),

      [2] = LAYOUT(
  	  LSFT_T(KC_PGUP), LALT_T(KC_HOME), KC_UP, LALT_T(KC_END), MEH(KC_BACKSLASH), KC_NO, KC_F9, KC_F10, KC_F11, KC_F12,
  	  TD(1), KC_LEFT, KC_DOWN, KC_RIGHT, KC_BACKSPACE, KC_DELETE, LSFT_T(KC_F5), RCTL_T(KC_F6), RALT_T(KC_F7), RGUI_T(KC_F8),
  	  LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_ENTER, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4,
  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

      [3] = LAYOUT(
  	  KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
  	  KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_REBOOT
    ),

};
