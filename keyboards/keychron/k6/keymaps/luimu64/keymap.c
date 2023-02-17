/*
Copyright 2020 Dimitris Mantzouranis
Copyright 2022 Philip Mourdjis

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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _QWERTY,
    _DVPFI,
    _DVRAISE,
    _FN1,
    _FN2,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   
/* _QWERTY Base layout
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ + │ ´ │       │PRT│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ Å │ ¨ │     │DEL│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Ö │ Ä │ ' │    │PUP│
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │ < │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ - │      │UP │PDN│
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │CTRL│ WIN│ALT │                        │ALT│FN1│FN2│LFT│DWN│RGT│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15        */
  [_QWERTY] = { {   KC_GESC,   KC_1,      KC_2,      KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,      KC_0,      KC_MINS,   KC_EQL,    KC_BSPC,   KC_NO,     DF(_DVPFI) },
                {   KC_TAB,    KC_Q,      KC_W,      KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,      KC_P,      KC_LBRC,   KC_RBRC,   KC_NO,     KC_NO,     KC_DEL     },
                {   KC_CAPS,   KC_A,      KC_S,      KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,      KC_SCLN,   KC_QUOT,   KC_NUHS,   KC_ENT,    KC_NO,     KC_PGUP    },
                {   KC_LSFT,   KC_NUBS,   KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,   KC_NO,     KC_RSFT,   KC_UP,     KC_PGDN    },
                {   KC_LCTL,   KC_LGUI,   KC_LALT,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,     KC_RALT,   MO(_FN1),  MO(_FN2),  KC_LEFT,   KC_DOWN,   KC_RGHT    }
              },

/* _Programmer Dvorak Base layout
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ESC│ & │ [ │ { │ } │ ( │ = │ * │ ) │ + │ ] │ ! │ # │       │QWE│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │ ; │ , │ . │ p │ y │ f │ g │ c │ r │ l │ / │ @ │     │HOM│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │SHIFT │ a │ o │ e │ u │ i │ d │ h │ t │ n │ s │ - │ \ │    │PGU│
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │RAIS│ ä │ ' │ q │ j │ k │ x │ b │ m │ w │ v │ v │RAISE │UP │PGD│
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │CTRL│WIN │ALT │                        │CTL│FN1│FN2│LFT│DWN│RGT│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0               1            2            3            4            5         6         7             8        9          10              11         12             13              14         15        */
   [_DVPFI] = { {   KC_GESC,        S(KC_6),     RALT(KC_8),  RALT(KC_7),  RALT(KC_0),  S(KC_8),  S(KC_0),  S(KC_NUHS),   S(KC_9), KC_MINS,   RALT(KC_9),     S(KC_1),   S(KC_3),       KC_BSPC,        KC_NO,     DF(_QWERTY) },
                {   KC_TAB,         S(KC_COMMA), KC_COMMA,    KC_DOT,      KC_P,        KC_Y,     KC_F,     KC_G,         KC_C,    KC_R,      KC_L,           S(KC_7),   RALT(KC_2),    KC_NO,          KC_NO,     KC_HOME    },
                {   KC_LSFT,        KC_A,        KC_O,        KC_E,        KC_U,        KC_I,     KC_D,     KC_H,         KC_T,    KC_N,      KC_S,           KC_SLSH,   RALT(KC_MINS), KC_ENT,         KC_NO,     KC_PGUP    },
                {   MO(_DVRAISE),   KC_QUOT,     KC_BSLS,     KC_Q,        KC_J,        KC_K,     KC_X,     KC_B,         KC_M,    KC_W,      KC_V,           KC_Z,      KC_NO,         MO(_DVRAISE),   KC_UP,     KC_PGDN    },
                {   KC_LCTL,        KC_LGUI,     KC_LALT,     KC_NO,       KC_NO,       KC_NO,    KC_SPC,   KC_NO,        KC_NO,   KC_NO,     KC_RALT,        MO(_FN1),  MO(_FN2),      KC_LEFT,        KC_DOWN,   KC_RGHT    }
                },
              
