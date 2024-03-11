/*
Copyright 2022 Joe Scotto

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H


enum combo_events {
  COMBO_DEL,
  COMBO_ESC,
 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q,         KC_W, KC_E,    KC_R,    KC_T,                                           KC_Y,          KC_U,          KC_I,     KC_O,   KC_P,
        KC_A,         KC_S, KC_D,    KC_F,    KC_G,                                           KC_H,          KC_J,          KC_K,     KC_L,   KC_SCLN,
        LSFT_T(KC_Z), KC_X, KC_C,    KC_V,    KC_B,                                           KC_N,          KC_M,          KC_COMMA, KC_DOT, RSFT_T(KC_SLSH),
                            KC_LCTL, KC_LGUI, LT(1,KC_BSPC),                                  LT(2,KC_SPC),   (KC_ENT),      KC_LALT
    ),
    [1] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
        KC_TAB,  _______, _______, _______, _______,                         KC_MINS,  KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
        _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,                         KC_TILD,  KC_GRV,  _______, _______, KC_BSLS,
                          _______, _______, _______,                         _______,  _______, _______
    ),
    [2] = LAYOUT(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        _______,  _______,    _______,    _______,   _______,                _______,  _______,  _______,   _______, _______,
        _______,  _______,    _______,    _______,   _______,               _______,  _______, _______, _______, _______,
                          _______, _______, _______,                         _______,  _______, _______
    ),
    [3] = LAYOUT(
        _______, KC_UP, _______, _______, _______,                         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_PSCR,
        KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,
        _______, _______, _______, _______, _______,                       KC_F10,  KC_F11,  KC_F12,  _______, _______,
                          _______, _______, _______,                       _______, _______, _______
    ),
    [4] = LAYOUT(
        _______, _______, _______, _______, _______,                         _______,   _______,   _______,   _______,   _______,
        _______, _______, _______, _______, _______,                      _______,   _______,   _______,   _______,   _______,
        _______, _______, _______, _______, _______,                       _______,  _______,  _______,  _______, _______,
                          _______, _______, _______,                       _______, _______, _______
    ),
    [5] = LAYOUT(
        _______, _______, _______, _______, _______,                         _______,   _______,   _______,   _______,   _______,
        _______, _______, _______, _______, _______,                      _______,   _______,   _______,   _______,   _______,
        _______, _______, _______, _______, _______,                       _______,  _______,  _______,  _______, _______,
                          _______, _______, _______,                       _______, _______, _______
    ),
    [6] = LAYOUT(
        _______, _______, _______, _______, _______,                         _______,   _______,   _______,   _______,   _______,
        _______, _______, _______, _______, _______,                      _______,   _______,   _______,   _______,   _______,
        _______, _______, _______, _______, _______,                       _______,  _______,  _______,  _______, _______,
                          _______, _______, _______,                       _______, _______, _______
    ),
    [7] = LAYOUT(
        _______, _______, _______, _______, _______,                         _______,   _______,   _______,   _______,   _______,
        _______, _______, _______, _______, _______,                      _______,   _______,   _______,   _______,   _______,
        _______, _______, _______, _______, _______,                       _______,  _______,  _______,  _______, _______,
                          _______, _______, _______,                       _______, _______, _______
    )
};
