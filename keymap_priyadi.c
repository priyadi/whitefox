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
#include <stdint.h>
#include <stdbool.h>
#include "action.h"
#include "action_code.h"
#include "action_layer.h"
#include "action_util.h"
#include "bootloader.h"
#include "command.h"
#include "keycode.h"
#include "print.h"
#include "report.h"
#include "keymap.h"

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
     * |Fn1 |   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Fn2   |Up |Fn4|
     * |---------------------------------------------------------------|
     * |Ctrl|Gui |Alt |         Fn0        |Alt |Gui |Ctrl |Lef|Dow|Rig|
     * `---------------------------------------------------------------'
     */
    [0] = KEYMAP( \
        FN7, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, NO,  BSPC, DEL, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     PGUP, \
        BSPC,A,   S,   D,   F,   G,   H,   J,   K,   L,   FN3 ,QUOT,NUHS,ENT,      PGDN,\
        LSFT,NO,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,FN8,      UP,  FN6,\
        LCTL,LGUI,LALT,               FN0,           RALT,FN4, RCTL,     LEFT,DOWN,RGHT \
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
    // [1] = KEYMAP( \
    //     GRV, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
    //     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS, \
    //     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SCLN, TRNS,TRNS,TRNS,    TRNS,\
    //     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,\
    //     TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS \
    // ),
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
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,TRNS,INS, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,UP,  PGDN,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        DEL, TRNS,TRNS,TRNS,TRNS,TRNS,HOME,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SPC, END, TRNS,HOME,END, TRNS,TRNS,     TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS \
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
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS,TRNS,INS, \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,UP,  PGDN,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        DEL, TRNS,TRNS,TRNS,TRNS,TRNS,HOME,LEFT,DOWN,RGHT,TRNS,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SPC, END, TRNS,HOME,END, TRNS,TRNS,     TRNS,TRNS, \
        TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS \
    ),
    /* Layer 4: Other
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
    [4] = KEYMAP( \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,VOLU,VOLD,MUTE,TRNS,TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MPLY,TRNS,PSCR,TRNS,TRNS,TRNS,     TRNS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,MPRV,MSTP,MNXT,TRNS,TRNS,TRNS,TRNS,     TRNS,\
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,\
        TRNS,TRNS,TRNS,               FN5,           TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS \
    ),
};

enum function_id {
    ACTION_LEDS_LOGO,
    ACTION_ESCAPE
};

const uint16_t fn_actions[] = {
    // spaceFn
    [0] = ACTION_LAYER_TAP_KEY(3, KC_SPC),
    // Hybrid Esc (shift-Esc = ~), & ignore SemicolonFn when shifted (shift-; = :)
    // [1] = ACTION_LAYER_MODS(1, MOD_LSFT),
    // [2] = ACTION_LAYER_MODS(1, MOD_RSFT),
    // semicolonFn
    [3] = ACTION_LAYER_TAP_KEY(2, KC_SCLN),
    // Hybrid R-Super: Super when pressed, ScrollLock when tapped (mapped to Compose in my Linux OS)
    // Also function as Menu key using SpaceFn/SemicolonFn
    [4] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_SLCK),
    // toggle led
    [5] = ACTION_FUNCTION(ACTION_LEDS_LOGO),
    // hybrid End key
    [6] = ACTION_LAYER_TAP_KEY(4, KC_END),
    // Hybrid Escape
    [7] = ACTION_FUNCTION(ACTION_ESCAPE),
    // right shift functions as Home when tapped
    [8] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_HOME)
};

/* custom action function */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  (void)opt;
  switch(id) {
    case ACTION_LEDS_LOGO:
        // toggle TMK LOGO LEDs on press
        if(record->event.pressed) {
            // signal the LED controller thread
            chMBPost(&led_mailbox, LED_MSG_LOGO_TOGGLE, TIME_IMMEDIATE);
        }
        break;
    case ACTION_ESCAPE:
        ;
        uint8_t shifted = get_mods() & (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT));
        void (*method)(uint8_t) = (record->event.pressed) ? &add_key : &del_key;
        if(layer_state == 0)
            method(shifted ? KC_GRAVE : KC_ESCAPE);
        else
            method(shifted ? KC_ESCAPE : KC_GRAVE);

        send_keyboard_report();
        break;
  }
}
