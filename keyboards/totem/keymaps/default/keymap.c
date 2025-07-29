#include QMK_KEYBOARD_H

enum totem_layers {
    _BASE,
    _COLEMAK,
    _SYM,
    _NUMS,
    _NAV,
    _GAMING,
};

const uint16_t PROGMEM gaming_combo[] = {KC_Q, KC_B, KC_V, COMBO_END};
const uint16_t PROGMEM colemak_combo[] = {KC_Y, KC_U, KC_M, COMBO_END};
combo_t key_combos[] = {
  COMBO(gaming_combo, TG(_GAMING)),
  COMBO(colemak_combo, TG(_COLEMAK)),
};

#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LSFT_T(KC_D)
#define HM_F LCTL_T(KC_F)

#define HM_J RCTL_T(KC_J)
#define HM_K RSFT_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN RGUI_T(KC_SCLN)

#define HM_4 RCTL_T(KC_4)
#define HM_5 RSFT_T(KC_5)
#define HM_6 LALT_T(KC_6)
#define HM_EQL RGUI_T(KC_EQL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* _BASE     ┌─────────┬─────────┬─────────┬─────────┬─────────┐┌─────────┬─────────┬─────────┬─────────┬─────────┐
                 │    Q    │    W    │    E    │    R    │    T    ││    Y    │    U    │    I    │    O    │    P    │
                 ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                 │ A/LGUI  │ S/LALT  │ D/LSFT  │ F/LCTL  │    G    ││    H    │ J/RCTL  │ K/RSFT  │ L/LALT  │ ;/RGUI  │
       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
       │    [    │    Z    │    X    │    C    │    V    │    B    ││    N    │    M    │    ,    │    .    │    /    │    ]    │
       └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                     │    '    │  SPACE  │   ESC   ││  ENTER  │  BSPC   │    -    │
                                     └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/
    [_BASE] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷     ╷╷    ╷         ╷         ╷         ╷         ╷         ╷
                  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
                  HM_A,     HM_S,     HM_D,     HM_F,     KC_G,       KC_H,     HM_J,     HM_K,     HM_L,     HM_SCLN,
        KC_LBRC,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RBRC,
                    LT(_NAV,KC_QUOT), KC_SPC, LT(_NUMS,KC_ESC),       LT(_SYM,KC_ENT), KC_BSPC, KC_MINS
    ),

    /* _COLEMAK  ┌─────────┬─────────┬─────────┬─────────┬─────────┐┌─────────┬─────────┬─────────┬─────────┬─────────┐
                 │    Q    │    W    │    F    │    P    │    B    ││    J    │    L    │    U    │    Y    │    ;    │
                 ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                 │ A/LGUI  │ R/LALT  │ S/LSFT  │ T/LCTL  │    G    ││    M    │ N/RCTL  │ E/RSFT  │ I/LALT  │ O/RGUI  │
       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
       │    [    │    Z    │    X    │    C    │    D    │    V    ││    K    │    H    │    ,    │    .    │    /    │    ]    │
       └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                     │    '    │  SPACE  │   ESC   ││  ENTER  │  BSPC   │    -    │
                                     └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/
    [_COLEMAK] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷     ╷╷    ╷         ╷         ╷         ╷         ╷         ╷
                  KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,       KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,
         LGUI_T(KC_A),LALT_T(KC_R),LSFT_T(KC_S),LCTL_T(KC_T),KC_G,    KC_M,RCTL_T(KC_N),RSFT_T(KC_E),LALT_T(KC_I),RGUI_T(KC_O),
        KC_LBRC,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,       KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RBRC,
                    LT(_NAV,KC_QUOT), KC_SPC, LT(_NUMS,KC_ESC),       LT(_SYM,KC_ENT), KC_BSPC, KC_MINS
    ),

    /* _SYM     ┌─────────┬─────────┬─────────┬─────────┬─────────┐┌─────────┬─────────┬─────────┬─────────┬─────────┐
                │    \    │    [    │    {    │    (    │    @    ││    `    │    )    │    }    │    ]    │    ▼    │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │    !    │    -    │    +    │    =    │    &    ││    ~    │  RCTL   │  RSFT   │  LALT   │  RGUI   │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │    #    │    ^    │    %    │    *    │    $    │    |    ││    ▼    │    ▼    │    <    │    >    │    ?    │    ▼    │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │  CAPS   │   TAB   │  CWORD  ││    ▼    │    ▼    │    ▼    │
                                    └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */
    [_SYM] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷    ╷╷    ╷         ╷         ╷         ╷         ╷         ╷
                  KC_BSLS,  KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_AT,     KC_GRV,   KC_RPRN,  KC_RCBR,  KC_RBRC,  _______,
                  KC_EXLM,  KC_MINS,  KC_PLUS,  KC_EQL,   KC_AMPR,   KC_TILD,  KC_RCTL,  KC_RSFT,  KC_LALT,  KC_RGUI,
         KC_HASH, KC_CIRC,  KC_PERC,  KC_ASTR,  KC_DLR,   KC_PIPE,   _______,  _______,  KC_LT,    KC_GT,    KC_QUES,  _______,
                                      KC_CAPS,  KC_TAB,   CW_TOGG,   _______,  _______,  _______
    ),

    /* _NUMS    ┌─────────┬─────────┬─────────┬─────────┬─────────┐┌─────────┬─────────┬─────────┬─────────┬─────────┐
                │   f1    │   f2    │   f3    │   f4    │   f13   ││    %    │    7    │    8    │    9    │    +    │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │   f5    │   f6    │   f7    │   f8    │   f14   ││    *    │ 4/RCTL  │ 5/RSFT  │ 6/LALT  │ =/RGUI  │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │   f16   │   f9    │   f10   │   f11   │   f12   │   f15   ││    -    │    1    │    2    │    3    │    /    │    .    │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │    ▼    │    ▼    │    ▼    ││    ▼    │   DEL   │    ▼    │
                                    └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */
    [_NUMS] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷    ╷╷    ╷         ╷         ╷         ╷         ╷         ╷
                  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F13,    KC_PERC,  KC_7,     KC_8,     KC_9,     KC_PLUS,
                  KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F14,    KC_ASTR,  HM_4,     HM_5,     HM_6,     HM_EQL,
         KC_F16,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F15,    KC_MINS,  KC_1,     KC_2,     KC_3,     KC_SLSH,  KC_DOT,
                                      _______,  _______,  _______,   KC_0,     KC_DEL,   KC_COMM
    ),

    /* _NAV     ┌─────────┬─────────┬─────────┬─────────┬─────────┐┌─────────┬─────────┬─────────┬─────────┬─────────┐
                │   BUP   │  PREV   │  PLAY   │  NEXT   │         ││         │  PGUP   │  HOME   │         │         │
                ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                │  LGUI   │  LALT   │  LSFT   │  LCTL   │  PRNT   ││  LEFT   │  DOWN   │   UP    │  RIGHT  │         │
      ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
      │         │   BDN   │   VDN   │  MUTE   │   VUP   │         ││         │  PGDN   │   END   │         │         │         │
      └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                    │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │
                                    └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */
    [_NAV] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷    ╷╷    ╷         ╷         ╷         ╷         ╷         ╷
                  KC_BRIU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,   XXXXXXX,  KC_PGUP,  KC_HOME,  XXXXXXX,  XXXXXXX,
                  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL,  KC_PSCR,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,
         XXXXXXX, KC_BRID,  KC_VOLD,  KC_MUTE,  KC_VOLU,  XXXXXXX,   XXXXXXX,  KC_PGDN,  KC_END,   XXXXXXX,  XXXXXXX,  XXXXXXX,
                                      _______,  _______,  _______,   _______,  _______,  _______
    ),

    /* _GAMING   ┌─────────┬─────────┬─────────┬─────────┬─────────┐┌─────────┬─────────┬─────────┬─────────┬─────────┐
                 │    Q    │    W    │    E    │    R    │    T    ││    Y    │    U    │    I    │    O    │    P    │
                 ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
                 │    A    │    S    │    D    │    F    │    G    ││    H    │ J/RCTL  │ K/RSFT  │ L/LALT  │ ;/RGUI  │
       ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
       │  LSFT   │    Z    │    X    │    C    │    V    │    B    ││    N    │    M    │    ,    │    .    │    /    │    '    │
       └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                     │   TAB   │   ESC   │  SPACE  ││  BSPC   │  ENTER  │   DEL   │
                                     └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/
    [_GAMING] = LAYOUT(
        // ╷         ╷         ╷         ╷         ╷         ╷     ╷╷    ╷         ╷         ╷         ╷         ╷         ╷
                  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
                  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,       KC_H,     HM_J,     HM_K,     HM_L,     HM_SCLN,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_QUOT,
                     LT(_NAV,KC_TAB), KC_SPC, LT(_NUMS,KC_ESC),       KC_ENT, KC_BSPC, KC_DEL
    ),
};
