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
    NAV = 2,
    SYM = 3,
    NUM = 4,
} _LAYERS;

#define MO_NAV TL_LOWR
#define MO_SYM TL_UPPR
// >> MO_NUM == MO_NAV | MO_SYM

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

    WE_LBRK,
    ER_RBRK,
    SD_LPRN,
    DF_RPRN,
    XC_LCBR,
    CV_RCBR,

    UI_TAB,
    IO_STAB,
    JK_ESC,
    KL_ENT,
} _COMBOS;

const uint16_t PROGMEM combo_qtb[] = {KC_Q, KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM combo_ypn[] = {KC_Y, KC_P, KC_N, COMBO_END};

const uint16_t PROGMEM combo_we[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_er[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_sd[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_xc[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM combo_ui[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_kl[] = {KC_K, KC_L, COMBO_END};

// DO NOT INCLUDE THESE IN COMBOS, BECAUSE COMM AND DOT ARE PART OF OVERRIDES
// const uint16_t PROGMEM combo_mcomm[] = {KC_M, KC_COMM, COMBO_END};
// const uint16_t PROGMEM combo_commdot[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [QTB_GAME] = COMBO(combo_qtb, DF(GAME)),
    [YPN_BASE] = COMBO(combo_ypn, PDF(BASE)),

    [WE_LBRK] = COMBO(combo_we, KC_LBRC),
    [ER_RBRK] = COMBO(combo_er, KC_RBRC),
    [SD_LPRN] = COMBO(combo_sd, KC_LPRN),
    [DF_RPRN] = COMBO(combo_df, KC_RPRN),
    [XC_LCBR] = COMBO(combo_xc, KC_LCBR),
    [CV_RCBR] = COMBO(combo_cv, KC_RCBR),

    [UI_TAB] = COMBO(combo_ui, KC_TAB),
    [IO_STAB] = COMBO(combo_io, S(KC_TAB)),
    [JK_ESC] = COMBO(combo_jk, KC_ESC),
    [KL_ENT] = COMBO(combo_kl, KC_ENT),
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        // Disable left-hand combos on layer `GAME`
        case WE_LBRK:
        case ER_RBRK:
        case SD_LPRN:
        case DF_RPRN:
        case XC_LCBR:
        case CV_RCBR:
            return !layer_state_is(GAME);

        // No sense in swapping to game, when you already are on game
        case QTB_GAME:
            return !layer_state_is(GAME);

        // No sense in swapping to base, when you already are on base
        case YPN_BASE:
            return !layer_state_is(BASE);
    }

    return true;
}


const key_override_t ko_shift_comm_scln = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t ko_shift_dot_colon = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t ko_ctrl_comm_lt = ko_make_basic(MOD_MASK_CTRL, KC_COMM, KC_LT);
const key_override_t ko_ctrl_dot_gt = ko_make_basic(MOD_MASK_CTRL, KC_DOT, KC_GT);
const key_override_t *key_overrides[] = {
    &ko_shift_comm_scln,
    &ko_shift_dot_colon,
    &ko_ctrl_comm_lt,
    &ko_ctrl_dot_gt
};

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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J, KC_K,    KC_L,   LGUI_T(KC_QUOT),
        KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, LALT_T(KC_SLSH),
              MO_NAV, LSFT_T(KC_SPC), /**/ LCTL_T(KC_BSPC), MO_SYM
    ),

    [GAME] = LAYOUT_split_3x5_2(
        KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
                      KC_P0, KC_BSPC, /**/ KC_SPC, KC_P1
    ),

    [NAV] = LAYOUT_split_3x5_2(
        MS_BTN4, MS_BTN3, MS_BTN2, MS_BTN1, MS_BTN5, /**/ MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_PSCR,
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, MS_WHLU, /**/ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG,
        XXXXXXX, XXXXXXX, MS_WHLL, MS_WHLR, MS_WHLD, /**/ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_CAPS,
                                   _______, XXXXXXX, /**/ KC_DEL,  _______
    ),

    [SYM] = LAYOUT_split_3x5_2(
        KC_BSLS, KC_GRV,  KC_TILD, KC_AT,  KC_PIPE, /**/ EMAIL,     KC_MPRV, KC_MPLY, KC_MNXT, KC_BRIU,
        KC_ASTR, KC_MINS, KC_PLUS, KC_EQL, KC_EXLM, /**/ G(KC_TAB), KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI,
        KC_CIRC, KC_UNDS, KC_PERC, KC_DLR, KC_AMPR, /**/ XXXXXXX,   KC_VOLD, KC_MUTE, KC_VOLU, KC_BRID,
                                  _______, KC_HASH, /**/ XXXXXXX, _______
    ),

    [NUM] = LAYOUT_split_3x5_2(
        KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    /**/ KC_8,    KC_0,    KC_2,    KC_4,    KC_6,
        KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_F11,  /**/ KC_F12,  KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI,
        KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   /**/ KC_F8,   KC_F10,  KC_F2,   KC_F4,   KC_F6,
                                   _______, XXXXXXX, /**/ XXXXXXX, _______
    ),
};
// clang-format on
