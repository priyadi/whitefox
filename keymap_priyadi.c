/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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
#include "keymap_common.h"
#include "led_controller.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Template
     * ,---------------------------------------------------------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |   |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |   |
     * |---------------------------------------------------------------|
     * |    |   |   |   |   |   |   |   |   |   |   |   |      |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |                    |    |    |     |   |   |   |
     * `---------------------------------------------------------------'
     */
 
     /* Layer 0: Default Layer
     * ,---------------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  Backs|Del|
     * |---------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|   \ |PgU|
     * |---------------------------------------------------------------|
     * |Backsp|  A|  S|  D|  F|  G|  H|  J|  K|  L|Fn3|  '|Enter   |PgD|
     * |---------------------------------------------------------------|
     * |Fn1 |   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Fn2   |Up |Men|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Fn0        |Alt |Fn4 |Ctrl |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP( \
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC, DEL, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGUP, \
        BSPC,A,   S,   D,   F,   G,   H,   J,   K,   L,   FN3 ,QUOT,NUHS,ENT,      PGDN,\
        FN1 ,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,FN2 ,     UP,  MENU,\
        LCTL,LGUI,LALT,               FN0,           RALT,FN4 ,RCTL,     LEFT,DOWN,RGHT \
    ),
    /* Layer 1: Hybrid Esc & hard semicolon
     * ,---------------------------------------------------------------.
     * |  `|   |   |   |   |   |   |   |   |   |   |   |   |       |   |
     * |---------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |      |   |   |   |   |   |   |   |   |   | ; |   |        |   |
     * |---------------------------------------------------------------|
     * |    |   |   |   |   |   |   |   |   |   |   |   |      |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |                    |    |    |     |   |   |   |
     * `---------------------------------------------------------------'
     */
    [1] = KEYMAP( \
        GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SCLN, TRNS,TRNS,TRNS,    TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,\
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS \
    ),
    /* Layer 2: SemicolonFn layer
     * ,---------------------------------------------------------------.
     * |  `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |   |
     * |---------------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |PgU| Up|Pgd|   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |Del   |   |   |   |   |   |Hom|Lef| Dn|Rgt| ; |   |        |   |
     * |---------------------------------------------------------------|
     * |    |   |   |   |   |   |   |Spc|End|Hom|End|   |      |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |                    |PrtS|Menu| Ins |   |   |   |
     * `---------------------------------------------------------------'
     */
    [2] = KEYMAP( \
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,TRNS,FN5, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,UP,  PGDN,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        DEL, TRNS,TRNS,TRNS,TRNS,TRNS,HOME,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,     TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SPC, END, TRNS,HOME,END, TRNS,TRNS,     TRNS,TRNS,\
        TRNS,TRNS,TRNS,               TRNS,          PSCR,APP, INS,      TRNS,TRNS,TRNS \
    ),
    /* Layer 3: SpaceFn layer
     * ,---------------------------------------------------------------.
     * |  `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |   |
     * |---------------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |PgU| Up|Pgd|   |   |   |     |   |
     * |---------------------------------------------------------------|
     * |Del   |   |   |   |   |   |Hom|Lef| Dn|Rgt| ; |   |        |   |
     * |---------------------------------------------------------------|
     * |    |   |   |   |   |   |   |Spc|End|Hom|End|   |      |   |   |
     * |---------------------------------------------------------------|
     * |    |    |    |                    |PrtS|Menu| Ins |   |   |   |
     * `---------------------------------------------------------------'
     */
    [3] = KEYMAP( \
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,TRNS,FN5, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,UP,  PGDN,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        DEL, TRNS,TRNS,TRNS,TRNS,TRNS,HOME,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,     TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SPC, END, TRNS,HOME,END, TRNS,TRNS,     TRNS,TRNS,\
        TRNS,TRNS,TRNS,               TRNS,          PSCR,APP, INS,      TRNS,TRNS,TRNS \
    ),
};

#define ACTION_LEDS_LOGO 1
#define ACTION_LEDS_ENTER 2

const uint16_t fn_actions[] = {
    // spaceFn
    [0] = ACTION_LAYER_TAP_KEY(3, KC_SPC),
    // Hybrid Esc (shift-Esc = ~), & ignore SemicolonFn when shifted (shift-; = :)
    [1] = ACTION_LAYER_MODS(1, MOD_LSFT),
    [2] = ACTION_LAYER_MODS(1, MOD_RSFT),
    // semicolonFn
    [3] = ACTION_LAYER_TAP_KEY(2, KC_SCLN),
    // Hybrid R-Super: Super when pressed, ScrollLock when tapped (mapped to Compose in my Linux OS)
    // Also function as Menu key using SpaceFn/SemicolonFn
    [4] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_SLCK),
    [5] = ACTION_FUNCTION(ACTION_LEDS_LOGO),

};

/* custom action function */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  (void)opt;
  switch(id) {
    case ACTION_LEDS_ENTER:
      // toggle enter LED on press
      if(record->event.pressed) {
        // signal the LED controller thread
        chMBPost(&led_mailbox, LED_MSG_ENTER_TOGGLE, TIME_IMMEDIATE);
      }
      break;
    case ACTION_LEDS_LOGO:
      // toggle TMK LOGO LEDs on press
      if(record->event.pressed) {
        // signal the LED controller thread
        chMBPost(&led_mailbox, LED_MSG_LOGO_TOGGLE, TIME_IMMEDIATE);
      }
      break;
  }
}
