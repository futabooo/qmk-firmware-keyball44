/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for futabooo (VIA)
  [0] = LAYOUT_universal(
    KC_ESC        , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                         KC_Y     , KC_U     , KC_I     , KC_O     , KC_P           , KC_DEL   ,
    CTL_T(KC_TAB) , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                         KC_H     , KC_J     , KC_K     , KC_L     , LT(3,KC_SCLN)  , RCTL_T(KC_QUOT)  ,
    KC_LSFT       , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                         KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH        , KC_RSFT  ,
              KC_LALT , KC_LGUI ,    LT(2,KC_LNG2) , LT(1,KC_SPC) , LT(3,KC_LNG1) ,                   SFT_T(KC_BSPC)  , RCMD_T(KC_ENT) ,       XXXXXXX  , XXXXXXX  , G(A(KC_SPC))
  ),

  [1] = LAYOUT_universal(
    XXXXXXX              , KC_1     , KC_2     , KC_3     , KC_4        , KC_5     ,                                   KC_6     , KC_7        , KC_8     , KC_9        , KC_0       , XXXXXXX            ,
    CTL_T(KC_GRV)        , KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR      , KC_PERC  ,                                   KC_CIRC  , KC_AMPR     , KC_ASTR  , KC_MINS     , S(KC_EQL)  , RCTL_T(KC_BSLS)    ,
    S(KC_GRV)            , XXXXXXX  , XXXXXXX  , KC_LBRC  , S(KC_LBRC)  , KC_LPRN  ,                                   KC_RPRN  , S(KC_RBRC)  , KC_RBRC  , S(KC_MINS)  , KC_EQL     , RSFT(S(KC_BSLS))   ,
                  _______  , _______  ,           XXXXXXX  ,  XXXXXXX  , XXXXXXX  ,                   _______  , KC_RCMD  ,        XXXXXXX  , XXXXXXX  , _______
  ),

  [2] = LAYOUT_universal(
    XXXXXXX  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                         KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , XXXXXXX  ,
    KC_LCTL  , KC_F11   , KC_F12   , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                         XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    KC_LSFT  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                         XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
                  _______  , _______  ,           XXXXXXX  ,  XXXXXXX  , XXXXXXX  ,                   _______  , _______  ,        XXXXXXX  , XXXXXXX  , _______
  ),

  [3] = LAYOUT_universal(
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX   , XXXXXXX  ,                                       XXXXXXX  , XXXXXXX  , KC_UP    , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , CPI_I100  , SCRL_DVI ,                                       XXXXXXX  , KC_LEFT  , KC_DOWN  , KC_RGHT  , XXXXXXX  , XXXXXXX  ,
    _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , CPI_D100  , SCRL_DVD ,                                       XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , KBC_SAVE ,
                  _______  , _______  ,           QK_BOOT  ,  KBC_RST  , XXXXXXX  ,                   _______  , _______  ,        XXXXXXX  , XXXXXXX  , _______
  ),

  [4] = LAYOUT_universal(
    XXXXXXX  ,  XXXXXXX , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        XXXXXXX        , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
    _______  ,  XXXXXXX , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        LCMD(KC_LBRC)  , KC_BTN1  , KC_BTN2  , KC_BTN3  , XXXXXXX  , XXXXXXX  ,
    _______  ,  XXXXXXX , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,                                        LCMD(KC_RBRC)  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,
                  _______  , _______ ,            XXXXXXX  ,  XXXXXXX  , XXXXXXX  ,                   _______  , XXXXXXX  ,        XXXXXXX  , XXXXXXX  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 3:
            // keyballはlayer3がスクロールモードなのでAutomatic Mouse LayerをOFFにする
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            keyball_set_scroll_mode(true);
            break;
        default:
            set_auto_mouse_enable(true);
            keyball_set_scroll_mode(false);
            break;
    }
    return state;
}

void pointing_device_init_user(void) {
    // set_auto_mouse_layer(<mouse_layer>); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
