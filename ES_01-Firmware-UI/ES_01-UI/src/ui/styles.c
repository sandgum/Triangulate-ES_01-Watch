#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: Large Button
//

void init_style_large_button_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(0xffffffff));
    lv_style_set_border_width(style, 2);
    lv_style_set_radius(style, 10);
};

lv_style_t *get_style_large_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_large_button_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_large_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_large_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_large_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_large_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Small Title
//

void init_style_small_title_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_barlow_condensed_medium);
    lv_style_set_align(style, LV_ALIGN_CENTER);
};

lv_style_t *get_style_small_title_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_small_title_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_small_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_small_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_small_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_small_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Large Title
//

void init_style_large_title_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_bitcount_single_medium);
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
    lv_style_set_text_align(style, LV_TEXT_ALIGN_AUTO);
};

lv_style_t *get_style_large_title_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_large_title_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_large_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_large_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_large_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_large_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_large_button,
        add_style_small_title,
        add_style_large_title,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_large_button,
        remove_style_small_title,
        remove_style_large_title,
    };
    remove_style_funcs[styleIndex](obj);
}

