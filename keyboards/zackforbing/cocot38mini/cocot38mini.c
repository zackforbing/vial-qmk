/* Copyright 2020 Alexander Tulloh
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

#include "quantum.h"
#include <math.h>
#include "cocot38mini.h"
#include "wait.h"
#include "debug.h"
#include <stdio.h>
#include "pointing_device.h"
extern const pointing_device_driver_t pointing_device_driver;


// Invert vertical scroll direction
#ifndef COCOT_SCROLL_INV_DEFAULT
#    define COCOT_SCROLL_INV_DEFAULT true
#endif

#ifndef COCOT_CPI_OPTIONS
#    define COCOT_CPI_OPTIONS { 200, 400, 800, 1600, 3200 }
#    ifndef COCOT_CPI_DEFAULT
#       define COCOT_CPI_DEFAULT 3
#    endif
#endif
#ifndef COCOT_CPI_DEFAULT
#    define COCOT_CPI_DEFAULT 3
#endif

#ifndef COCOT_SCROLL_DIVIDERS
#    define COCOT_SCROLL_DIVIDERS { 1, 2, 3, 4, 5, 6 }
#    ifndef COCOT_SCROLL_DIV_DEFAULT
#       define COCOT_SCROLL_DIV_DEFAULT 4
#    endif
#endif
#ifndef COCOT_SCROLL_DIV_DEFAULT
#    define COCOT_SCROLL_DIV_DEFAULT 4
#endif


#ifndef COCOT_ROTATION_ANGLE
#    define COCOT_ROTATION_ANGLE { -75, -60, -45, -30, -15, 0, 15, 30, 45, 60, 75 }
#    ifndef COCOT_ROTATION_DEFAULT
#       define COCOT_ROTATION_DEFAULT 5
#    endif
#endif
#ifndef COCOT_ROTATION_DEFAULT
#    define COCOT_ROTATION_DEFAULT 3
#endif
#ifndef COCOT_AUTO_MOUSE_MODE
#    define COCOT_AUTO_MOUSE_MODE true
#endif





cocot_config_t cocot_config;
uint16_t cpi_array[] = COCOT_CPI_OPTIONS;
uint16_t scrl_div_array[] = COCOT_SCROLL_DIVIDERS;
uint16_t angle_array[] = COCOT_ROTATION_ANGLE;
#define CPI_OPTION_SIZE (sizeof(cpi_array) / sizeof(uint16_t))
#define SCRL_DIV_SIZE (sizeof(scrl_div_array) / sizeof(uint16_t))
#define ANGLE_SIZE (sizeof(angle_array) / sizeof(uint16_t))


// Scroll Accumulation
static int16_t h_acm       = 0;
static int16_t v_acm       = 0;


void pointing_device_init_kb(void) {
    // set the CPI.
    pointing_device_set_cpi(cpi_array[cocot_config.cpi_idx]);
    cocot_config.raw = eeconfig_read_kb();
    eeconfig_update_kb(cocot_config.raw);
    //set_auto_mouse_layer(4);
    set_auto_mouse_enable(cocot_config.auto_mouse);
}


report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {

    double rad = angle_array[cocot_config.rotation_angle] * (M_PI / 180) * -1;
    int8_t x_rev =  + mouse_report.x * cos(rad) - mouse_report.y * sin(rad);
    int8_t y_rev =  + mouse_report.x * sin(rad) + mouse_report.y * cos(rad);

    if (cocot_get_scroll_mode()) {
        // rock scroll direction
        if (abs(x_rev) > abs(y_rev)) {
            y_rev = 0;
        } else {
            x_rev = 0;
        }

        // accumulate scroll
        if (cocot_config.scrl_inv) {
            h_acm += x_rev * 1;
            v_acm += y_rev * -1;
        } else {
            h_acm += x_rev * -1;
            v_acm += y_rev * 1;
        }

        int8_t h_rev = h_acm >> scrl_div_array[cocot_config.scrl_div];
        int8_t v_rev = v_acm >> scrl_div_array[cocot_config.scrl_div];

        // clear accumulated scroll on assignment

        if (h_rev != 0) {
            if (mouse_report.h + h_rev > 127) {
                h_rev = 127 - mouse_report.h;
            } else if (mouse_report.h + h_rev < -127) {
                h_rev = -127 - mouse_report.h;
            }
            mouse_report.h += h_rev;
            h_acm -= h_rev << scrl_div_array[cocot_config.scrl_div];
        }
        if (v_rev != 0) {
            if (mouse_report.v + v_rev > 127) {
                v_rev = 127 - mouse_report.v;
            } else if (mouse_report.v + v_rev < -127) {
                v_rev = -127 - mouse_report.v;
            }
            mouse_report.v += v_rev;
            v_acm -= v_rev << scrl_div_array[cocot_config.scrl_div];
        }

        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        mouse_report.x = -x_rev;
        mouse_report.y = y_rev;
    }

    return pointing_device_task_user(mouse_report);
}



bool process_record_kb(uint16_t keycode, keyrecord_t* record) {
    // xprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);

    if (!process_record_user(keycode, record)) return false;

    switch (keycode) {
        #ifndef MOUSEKEY_ENABLE
                // process KC_MS_BTN1~8 by myself
                // See process_action() in quantum/action.c for details.
                case KC_MS_BTN1 ... KC_MS_BTN8: {
                    extern void register_button(bool, enum mouse_buttons);
                    register_button(record->event.pressed, MOUSE_BTN_MASK(keycode - KC_MS_BTN1));
                    return false;
                }
        #endif
        //*
        case AM_TOG:
            if(record->event.pressed) { // key down
                //auto_mouse_layer_off(); // disable target layer if needed
                cocot_config.auto_mouse ^= 1;
                eeconfig_update_kb(cocot_config.raw);
                set_auto_mouse_enable(cocot_config.auto_mouse);
                //auto_mouse_tg_off = !get_auto_mouse_enable();
            } // do nothing on key up
            return false; // prevent further processing of keycode
    //*/
    }

    if (keycode == CPI_SW && record->event.pressed) {
        cocot_config.cpi_idx = (cocot_config.cpi_idx + 1) % CPI_OPTION_SIZE;
        eeconfig_update_kb(cocot_config.raw);
        pointing_device_set_cpi(cpi_array[cocot_config.cpi_idx]);
    }

    if (keycode == SCRL_SW && record->event.pressed) {
        cocot_config.scrl_div = (cocot_config.scrl_div + 1) % SCRL_DIV_SIZE;
        eeconfig_update_kb(cocot_config.raw);
    }

    if (keycode == ROT_R15 && record->event.pressed) {
        cocot_config.rotation_angle = (cocot_config.rotation_angle + 1) % ANGLE_SIZE;
        eeconfig_update_kb(cocot_config.raw);
    }

    if (keycode == ROT_L15 && record->event.pressed) {
        cocot_config.rotation_angle = (ANGLE_SIZE + cocot_config.rotation_angle - 1) % ANGLE_SIZE;
        eeconfig_update_kb(cocot_config.raw);
    }

    if (keycode == SCRL_IN && record->event.pressed) {
        cocot_config.scrl_inv ^= 1;
        eeconfig_update_kb(cocot_config.raw);
    }

    if (keycode == SCRL_TO && record->event.pressed) {
        { cocot_config.scrl_mode ^= 1; }
    }

    if (keycode == SCRL_MO) {
        { cocot_config.scrl_mode ^= 1; }
    }

    return true;
}


