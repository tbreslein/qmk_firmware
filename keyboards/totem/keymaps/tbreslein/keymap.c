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
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)

#define HM_J RSFT_T(KC_J)
#define HM_K RCTL_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

typedef enum {
    QTB_GAME,
    YPN_BASE,
    UI_TAB,
    IO_STAB,
    JK_ESC,
    KL_ENT,
    MCOMM_LBRC,
    COMMDOT_RBRC,
    NM_LCBR,
    DOTSLSH_RCBR,
    ZX_EXLM,
    XC_LPRN,
    CV_RPRN,
    AS_AT,
    SD_PERC,
    DF_HASH,
    WE_CIRC,
    ER_DLR,
} _COMBOS;
const uint16_t PROGMEM combo_qtb[] = {KC_Q, KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM combo_ypn[] = {KC_Y, KC_P, KC_N, COMBO_END};
const uint16_t PROGMEM combo_ui[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_io[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {HM_J, HM_K, COMBO_END};
const uint16_t PROGMEM combo_kl[] = {HM_K, HM_L, COMBO_END};
const uint16_t PROGMEM combo_mcomm[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_commdot[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_nm[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combo_dotslsh[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM combo_zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_xc[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_as[] = {HM_A, HM_S, COMBO_END};
const uint16_t PROGMEM combo_sd[] = {HM_S, HM_D, COMBO_END};
const uint16_t PROGMEM combo_df[] = {HM_D, HM_F, COMBO_END};
const uint16_t PROGMEM combo_we[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_er[] = {KC_E, KC_R, COMBO_END};
combo_t key_combos[] = {
    [QTB_GAME] = COMBO(combo_qtb, DF(GAME)),
    [YPN_BASE] = COMBO(combo_ypn, DF(BASE)),
    [UI_TAB] = COMBO(combo_ui, KC_TAB),
    [IO_STAB] = COMBO(combo_io, S(KC_TAB)),
    [JK_ESC] = COMBO(combo_jk, KC_ESC),
    [KL_ENT] = COMBO(combo_kl, KC_ENT),
    [MCOMM_LBRC] = COMBO(combo_mcomm, KC_LBRC),
    [COMMDOT_RBRC] = COMBO(combo_commdot, KC_RBRC),
    [NM_LCBR] = COMBO(combo_nm, KC_LCBR),
    [DOTSLSH_RCBR] = COMBO(combo_dotslsh, KC_RCBR),
    [ZX_EXLM] = COMBO(combo_zx, KC_EXLM),
    [XC_LPRN] = COMBO(combo_xc, KC_LPRN),
    [CV_RPRN] = COMBO(combo_cv, KC_RPRN),
    [AS_AT] = COMBO(combo_as, KC_AT),
    [SD_PERC] = COMBO(combo_sd, KC_PERC),
    [DF_HASH] = COMBO(combo_df, KC_HASH),
    [WE_CIRC] = COMBO(combo_we, KC_CIRC),
    [ER_DLR] = COMBO(combo_er, KC_DLR),
};

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t, combo_t *) {
    return true;
}
#endif

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
        // don't fire these on the game layer
        case QTB_GAME:
        case ZX_EXLM:
        case XC_LPRN:
        case CV_RPRN:
        case AS_AT:
        case SD_PERC:
        case DF_HASH:
        case WE_CIRC:
        case ER_DLR:
            return !layer_state_cmp(default_layer_state, GAME);
    }
    return true;
}

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
                   MO(NAV), MO(NUM), KC_SPC, /**/ KC_BSPC, MO(SYM), MO(FN)
    ),

    [GAME] = LAYOUT(
                 KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
                 KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, HM_J, HM_K,    HM_L,   HM_SCLN,
LSFT_T(KC_MINS), KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
       LT(FN, KC_ESC), LALT_T(KC_TAB), KC_SPC, /**/ KC_BSPC, MO(SYM), MO(FN)
    ),

    [SYM] = LAYOUT(
         _______, _______, KC_PIPE, KC_AMPR, _______, /**/ _______, KC_CAPS, CW_TOGG, _______, _______,
         KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  _______, /**/ _______, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI,
_______, KC_QUES, KC_LT,   KC_GT,   KC_BSLS, _______, /**/ _______, _______, _______, _______, _______, _______,
                           _______, KC_GRV,  KC_TILD, /**/ _______, _______, _______
    ),

    [NUM] = LAYOUT(
         _______,  _______, KC_COMM, KC_DOT,  _______, /**/ KC_ASTR, KC_7, KC_8, KC_9, KC_PERC,
         KC_LGUI,  KC_LALT, KC_LSFT, KC_LCTL, _______, /**/ KC_PLUS, KC_4, KC_5, KC_6, KC_COLN,
_______, _______,  _______, _______, _______, _______, /**/ KC_MINS, KC_1, KC_2, KC_3, KC_SLSH, KC_EQL,
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
                    _______, _______, _______, /**/ _______, _______, _______
    ),
};
// clang-format on
