// Copyright 2026 tbreslein
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// NOTE: WHEN I CHANGE THESE, I NEED TO ADJUST THE TRI LAYER NUMBERS IN config.h
typedef enum {
    BASE = 0,
    ENTHIUM,
    GAME,
    SYM,
    NUM,
    NAV,
    FN,
    // GAMEEXTRA,
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
    QTG_GAME,
    QTB_BASE,
    YPN_ENTHIUM,
    // UI_TAB,
    // IO_STAB,
    // JK_ESC,
    // KL_ENT,
    // MCOMM_LBRC,
    // COMMDOT_RBRC,
    // NM_LCBR,
    // DOTSLSH_RCBR,
    // ZX_EXLM,
    // XC_LPRN,
    // CV_RPRN,
    // AS_AT,
    // SD_PERC,
    // DF_HASH,
    // WE_CIRC,
    // ER_DLR,
} _COMBOS;
const uint16_t PROGMEM combo_qtg[] = {KC_Q, KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_qtb[] = {KC_Q, KC_T, KC_B, COMBO_END};
const uint16_t PROGMEM combo_ypn[] = {KC_Y, KC_P, KC_N, COMBO_END};
// const uint16_t PROGMEM combo_ui[] = {KC_U, KC_I, COMBO_END};
// const uint16_t PROGMEM combo_io[] = {KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM combo_jk[] = {HM_J, HM_K, COMBO_END};
// const uint16_t PROGMEM combo_kl[] = {HM_K, HM_L, COMBO_END};
// const uint16_t PROGMEM combo_mcomm[] = {KC_M, KC_COMM, COMBO_END};
// const uint16_t PROGMEM combo_commdot[] = {KC_COMM, KC_DOT, COMBO_END};
// const uint16_t PROGMEM combo_nm[] = {KC_N, KC_M, COMBO_END};
// const uint16_t PROGMEM combo_dotslsh[] = {KC_DOT, KC_SLSH, COMBO_END};
// const uint16_t PROGMEM combo_zx[] = {KC_Z, KC_X, COMBO_END};
// const uint16_t PROGMEM combo_xc[] = {KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};
// const uint16_t PROGMEM combo_as[] = {HM_A, HM_S, COMBO_END};
// const uint16_t PROGMEM combo_sd[] = {HM_S, HM_D, COMBO_END};
// const uint16_t PROGMEM combo_df[] = {HM_D, HM_F, COMBO_END};
// const uint16_t PROGMEM combo_we[] = {KC_W, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_er[] = {KC_E, KC_R, COMBO_END};
combo_t key_combos[] = {
    [QTG_GAME] = COMBO(combo_qtg, DF(GAME)),
    [QTB_BASE] = COMBO(combo_qtb, DF(BASE)),
    [YPN_ENTHIUM] = COMBO(combo_ypn, DF(ENTHIUM)),
};

// #ifdef COMBO_MUST_TAP_PER_COMBO
// bool get_combo_must_tap(uint16_t, combo_t *) {
//     return true;
// }
// #endif

// bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
//     switch (combo_index) {
//         // don't fire these on the game layer
//         case QTB_GAME:
//         case ZX_EXLM:
//         case XC_LPRN:
//         case CV_RPRN:
//         case AS_AT:
//         case SD_PERC:
//         case DF_HASH:
//         case WE_CIRC:
//         case ER_DLR:
//             return !layer_state_cmp(default_layer_state, GAME);
//     }
//     return true;
// }

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
   LT(NAV, KC_ESC), LT(NUM, KC_TAB), KC_SPC, /**/ KC_BSPC, LT(SYM, KC_ENT), MO(FN)
    ),

    [ENTHIUM] = LAYOUT(
            KC_Q,         KC_Y,         KC_O,         KC_U,         KC_EQL,  /**/ KC_X, KC_L,         KC_D,         KC_P,         KC_Z,
            LGUI_T(KC_C), LALT_T(KC_I), LCTL_T(KC_A), LSFT_T(KC_E), KC_MINS, /**/ KC_K, RSFT_T(KC_H), RCTL_T(KC_T), LALT_T(KC_N), RGUI_T(KC_S),
      KC_B, KC_QUOT,      KC_COMM,      KC_DOT,       KC_SCLN,      KC_SLSH, /**/ KC_J, KC_M,         KC_G,         KC_F,         KC_V,         KC_W,
                                   LT(NAV, KC_ESC), LT(NUM, KC_TAB), KC_SPC, /**/ KC_BSPC, LT(SYM, KC_R), LT(FN, KC_ENT)
    ),

    [GAME] = LAYOUT(
                 KC_Q, KC_W, KC_E, KC_R, KC_T, /**/ KC_Y, KC_U, KC_I,    KC_O,   KC_P,
                 KC_A, KC_S, KC_D, KC_F, KC_G, /**/ KC_H, HM_J, HM_K,    HM_L,   HM_SCLN,
LSFT_T(KC_MINS), KC_Z, KC_X, KC_C, KC_V, KC_B, /**/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
       LT(FN, KC_ESC), LALT_T(KC_TAB), KC_SPC, /**/ KC_BSPC, LT(SYM, KC_ENT), MO(FN)
    ),

    [SYM] = LAYOUT(
         KC_BSLS, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, /**/ KC_CAPS, CW_TOGG, KC_LT,   KC_GT,   _______,
         KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  KC_AMPR, /**/ _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
KC_HASH, KC_CIRC, KC_PERC, KC_EXLM, KC_DLR,  KC_PIPE, /**/ _______, _______, _______, _______, _______, _______,
                             KC_AT, KC_GRV,  KC_TILD, /**/ _______, _______, _______
    ),

    [NUM] = LAYOUT(
         _______,  _______, KC_COMM, KC_DOT,  _______, /**/ KC_ASTR, KC_7, KC_8, KC_9, KC_PERC,
         KC_LGUI,  KC_LALT, KC_LCTL, KC_LSFT, _______, /**/ KC_PLUS, KC_4, KC_5, KC_6, KC_COLN,
_______, _______,  _______, _______, _______, _______, /**/ KC_MINS, KC_1, KC_2, KC_3, KC_SLSH, KC_EQL,
                            _______, _______, _______, /**/ KC_DEL, KC_0, _______
    ),

    [NAV] = LAYOUT(
         _______, _______, MS_BTN4, MS_BTN5, _______, /**/ MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, KC_PGUP,
         KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, /**/ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PGDN,
_______, _______, _______, _______, _______, _______, /**/ MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, KC_HOME, KC_END,
                           _______, _______, _______, /**/ MS_BTN1, MS_BTN2, MS_BTN3
    ),

    [FN] = LAYOUT(
        KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F13, /**/ EMAIL,   KC_MPRV, KC_MPLY, KC_MNXT, KC_BRIU,
        KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_F14, /**/ _______, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI,
KC_F16, KC_F9, KC_F10, KC_F11, KC_F12, KC_F15, /**/ _______, KC_VOLD, KC_MUTE, KC_VOLU, KC_BRID, G(KC_TAB),
                    _______, _______, _______, /**/ _______, _______, _______
    ),
};
// clang-format on