layer_state_t layer_state_set_kb(layer_state_t state) {
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 1 ... 2:
            //rgblight_sethsv_range(HSV_YELLOW, 0, 9);
            cocot_set_scroll_mode(true);
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            break;
        case 3 ... 7:
            //rgblight_sethsv_range(HSV_CYAN, 0, 9);
            cocot_set_scroll_mode(false);
            //set_auto_mouse_enable(true);
            break;
        default:
            //rgblight_sethsv_range(HSV_RED, 0, 9);
            cocot_set_scroll_mode(false);

            if (cocot_config.auto_mouse) {
                set_auto_mouse_enable(true);
            } else {
                //state = remove_auto_mouse_layer(state, false);
                set_auto_mouse_enable(false);
            }

            //set_auto_mouse_enable(true);
            //state = remove_auto_mouse_layer(state, false);
            //set_auto_mouse_enable(cocot_config.auto_mouse);
            break;
        }
    //rgblight_set_effect_range( 9, 36);
  return state;
};



void eeconfig_init_kb(void) {
    cocot_config.cpi_idx = COCOT_CPI_DEFAULT;
    cocot_config.scrl_div = COCOT_SCROLL_DIV_DEFAULT;
    cocot_config.rotation_angle = COCOT_ROTATION_DEFAULT;
    cocot_config.scrl_inv = COCOT_SCROLL_INV_DEFAULT;
    cocot_config.scrl_mode = false;
    cocot_config.auto_mouse = COCOT_AUTO_MOUSE_MODE;
    eeconfig_update_kb(cocot_config.raw);
    eeconfig_init_user();
}


