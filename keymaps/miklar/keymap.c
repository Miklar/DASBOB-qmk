#include QMK_KEYBOARD_H

#include "keymap_swedish.h"
#include "sendstring_swedish.h"

enum dasbob_layers {
  _QWERTY,
  _NUMBERS,
  _SYMBOLS,
  _NAV
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
      *           │ESC├───┐           ┌───┤BSP│
      *           └───┤SPC├───┐   ┌───┤SPC├───┘
      *               └───│TAB│   │ENT├───┘
      *                NAV└───┘   └───┘
      *                   │NUM│   │SYM│
      */

// CAGS - Ctrl / Opt / Command / Shift
// CAGS - Ctrl / Alt / Gui  / Shift

    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,  KC_E,            KC_R,              KC_T,           KC_Y,         KC_U,              KC_I,              KC_O,           KC_P,
        LCTL_T(KC_A),   LALT_T(KC_S),    LGUI_T(KC_D),      LSFT_T(KC_F),  KC_G,           KC_H,         RSFT_T(KC_J),      RGUI_T(KC_K),      LALT_T(KC_L),   RCTL_T(S(SE_DQUO)),
        KC_Z,    KC_X,              KC_C,            KC_V,            KC_B,             KC_N,         KC_M,              SE_COMM,           SE_DOT,         SE_SLSH,
                                    KC_ESC,          LT(_NAV, KC_SPC),          LT(_NUMBERS, KC_TAB),             LT(_SYMBOLS, KC_ENT),        MEH_T(KC_SPC),           KC_BSPC
    ),

    /*
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │   │ Å │ Ä │ Ö │   │       │   │ 7 │ 8 │ 9 │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │       │   │ 4 │ 5 │ 6 │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │       │ 0 │ 1 │ 2 │ 3 │   │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     */
    [_NUMBERS] = LAYOUT_split_3x5_3(
       _______, SE_ARNG,           SE_ADIA,         SE_ODIA,            _______,            _______,    KC_7,           KC_8,           KC_9,           _______,
       _______, RALT_T(XXXXXXX),   LCTL_T(XXXXXXX), LSFT_T(XXXXXXX),    _______,            _______,    LSFT_T(KC_4),   LCTL_T(KC_5),   RALT_T(KC_6),   _______,
       _______, _______,           _______,         _______,            _______,            KC_0,       KC_1,           KC_2,           KC_3,           _______,
                                    _______,          _______,          _______,            _______,        _______,          _______
    ),

    /*
     * https://www.reddit.com/r/ErgoMechKeyboards/comments/1cim5s9/comment/l2adh8g/?context=3
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │ ` │ < │ > │ " │ . │       │ & │ ; │ [ │ ] │ % │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ ! │ - │ + │ = │ # │       │ | │ : │ ( │ ) │ ? │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │ ^ │ / │ * │ \ │ , │       │ ~ │ _ │ { │ } │ @ │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     */
    [_SYMBOLS] = LAYOUT_split_3x5_3(
        SE_GRV,     SE_SECT,      S(SE_SECT),     SE_DQUO,     SE_DOT,            SE_AMPR,     SE_SCLN,      SE_LBRC,         SE_RBRC, SE_PERC,
        SE_EXLM,    SE_MINS,      SE_PLUS,      SE_EQL,     SE_HASH,             ALGR(SE_7),     SE_COLN,         SE_LPRN,        SE_RPRN,    SE_QUES,
        SE_CIRC,    SE_SLSH,      SE_ASTR,   S(ALGR(SE_7)),   SE_COMM,                SE_TILD,        SE_UNDS,      S(SE_LBRC),      S(SE_RBRC),    SE_AT,
                                    _______,          _______,          _______,             _______,        _______,          _______
    ),

    /*/**/
    /* * https://www.reddit.com/r/ErgoMechKeyboards/comments/1cim5s9/comment/l2adh8g/?context=3*/
    /* * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐*/
    /* * │ ` │ ~ │ # │ & │ | │       │ ^ │ { │ } │ [ │ ] │*/
    /* * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤*/
    /* * │ ! │ ? │ : │ = │ $ │       │ @ │ ( │ ) │ _ │ ; │*/
    /* * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤*/
    /* * │ % │ - │ * │ + │ \ │       │ / │ - │ < │ > │ " │*/
    /* * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘*/
    /* */
    /*[_SYMBOLS] = LAYOUT_split_3x5_3(*/
    /*    SE_GRV,     SE_TILD,       SE_HASH,     SE_AMPR,     ALGR(SE_7),            SE_CIRC,     S(SE_LBRC),      S(SE_RBRC),      SE_LBRC,         SE_RBRC,*/
    /*    SE_EXLM,    SE_QUES,      SE_COLN,      SE_EQL,     SE_DLR,             SE_AT,     SE_LPRN,         SE_RPRN,        SE_UNDS,    SE_SCLN,*/
    /*    SE_PERC,    SE_MINS,      SE_ASTR,      SE_PLUS,   S(ALGR(SE_7)),                   SE_SLSH,        SE_SECT,      S(SE_SECT),      SE_MINS,    SE_DQUO,*/
    /*                                _______,          _______,          _______,             _______,        _______,          _______*/
    /*),*/

    /*
     * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
     * │   │   │   │   │   │       │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │       │ L │ D │ U │ R │   │
     * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
     * │   │   │   │   │   │       │   │ Å │ Ä │ Ö │   │
     * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
     */
    [_NAV] = LAYOUT_split_3x5_3(
       _______, _______,    _______,        _______,    _______,                    KC_AGAIN,       KC_UNDO,        KC_COPY,    KC_PASTE,           _______,
       _______, _______,    _______,        _______,     _______,                    KC_LEFT,        KC_DOWN,        KC_UP,      KC_RIGHT,   _______,
       _______, _______,    _______,        _______,    _______,                    SE_ARNG,        SE_ADIA,        SE_ODIA,    _______,           _______,
                                    _______,          _______,          _______,            _______,        _______,          _______
    )
};