/* _Programmer Dvorak Shift layer
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ ~ │ % │ 7 │ 5 │ 3 │ 1 │ 9 │ 0 │ 2 │ 4 │ 6 │ 8 │ ` │       │TOG│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │CAPS │ : │ < │ > │ P │ Y │ F │ G │ C │ R │ L │ ? │ ^ │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │ _ │ \ │    │   │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │ ö │ " │ Q │ J │ K │ X │ B │ M │ W │ V │ Z │      │VAI│   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │FN1│   │HUD│VAD│HUI│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0               1            2          3            4        5        6         7        8        9          10         11              12              13         14         15       */
 [_DVRAISE] = { {   RALT(KC_RBRC),  S(KC_5),     KC_7,      KC_5,        KC_3,    KC_1,    KC_9,     KC_0,    KC_2,    KC_4,      KC_6,      KC_8,           S(KC_EQL),      KC_TRNS,   KC_NO,     KC_NO    },
                {   KC_CAPS,        S(KC_DOT),   KC_NUBS,   S(KC_NUBS),  S(KC_P), S(KC_Y), S(KC_F),  S(KC_G), S(KC_C), S(KC_R),   S(KC_L),   S(KC_MINS),     S(KC_RBRC),     KC_NO,     KC_NO,     KC_NO    },
                {   KC_TRNS,        S(KC_A),     S(KC_O),   S(KC_E),     S(KC_U), S(KC_I), S(KC_D),  S(KC_H), S(KC_T), S(KC_N),   S(KC_S),   S(KC_SLASH),    RALT(KC_NUBS),  KC_TRNS,   KC_NO,     KC_NO    },
                {   KC_TRNS,        KC_SCLN,     S(KC_2),   S(KC_Q),     S(KC_J), S(KC_K), S(KC_X),  S(KC_B), S(KC_M), S(KC_W),   S(KC_V),   S(KC_Z),        KC_NO,          KC_TRNS,   RGB_VAI,   KC_NO    },
                {   KC_TRNS,        KC_TRNS,     KC_TRNS,   KC_NO,       KC_NO,   KC_NO,   KC_TRNS,  KC_NO,   KC_NO,   KC_NO,     KC_TRNS,   KC_TRNS,        KC_TRNS,        RGB_HUD,   RGB_VAD,   RGB_HUI  }
              },
               
 /* _FN1 Settings
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ $ │BR+│BR-│   │   │VAD│VAI│PRV│PLY│NXT│MTE│VL-│VL+│       │TOG│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │INS│DEL│END│     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │   │   │   │   │   │   │NKR│   │   │   │   │      │SPI│   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │FN1│FN2│VAD│SPD│VAI│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0               1          2          3        4        5        6         7        8        9          10         11         12         13         14         15        */
     [_FN1] = { {   RALT(KC_4),     KC_BRIU,   KC_BRID,   KC_NO,   KC_NO,   RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_NO,     KC_NO,     RGB_TOG    },
                {   KC_NO,          KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_INS,    KC_DEL,    KC_END,    KC_NO,     KC_NO,     KC_NO      },
                {   KC_NO,          KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_TRNS,        KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    NK_ON,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_SPI,   KC_NO      },
                {   KC_TRNS,        KC_TRNS,   KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_RGUI,   KC_NO,     KC_NO,     RGB_VAD,   RGB_SPD,   RGB_VAI    }
              },             
              
/* _FN2 MOD Keys (common to qwerty/dvorak)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ € │ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│ RESET │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │INS│DEL│END│     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │      │SPI│   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │   │FN2│SAD│SPD│SAI│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15        */
     [_FN2] = { {   RCTL(KC_E),    KC_F1,     KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    RESET,     KC_NO,     RGB_MOD   },
                {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_SPI,   KC_NO      },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_RALT,   KC_NO,     KC_NO,     RGB_SAD,   RGB_SPD,   RGB_SAI    }
              }
};

/*
bool dip_switch_update_user(uint8_t index, bool active){
    switch(index){
        case 0: // macos/windows togggle
            if(active){ //macos
                layer_off(_WINDOWS);
                layer_on(_MAC);
            }
            else{ //windows
                layer_on(_WINDOWS);
                layer_off(_MAC);
            }
        break;
    }
    return true;
}
*/

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}
