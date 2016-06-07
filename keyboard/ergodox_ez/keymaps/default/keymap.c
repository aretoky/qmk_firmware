#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define C_S(kc)   kc | 0x0100 | 0x0200 // `Ctrl + Shift + kc`(= `kc | 0x1400`)
#define KC_COLN LSFT(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Grv    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   :    |
 * |--------+------+------+------+------+------| Lclk |           | Rclk |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L1  |AltShf| Cmd  | LAlt | EISU |                                       | KANA | RAlt |      |      | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                  ,-------------------.       ,--------------.
 *                                  |  MsLeft | MsRight |       | LEFT | RIGHT |
 *                           ,------|---------|---------|       |------+-------+-------.
 *                           |      |         |   MsUp  |       |  UP  |       |       |
 *                           | Space|Backspace|---------|       |------|  Esc  | Enter |
 *                           |      |         |  MsDown |       | DOWN |       |       |
 *                            `-------------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,           KC_1,            KC_2,     KC_3,   KC_4,   KC_5,   KC_TRNS,
        KC_TAB,           KC_Q,            KC_W,     KC_E,   KC_R,   KC_T,   KC_TRNS,
        KC_LCTRL,         KC_A,            KC_S,     KC_D,   KC_F,   KC_G,
        KC_LSFT,          KC_Z,            KC_X,     KC_C,   KC_V,   KC_B,   KC_BTN1,
        MO(SYMB),         LALT(KC_LSFT),   KC_LGUI,  KC_LALT,C_S(KC_SCLN),
                                                                KC_MS_L,KC_MS_R,
                                                                        KC_MS_U,
                                                         KC_SPC,KC_BSPC,KC_MS_D,
        // right hand
        KC_TRNS,     KC_6,   KC_7,         KC_8,   KC_9,   KC_0,             KC_MINS,
        KC_TRNS,     KC_Y,   KC_U,         KC_I,   KC_O,   KC_P,             KC_BSLS,
                     KC_H,   KC_J,         KC_K,   KC_L,   LT(MDIA, KC_SCLN),KC_COLN,
        KC_BTN2,     KC_N,   KC_M,         KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                             C_S(KC_J), KC_RALT,KC_TRNS,KC_TRNS,            MO(SYMB),
        KC_LEFT,     KC_RIGHT,
        KC_UP,
        KC_DOWN,KC_ESC, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   !  |   "  |  #   |  $   |  %   |  &   |           |   '  |   (  |   )  |      |   =  |   ~  |    |   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |   -  |   ^  |    \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |   `  |   [  |    {   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |   @  |   ]  |    }   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |   +  |   *  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_EXLM,    LSFT(KC_QUOT), KC_HASH, KC_DLR,  KC_PERC, KC_AMPR,
       KC_TRNS,KC_TRNS,    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,KC_TRNS,    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, 
       KC_TRNS,KC_TRNS,    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,KC_TRNS,    KC_TRNS,       KC_TRNS, KC_TRNS,
                                          KC_TRNS, KC_TRNS,
                                                   KC_TRNS,
                               KC_TRNS,KC_TRNS,    KC_TRNS,
       // right hand
       KC_QUOT, KC_LPRN, KC_RPRN, KC_TRNS, KC_EQL,  KC_TILD, KC_PIPE,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_CIRC, KC_BSLS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV,  KC_LBRC,  KC_LCBR,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AT,   KC_RBRC, KC_RCBR,
                KC_TRNS, KC_TRNS, KC_PLUS, KC_ASTR, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
