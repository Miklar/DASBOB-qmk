#include QMK_KEYBOARD_H

#include "keymap_swedish_pro_mac_iso.h"

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
      *                NUM└───┘   └───┘MEH
      *                   │NAV│   │SYM│
      */

// CAGS - Ctrl / Opt / Command / Shift
// CAGS - Ctrl / Alt / Gui  / Shift

    [_QWERTY] = LAYOUT_split_3x5_3(
        SE_ARNG,    SE_ADIA,  SE_ODIA,            KC_R,              KC_T,           KC_Y,         KC_U,              KC_I,              KC_O,           KC_P,
        /*KC_Q,    KC_W,  KC_E,            KC_R,              KC_T,           KC_Y,         KC_U,              KC_I,              KC_O,           KC_P,*/
        LCTL_T(KC_A),   LALT_T(KC_S),    LGUI_T(KC_D),      LSFT_T(KC_F),  KC_G,           KC_H,         RSFT_T(KC_J),      RGUI_T(KC_K),      LALT_T(KC_L),   RCTL_T(S(KC_DQUO)),
        KC_Z,    KC_X,              KC_C,            KC_V,            KC_B,             KC_N,         KC_M,              KC_COMM,           KC_DOT,         KC_SLSH,
                                    KC_ESC,          LT(_NUMBERS, KC_SPC),          LT(_NAV, KC_TAB),             LT(_SYMBOLS, KC_ENT),        MEH_T(KC_SPC),           KC_BSPC
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
       _______, SE_ARNG,    SE_ADIA,  SE_ODIA,            _______,            _______,    KC_7,           KC_8,           KC_9,           _______,
       LCTL_T(XXXXXXX), LALT_T(XXXXXXX),   LGUI_T(XXXXXXX), LSFT_T(XXXXXXX),    _______,            _______,    RSFT_T(KC_4),   RGUI_T(KC_5),   LALT_T(KC_6),   RCTL_T(XXXXXXX),
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
        KC_QUOT,     SE_LABK,      SE_RABK,     KC_DQUO,     KC_DOT,            KC_AMPR,     KC_SCLN,      SE_LBRC,         SE_RBRC, KC_PERC,
       LCTL_T(KC_EXLM), LALT_T(KC_MINS),   LGUI_T(KC_PLUS), LSFT_T(KC_EQL),     KC_HASH,             KC_7,     RSFT_T(KC_COLN),         RGUI_T(KC_LPRN),  LALT_T(KC_RPRN),    RCTL_T(KC_QUES),
        KC_CIRC,    KC_SLSH,      KC_ASTR,   S(ALGR(KC_7)),   KC_COMM,                KC_TILD,        KC_UNDS,      S(KC_LBRC),      S(KC_RBRC),    KC_AT,
                                    _______,          _______,          _______,             _______,        _______,          _______
    ),

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
       LCTL_T(XXXXXXX), LALT_T(XXXXXXX),   LGUI_T(XXXXXXX), LSFT_T(XXXXXXX),     _______,                    KC_LEFT,        RSFT_T(KC_DOWN),        RGUI_T(KC_UP),      LALT_T(KC_RIGHT),   RCTL_T(_______),
        _______, _______,    _______,        _______,    _______,                    SE_ARNG,           SE_ADIA,         SE_ODIA,    _______,           _______,
                                    _______,          _______,          _______,            _______,        _______,          _______
    )
};

