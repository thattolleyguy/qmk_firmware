/*
Copyright 2021 Tyler Tolley <thattolleyguy@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H


enum iris_layers {
  _QWERTY,
  _SYM,
  _NUM,
  _NAV,
  _FN
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NUMPAD
};

#define CTL_A   LCTL_T(KC_A)
#define Z_SHFT  LSFT_T(KC_Z)
#define ALT_DOT RALT_T(KC_DOT)
#define FS_SHFT RSFT_T(KC_SLSH)
#define CTL_CLN RCTL_T(KC_SCLN)
#define NUM_TAB LT(_NUM, KC_TAB)
#define SYM_SPC LT(_SYM, KC_SPC)
#define NAV_BSP LT(_NAV, KC_BSPC)
#define DEL_FN  LT(_FN, KC_DEL)
#define CB_PRV  LCTL(KC_F11)
#define CB_NXT  LCTL(KC_F12)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   
  //├────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┤
     CTL_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    CTL_CLN,
  //├────────┼────────┼────────┼────────┼────────┐                  ┌────────┼────────┼────────┼────────┼────────┤
     Z_SHFT,   KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M,    KC_COMM, ALT_DOT, FS_SHFT,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┐         ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                           KC_LGUI, NUM_TAB, KC_ENT,            SYM_SPC, NAV_BSP, DEL_FN
                       // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),


  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_PIPE, XXXXXXX, KC_QUOT, KC_DQT,                     KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS,   
  //├────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┤
     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //├────────┼────────┼────────┼────────┼────────┐                  ┌────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, XXXXXXX, XXXXXXX, CB_PRV,  CB_NXT,                     KC_PPLS, KC_UNDS, KC_MINS, KC_EQL,  KC_RSFT,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┐         ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                           XXXXXXX, XXXXXXX, XXXXXXX,           _______,  XXXXXXX, XXXXXXX
                       // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┐
     KC_VOLU, KC_MPRV, KC_MPLY, KC_MPLY, KC_NUM,                     KC_PAST, KC_P7,    KC_P8,  KC_P9,   KC_PMNS,   
  //├────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┤
     KC_VOLD, KC_MUTE, KC_MSTP, XXXXXXX, XXXXXXX,                    KC_PSLS, KC_P4,    KC_P5,  KC_P6,   KC_PPLS,
  //├────────┼────────┼────────┼────────┼────────┐                  ┌────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_BSPC, KC_P1,   KC_P2,   KC_P3,   KC_EQL,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┐         ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                           XXXXXXX, _______, XXXXXXX,           XXXXXXX, KC_P0,   KC_PDOT
                       // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,                    XXXXXXX, RGB_RMOD,RGB_MOD, RGB_VAD, RGB_VAI,   
  //├────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS,                     KC_PGUP, KC_HOME, KC_BSPC, RGB_SAD, RGB_SAI,
  //├────────┼────────┼────────┼────────┼────────┐                  ┌────────┼────────┼────────┼────────┼────────┤
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,                     KC_PGDN, KC_END,  XXXXXXX, RGB_HUD, RGB_HUI,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┐         ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                           XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, _______, XXXXXXX
                       // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  ),

  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                  ┌────────┬────────┬────────┬────────┬────────┐
     KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                    XXXXXXX, KC_PSCR, KC_SCRL, KC_BRK,  KC_F11,   
  //├────────┼────────┼────────┼────────┼────────┤                  ├────────┼────────┼────────┼────────┼────────┤
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, 
  //├────────┼────────┼────────┼────────┼────────┐                  ┌────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, XXXXXXX, DT_PRNT, DT_DOWN, DT_UP,                      RGB_M_SW,RGB_M_R, XXXXXXX, XXXXXXX, XXXXXXX,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┐         ┌────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                           _______, _______, _______,           XXXXXXX, XXXXXXX, _______
                       // └────────┴────────┴────────┘         └────────┴────────┴────────┘
  )
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Number\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("Function\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    oled_write_P(PSTR("\n"), false);
    
    static char rgbStatusLine1[26] = {0};
    snprintf(rgbStatusLine1, sizeof(rgbStatusLine1), "RGB Mode: %d", rgblight_get_mode());
    oled_write_ln(rgbStatusLine1, false);
    static char rgbStatusLine2[26] = {0};
    snprintf(rgbStatusLine2, sizeof(rgbStatusLine2), "h:%d s:%d v:%d", rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val());
    oled_write_ln(rgbStatusLine2, false);
    
    return false;
}
#endif

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FS_SHFT:
        case Z_SHFT:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}