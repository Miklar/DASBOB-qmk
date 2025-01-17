#include QMK_KEYBOARD_H

/*#include "keymap_swedish.h"*/

enum dasbob_layers {
  _QWERTY,
  _NUMBERS,
  _SYMBOLS,
  _RAISE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │DEL├───┐           ┌───┤ESC│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘
      *               └───│LOW│   │RSE├───┘
      *                   └───┘   └───┘
      */

    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,              KC_E,            KC_R,            KC_T,               KC_Y,         KC_U,              KC_I,              KC_O,           KC_P,
        KC_A,    RALT_T(KC_S),      LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,               KC_H,         LSFT_T(KC_J),      LCTL_T(KC_K),      RALT_T(KC_L),   KC_SCLN,
        KC_Z,    KC_X,              KC_C,            KC_V,            KC_B,               KC_N,         KC_M,              KC_COMM,           KC_DOT,         KC_SLSH,
                                    KC_ESC,          KC_SPC,          LT(_NUMBERS, KC_TAB),             LT(_SYMBOLS, KC_ENT),        KC_SPC,           KC_ESC
    ),

    [_NUMBERS] = LAYOUT_split_3x5_3(
       KC_1,     UC(0x00E5),           UC(0x00E4),         UC(0x00F6),          KC_5,               KC_1,         KC_7,             KC_2,            KC_9,              KC_0,
       CK_RST,  RALT_T(XXXXXXX),   LCTL_T(XXXXXXX), LSFT_T(XXXXXXX), KC_PSCR,           KC_4,      LSFT_T(KC_4),   LCTL_T(KC_5),  RALT_T(KC_6),    KC_BSLS,
       CK_TOGG,  CK_UP,           CK_DOWN,         LCTL(KC_C),      LCTL(KC_V),         KC_0,      KC_1,          KC_2,         KC_3,           XXXXXXX,
                                    _______,          _______,          _______,             _______,        _______,          _______
    ),

    /*
     * https://www.reddit.com/r/ErgoMechKeyboards/comments/1cim5s9/comment/l2adh8g/?context=3
     *      ` ~ # & |    ^ { } [ ]
     *      ! _ : = $    @ ( ) _ ;
     *      % ? * + \    / - < > "
     */
    [_SYMBOLS] = LAYOUT_split_3x5_3(
        KC_GRV,     LSFT(KC_GRV),       LSFT(KC_3),     LSFT(KC_7),     LSFT(KC_BSLS),            LSFT(KC_6),     LSFT(KC_LBRC),      LSFT(KC_RBRC),      KC_LBRC,         KC_RBRC,
        LSFT(KC_1), LSFT(KC_MINS),      LSFT(KC_SCLN),  KC_EQL,         LSFT(KC_4),                 LSFT(KC_2),     LSFT(KC_9),         LSFT(KC_0),         LSFT(KC_MINS), KC_SCLN,
        LSFT(KC_5), LSFT(KC_SLSH),      LSFT(KC_8),      LSFT(KC_EQL),   KC_BSLS,                   KC_SLSH,        KC_MINS,        LSFT(KC_COMM),      LSFT(KC_DOT),       LSFT(KC_QUOT),
                                    _______,          _______,          _______,             _______,        _______,          _______
    ),

};
