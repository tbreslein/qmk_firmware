// Copyright 2026 tbreslein
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// NOTE: WHEN I CHANGE THESE, I NEED TO ADJUST THE TRI LAYER NUMBERS IN config.h
typedef enum {
    BASE = 0,
    GAME = 1,
    SYM = 2,
    NUM = 3,
    NAV = 4,
    FN = 5,
    // GAMEEXTRA = 6,
} _LAYERS;

#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LSFT_T(KC_D)
#define HM_F LCTL_T(KC_F)

#define HM_J RCTL_T(KC_J)
#define HM_K RSFT_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

typedef enum {
    QTB_GAME,
    YPN_BASE,
    MCOMM_LBRC,
    COMMDOT_RBRC,
} _COMBOS;
const uint16_t PROGMEM combo_qtb[] = {KC_Q, KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM combo_ypn[] = {KC_Y, KC_P, KC_N, COMBO_END};
const uint16_t PROGMEM combo_mcomm[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_commdot[] = {KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    [QTB_GAME] = COMBO(combo_qtb, DF(GAME)),
    [YPN_BASE] = COMBO(combo_ypn, DF(BASE)),
    [MCOMM_LBRC] = COMBO(combo_mcomm, KC_LBRC),
    [COMMDOT_RBRC] = COMBO(combo_commdot, KC_RBRC),
};

// const key_override_t ko_shift_comm_scln = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_MINS);
// const key_override_t ko_shift_dot_colon = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_UNDS);
// const key_override_t ko_ctrl_comm_lt = ko_make_basic(MOD_MASK_ALT, KC_COMM, KC_LT);
// const key_override_t ko_ctrl_dot_gt = ko_make_basic(MOD_MASK_ALT, KC_DOT, KC_GT);
// const key_override_t *key_overrides[] = {
//     &ko_shift_comm_scln,
//     &ko_shift_dot_colon,
//     &ko_ctrl_comm_lt,
//     &ko_ctrl_dot_gt
// };

typedef enum {
    EMAIL = SAFE_RANGE,
} custom_keycodes;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EMAIL:
        if (record->event.pressed) {
            SEND_STRING("tommy.breslein@protonmail.com");
        }
        break;
    }
    return true;
};

// TODO:

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
               KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
               HM_A, HM_S, HM_D, HM_F, KC_G, /**/ KC_H, HM_J, HM_K,    HM_L,   HM_SCLN,
      KC_MINS, KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
LT(NAV, S(KC_TAB)), LT(NUM, KC_ESC), KC_SPC, /**/ KC_BSPC, LT(SYM, KC_ENT), LT(FN, KC_TAB)
    ),

    [GAME] = LAYOUT(
                 KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
                 KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, HM_J, HM_K,    HM_L,   HM_SCLN,
LSFT_T(KC_MINS), KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
       LT(FN, KC_ESC), LALT_T(KC_TAB), KC_SPC, /**/ KC_BSPC, LT(SYM, KC_ENT), LT(FN, KC_TAB)
    ),

    // IDEA: this could become a layer that is accessible through a combo on the
    // GAME layer with a one-shot. then the keys could become things that
    // wouldn't be accessible otherwise, like numbers and symbols
//     [GAMEEXTRA] = LAYOUT(
//         KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F13, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
//         KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_F14, /**/ KC_H, HM_J, HM_K,    HM_L,   HM_SCLN,
// KC_F16, KC_F9, KC_F10, KC_F11, KC_F12, KC_F15, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
//                     _______, _______, _______, /**/ KC_BSPC, LT(SYM, KC_ENT), LT(FN, KC_TAB)
//     ),

    [SYM] = LAYOUT(
         _______, KC_AT,   KC_LPRN, KC_RPRN, KC_BSLS, /**/ _______, KC_TAB,  S(KC_TAB), _______, _______,
         KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_AMPR, /**/ _______, KC_RCTL, KC_RSFT,   KC_LALT, KC_RGUI,
KC_HASH, KC_CIRC, KC_PERC, KC_EXLM, KC_DLR,  KC_PIPE, /**/ _______, _______, KC_LT,     KC_GT,   KC_QUES, _______,
                           _______, KC_GRV,  KC_TILD, /**/ _______, _______, _______
    ),

    [NUM] = LAYOUT(
         _______,  _______, KC_COMM, KC_DOT,  _______, /**/ KC_ASTR, KC_7, KC_8, KC_9, KC_PERC,
         KC_LGUI,  KC_LALT, KC_LSFT, KC_LCTL, _______, /**/ KC_PLUS, KC_4, KC_5, KC_6, KC_EQL,
_______, _______,  _______, _______, _______, _______, /**/ KC_MINS, KC_1, KC_2, KC_3, KC_SLSH, KC_CIRC,
                            _______, _______, _______, /**/ KC_DEL, KC_0, _______
    ),

    [NAV] = LAYOUT(
         _______, _______, MS_BTN4, MS_BTN5, _______, /**/ MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_PGUP,
         KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______, /**/ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN,
_______, _______, _______, _______, _______, _______, /**/ MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_HOME, KC_END,
                           _______, _______, _______, /**/ MS_BTN1, MS_BTN2, MS_BTN3
    ),

    [FN] = LAYOUT(
        KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F13, /**/ EMAIL,   KC_MPRV, KC_MPLY, KC_MNXT, KC_BRIU,
        KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_F14, /**/ _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI,
KC_F16, KC_F9, KC_F10, KC_F11, KC_F12, KC_F15, /**/ _______, KC_VOLD, KC_MUTE, KC_VOLU, KC_BRID, G(KC_TAB),
                    _______, KC_CAPS, CW_TOGG, /**/ _______, _______, _______
    ),
};
// clang-format on