void matrix_init_kb(void) {
    // is safe to just read CPI setting since matrix init
    // comes before pointing device init.
    cocot_config.raw = eeconfig_read_kb();
    if (cocot_config.cpi_idx > CPI_OPTION_SIZE) // || cocot_config.scrl_div > SCRL_DIV_SIZE || cocot_config.rotation_angle > ANGLE_SIZE)
    {
        eeconfig_init_kb();
    }
    matrix_init_user();
}


bool cocot_get_scroll_mode(void) {
    return cocot_config.scrl_mode;
}

void cocot_set_scroll_mode(bool mode) {
    cocot_config.scrl_mode = mode;
}






#ifdef RGB_MATRIX_ENABLE
    led_config_t g_led_config = { {
    // Key Matrix to LED Index
        {  1, 3, 5, 7, 9,51,53,55,57,59 },
        { 10,12,14,16,18,42,44,46,48,50 },
        { 19,20,21,22,23,37,38,39,40,41 },
        { NO_LED,24,26,28, 0,30,32,34,36,NO_LED }
    }, {
    // LED Index to Physical Position
        {126, 174}, {8, 244}, {19, 239}, {32, 249}, {43, 244}, {56, 254}, {66, 233}, {78, 235}, {89, 214}, {101, 216}, {4, 183}, {15, 178}, {28, 187}, {39, 182}, {52, 192}, {62, 171}, {74, 173}, {85, 153}, {97, 155}, {0, 121}, {24, 126}, {48, 131}, {70, 112}, {93, 93}, {52, 40}, {64, 33}, {75, 23}, {88, 12}, {100, 5}, {113, 0}, {126, 0}, {139, 0}, {152, 5}, {165, 11}, {177, 23}, {189, 33}, {201, 39}, {160, 93}, {183, 112}, {205, 130}, {229, 126}, {254, 121}, {156, 155}, {168, 153}, {179, 173}, {191, 171}, {201, 192}, {214, 182}, {225, 187}, {238, 178}, {249, 183}, {152, 216}, {164, 214}, {175, 235}, {187, 233}, {197, 253}, {210, 244}, {221, 249}, {234, 239}, {245, 244}
    }, {
    // LED Index to Flag
        4, 4, 2, 4, 2, 4, 2, 4, 2, 4, 4, 2, 4, 2, 4, 2, 4, 2, 4, 4, 4, 4, 4, 4, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 2, 4, 4, 4, 4, 4, 4, 4, 2, 4, 2, 4, 2, 4, 2, 4, 4, 2, 4, 2, 4, 2, 4, 2, 4
} };
#endif
