/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers{
    MAC,
    PC,
    FN,
    FN1,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC] = LAYOUT_61_ansi(
        KC_ESC,        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
    LT(FN, KC_TAB),    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
    LT(FN1, KC_CAPS),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,       KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                      KC_RSFT,
        KC_LGUI,       KC_LALT,  KC_LCTL,                                LT(FN, KC_SPC),                         KC_RGUI,  TT(FN),   TT(FN1),  KC_ALGR),

    [PC] = LAYOUT_61_ansi(
        _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
        KC_LCTL,       _______,  KC_LGUI,                                _______,                                _______,  _______,  _______,  _______),

    [FN] = LAYOUT_61_ansi(
        _______,       KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_BSPC,
        _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,  KC_PGDN,  _______,
        _______,       _______,  _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_HOME,  KC_END,             _______,
        _______,       _______,  KC_DEL,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      _______,
    LM(FN, MOD_LCTL),  _______,  LM(FN, MOD_LGUI),                       _______,                                _______,  _______,  _______,  _______),

    [FN1] = LAYOUT_61_ansi(
        _______,       KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPLY,  KC_MPRV,  KC_MNXT,  KC_BRID,  KC_BRIU,  XXXXXXX,  XXXXXXX,  KC_SLEP,  KC_PWR,   BAT_LVL,
        _______,       BT_HST1,  BT_HST2,  BT_HST3,  XXXXXXX,  XXXXXXX,  KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,  XXXXXXX,  KC_BTN4,  KC_BTN5,  KC_PSCR,
        RGB_TOG,       RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  XXXXXXX,  XXXXXXX,            _______,
        _______,       RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_BTN1,  KC_BTN2,  KC_BTN3,  XXXXXXX,  XXXXXXX,                      _______,
        _______,       _______,  _______,                                BAT_LVL,                                _______,  _______,  _______,  _______),
    };

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t acute_esc_override = ko_make_basic(MOD_BIT(KC_RSFT), KC_ESC, KC_GRV);
const key_override_t tilde_esc_override = ko_make_basic(MOD_BIT(KC_RGUI), KC_ESC, S(KC_GRV));

const key_override_t vim_x_bspc_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DEL, KC_BSPC, 1<<FN);

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &acute_esc_override,
    &tilde_esc_override,
    &vim_x_bspc_override,
    NULL
};
