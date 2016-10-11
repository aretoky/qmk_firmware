#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define C_S(kc)   kc | 0x0100 | 0x0200 // `Ctrl + Shift + kc`(= `kc | 0x1400`)
//#define KC_COLN LSFT(KC_SCLN)
#define KC_UNDB LSFT(KC_MINS)

#define JA_CLON KC_QUOT  // : and +
#define JA_AT   KC_LBRC  // @ and `
#define JA_HAT  KC_EQL   // ^ and ~
#define JA_ENUN KC_RO    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_JYEN  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRC  // [ and {
#define JA_RBRC KC_BSLS  // ] and }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    1   |   2  |   3  |   4  |   5  |   6  |Grv/L2|           |   ^  |   7  |   8  |   9  |   0  |   -  |  \/L2  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  BS  |           |   [  |   Y  |   U  |   I  |   O  |   P  |  @/CTL |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   :    |
 * |--------+------+------+------+------+------| Lclk |           |   ]  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L1  |AltShf| LAlt | Cmd  | EISU |                                       | KANA |  Cmd | RAlt |   _  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                  ,-------------------.       ,--------------.
 *                                  |   Cut   |  Paste  |       | LEFT | RIGHT |
 *                           ,------|---------|---------|       |------+-------+-------.
 *                           |      |         |  Copy   |       |  UP  |       |       |
 *                           | Space|Backspace|---------|       |------|  L1   | Enter |
 *
 *                           |      |         |  Undo   |       | DOWN |       |       |
 *                            `-------------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_1,             KC_2,            KC_3,     KC_4,   KC_5,   KC_6,   LT(MDIA, KC_GRV), 
        KC_TAB,           KC_Q,            KC_W,     KC_E,   KC_R,   KC_T,   KC_BSPC,
        KC_LCTRL,         KC_A,            KC_S,     KC_D,   KC_F,   KC_G,
        KC_LSFT,          KC_Z,            KC_X,     KC_C,   KC_V,   KC_B,   KC_BTN1,
        MO(SYMB),         LALT(KC_LSFT),   KC_LALT,  KC_LGUI,KC_LANG2,
                                                               LGUI(KC_X) ,LGUI(KC_V),
                                                                        LGUI(KC_C),
                                                         KC_SPC,KC_BSPC,LGUI(KC_Z),
        // right hand
        JA_HAT,      KC_7,   KC_8,         KC_9,   KC_0,   KC_MINS,          LT(MDIA, JA_ENVL),
        JA_LBRC,    KC_Y,   KC_U,         KC_I,   KC_O,   KC_P,             CTL_T(JA_AT),
                     KC_H,   KC_J,         KC_K,   KC_L,   KC_SCLN,          JA_CLON,
        JA_RBRC,     KC_N,   KC_M,         KC_COMM,KC_DOT, KC_SLSH,   KC_LSFT,
                             KC_LANG1, KC_RGUI,KC_RALT,JA_ENUN,       MO(SYMB),
        KC_LEFT,     KC_RIGHT,
        KC_UP,
        KC_DOWN,MO(SYMB),KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |   '  |   (  |   )  |      |   ~  |    |   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   !    |   "  |   #  |  $   |  %   |  &   |      |           |      |   '  |  F11 |  F12 |   -  |   @  |    \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | F1   |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |   F7 |   F8 |   F9 |  F10 |    `   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   {  |   }  |   ^  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
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
       KC_TRNS,KC_TRNS,    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_EXLM,    LSFT(KC_QUOT), KC_HASH,KC_DLR,  KC_PERC, KC_AMPR, KC_TRNS,
       KC_TRNS,KC_F1,      KC_F2,         KC_F3,   KC_F4,   KC_F5, 
       KC_TRNS,KC_TRNS,    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,KC_TRNS,    KC_TRNS,       KC_TRNS, KC_TRNS,
                                          KC_TRNS, KC_TRNS,
                                                   KC_TRNS,
                               KC_TRNS,KC_TRNS,    KC_TRNS,
       // right hand
       KC_TRNS, KC_QUOT, KC_LPRN, KC_RPRN, KC_TRNS, KC_TILD, KC_PIPE,
       KC_TRNS, KC_QUOT, KC_F11, KC_F12, KC_MINS, KC_AT, KC_BSLS,
                KC_F6,    KC_F7,  KC_F8,   KC_F9,   KC_F10,KC_GRV,  
       KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_CIRC, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   F1    |  F2  |  F3  |  F4  |  F5  |  F6  |RESET|           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|MsLeft|MsDown| MsUp |MsRght|      | Play   |
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
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   RESET, 
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_MPLY, 
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
