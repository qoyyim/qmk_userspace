#include QMK_KEYBOARD_H

enum layers {
    BASE,
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
    FUN,
};

#define ESC_MED LT(MEDIA, KC_ESC)
#define TAB_MOUSE LT(MOUSE, KC_TAB)
#define SPC_NAV LT(NAV, KC_SPC)
#define BSP_NUM LT(NUM, KC_BSPC)
#define ENT_SYM LT(SYM, KC_ENT)
#define DEL_FUN LT(FUN, KC_DEL)

#define DEAD_ROW XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define HOME_MODS_L KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define HOME_MODS_R XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI
#define THUMBS KC_ESC, KC_TAB, KC_SPC, KC_BSPC, KC_ENT, KC_DEL
#define LAYOUT_wrapper(...) LAYOUT_split_3x5_3(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_wrapper(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,    KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_QUOT),
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                                    ESC_MED, TAB_MOUSE, SPC_NAV, BSP_NUM, ENT_SYM, DEL_FUN
    ),

    [NAV] = LAYOUT_wrapper(
        DEAD_ROW,                                                        KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_AGAIN,
        HOME_MODS_L,                                                     KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        DEAD_ROW,                                                        KC_INS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                                    THUMBS
    ),

    [MOUSE] = LAYOUT_wrapper(
        DEAD_ROW,                                                        DEAD_ROW,
        HOME_MODS_L,                                                     MS_BTN1, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT,
        DEAD_ROW,                                                        MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_BTN2,
                        KC_ESC, KC_TAB, MS_BTN1, MS_BTN1, MS_BTN2, MS_BTN3
    ),

    [MEDIA] = LAYOUT_wrapper(
        RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU,                    RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU,
        KC_MPRV,    KC_VOLD,    KC_MUTE,    KC_VOLU,    KC_MNXT,          KC_MPRV,    KC_VOLD,    KC_MUTE,    KC_VOLU,    KC_MNXT,
        DEAD_ROW,                                                        DEAD_ROW,
                                    THUMBS
    ),

    [NUM] = LAYOUT_wrapper(
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,                              DEAD_ROW,
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                               HOME_MODS_R,
        KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS,                             DEAD_ROW,
                                    KC_ESC, KC_TAB, KC_SPC, KC_BSPC, KC_ENT, KC_DEL
    ),

    [SYM] = LAYOUT_wrapper(
        KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                     DEAD_ROW,
        KC_COLN,  KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,                     HOME_MODS_R,
        KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                     DEAD_ROW,
                                    KC_ESC, KC_TAB, KC_SPC, KC_LPRN, KC_RPRN, KC_DEL
    ),

    [FUN] = LAYOUT_wrapper(
        DEAD_ROW,                                                        KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12,
        HOME_MODS_L,                                                     KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11,
        DEAD_ROW,                                                        KC_PAUS, KC_F1, KC_F2, KC_F3, KC_F10,
                                    KC_ESC, KC_TAB, KC_SPC, KC_BSPC, KC_ENT, KC_DEL
    ),
};
// clang-format on