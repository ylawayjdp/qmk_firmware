#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define QW 0
#define LW 1
#define RS 2
#define MAC 3
#define NUM 4

// This a slightly modified 'default' keymap that's closer to the Mac keyboard layout. I like the position
// of 'esc' and 'tab' better this way. I also got rid of the backlighting control key and the dvorak and
// colemak layers. I added an 'fn' layer that makes the 'bspc' a forward delete (like on OSX).
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* MIT Layout (QWERTY layer)
 *
 * ,-----------------------------------------------------------------------.
 * |no/esc |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  | bspc|
 * |-----------------------------------------------------------------------|
 * | tab |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |
 * |-----------------------------------------------------------------------|
 * |shift|  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |shft/enter|
 * |-----------------------------------------------------------------------|
 * | fn  | ctl | alt | cmd |lower|    spc    |raise|left |down | up  |right|
 * `-----------------------------------------------------------------------'
 */
[QW] = { /* QWERTY */
  {KC_FN1,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, FUNC(3)},
  {MO(MAC), KC_LCTL, KC_LALT, KC_LGUI, MO(LW), KC_FN2,  KC_FN2,  MO(RS), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
},
/* MIT Layout (Raised layer)
 *
 * ,-----------------------------------------------------------------------.
 * |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |     |
 * |-----------------------------------------------------------------------|
 * |     | F1  | F2  | F3  | F4  | F5  | F6  |  -  |  +  |  [  |  ]  |     |
 * |-----------------------------------------------------------------------|
 * |     | F7  | F8  | F9  | F10 | F11 | F12 |     |     |     |  |  |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[RS] = { /* RAISE */
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DELT},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TRNS},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PIPE, KC_TRNS}
},
/* MIT Layout (Lowered layer)
 *
 * ,-----------------------------------------------------------------------.
 * |  ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |     |
 * |-----------------------------------------------------------------------|
 * |     | F1  | F2  | F3  | F4  | F5  | F6  |  _  |  =  |  {  |  }  |     |
 * |-----------------------------------------------------------------------|
 * |     | F7  | F8  | F9  | F10 | F11 | F12 |     |     |     |  \  |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |           |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[LW] = { /* LOWER */
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DELT},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_EQL,  KC_LCBR, KC_RCBR, KC_TRNS},
  {KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
/* MIT Layout (Macro layer)
*
* ,-----------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     | del |
* |-----------------------------------------------------------------------|
* |     |     |     |     |     |     | home|     |     |     |     |     |
* |-----------------------------------------------------------------------|
* |     |     |     |     |     |     |  end|     |     |     |     |     |
* |-----------------------------------------------------------------------|
* |     |     |     |     |     |           |     |     |     |     |     |
* `-----------------------------------------------------------------------'
*/
[MAC] = { /* QWERTY */
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DELT},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
},
/* MIT Layout (Number layer ESC)
 *
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     |     |  7  | 8   | 9   |  =  |     |     | del |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |  4  | 5   | 6   |  -  |  +  |     |     |
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |  1  | 2   | 3   |  *  |  /  |     |enter|
 * |-----------------------------------------------------------------------|
 * |     |     |     |     |     |     0     |  .  |home |pgdn |pgup | end |
 * `-----------------------------------------------------------------------'
 */
[NUM] = { /* FUNCTION */
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_EQUAL, KC_TRNS, KC_TRNS, KC_DELT},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_4, KC_KP_4, KC_KP_6, KC_KP_MINUS, KC_KP_PLUS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ASTERISK, KC_KP_SLASH, KC_TRNS, KC_KP_ENTER},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_0, KC_KP_0, KC_KP_DOT, KC_HOME, KC_PGDN, KC_PGUP, KC_END}
}
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_KEY(NUM, KC_ESC)
    [2] = ACTION_LAYER_TAP_KEY(MAC, KC_SPACE)
    [3] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENTER)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            backlight_step();
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
