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
    lv_style_set_border_width(style, 4);
    lv_style_set_radius(style, 22);
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
// Style: Large Button white
//

void init_style_large_button_white_MAIN_DEFAULT(lv_style_t *style) {
    init_style_large_button_MAIN_DEFAULT(style);
    
    lv_style_set_bg_color(style, lv_color_hex(0xffffffff));
};

lv_style_t *get_style_large_button_white_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_large_button_white_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_large_button_white(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_large_button_white_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_large_button_white(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_large_button_white_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Inset Button White
//

void init_style_inset_button_white_MAIN_DEFAULT(lv_style_t *style) {
    init_style_large_button_white_MAIN_DEFAULT(style);
    
    lv_style_set_border_width(style, 2);
    lv_style_set_radius(style, 16);
};

lv_style_t *get_style_inset_button_white_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_inset_button_white_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_inset_button_white(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_inset_button_white_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_inset_button_white(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_inset_button_white_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Small Button
//

void init_style_small_button_MAIN_DEFAULT(lv_style_t *style) {
    init_style_large_button_MAIN_DEFAULT(style);
    
    lv_style_set_radius(style, 16);
    lv_style_set_border_width(style, 2);
};

lv_style_t *get_style_small_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_small_button_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_small_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_small_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_small_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_small_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Inset Button
//

void init_style_inset_button_MAIN_DEFAULT(lv_style_t *style) {
    init_style_large_button_MAIN_DEFAULT(style);
    
    lv_style_set_border_width(style, 2);
    lv_style_set_radius(style, 16);
};

lv_style_t *get_style_inset_button_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_inset_button_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_inset_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_inset_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_inset_button(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_inset_button_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Small Title
//

void init_style_small_title_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_barlow_condensed_medium);
    lv_style_set_align(style, LV_ALIGN_CENTER);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
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
// Style: Small Title Black
//

void init_style_small_title_black_MAIN_DEFAULT(lv_style_t *style) {
    init_style_small_title_MAIN_DEFAULT(style);
    
    lv_style_set_align(style, LV_ALIGN_CENTER);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_small_title_black_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_small_title_black_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_small_title_black(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_small_title_black_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_small_title_black(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_small_title_black_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
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
// Style: Default Screen
//

void init_style_default_screen_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_default_screen_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_default_screen_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_default_screen(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_default_screen_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_default_screen(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_default_screen_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: XL_WatchFace
//

void init_style_xl_watch_face_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
    lv_style_set_text_font(style, &ui_font_barlow_condensed_semibold_extra_large);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_xl_watch_face_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_xl_watch_face_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_xl_watch_face(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_xl_watch_face_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_xl_watch_face(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_xl_watch_face_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: XXL Pixel Watch Face
//

void init_style_xxl_pixel_watch_face_MAIN_DEFAULT(lv_style_t *style) {
    init_style_xl_watch_face_MAIN_DEFAULT(style);
    
    lv_style_set_text_font(style, &ui_font_doto_medium_xxl);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_RIGHT);
};

lv_style_t *get_style_xxl_pixel_watch_face_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_xxl_pixel_watch_face_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_xxl_pixel_watch_face(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_xxl_pixel_watch_face_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_xxl_pixel_watch_face(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_xxl_pixel_watch_face_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Large Doto Title
//

void init_style_large_doto_title_MAIN_DEFAULT(lv_style_t *style) {
    init_style_xl_watch_face_MAIN_DEFAULT(style);
    
    lv_style_set_text_font(style, &ui_font_doto_medium_l);
};

lv_style_t *get_style_large_doto_title_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_large_doto_title_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_large_doto_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_large_doto_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_large_doto_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_large_doto_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: XL_Title
//

void init_style_xl_title_MAIN_DEFAULT(lv_style_t *style) {
    init_style_xl_watch_face_MAIN_DEFAULT(style);
    
    lv_style_set_text_font(style, &ui_font_barlow_condensed_semibold_large);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
};

lv_style_t *get_style_xl_title_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_xl_title_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_xl_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_xl_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_xl_title(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_xl_title_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: XL_Title_Black
//

void init_style_xl_title_black_MAIN_DEFAULT(lv_style_t *style) {
    init_style_xl_title_MAIN_DEFAULT(style);
    
    lv_style_set_align(style, LV_ALIGN_CENTER);
    lv_style_set_text_color(style, lv_color_hex(0xff000000));
};

lv_style_t *get_style_xl_title_black_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_xl_title_black_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_xl_title_black(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_xl_title_black_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_xl_title_black(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_xl_title_black_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Default Container
//

void init_style_default_container_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_radius(style, 10);
    lv_style_set_border_color(style, lv_color_hex(0xffffffff));
    lv_style_set_border_width(style, 2);
};

lv_style_t *get_style_default_container_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_default_container_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_default_container(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_default_container_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_default_container(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_default_container_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Chart
//

void init_style_chart_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
    lv_style_set_radius(style, 22);
    lv_style_set_line_width(style, 1);
    lv_style_set_line_opa(style, 0);
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(0xffffffff));
    lv_style_set_border_width(style, 4);
    lv_style_set_text_font(style, &ui_font_barlow_condensed_medium);
};

lv_style_t *get_style_chart_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_chart_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_chart(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_chart_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_chart(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_chart_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Dropdown
//

void init_style_dropdown_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_border_color(style, lv_color_hex(0xffffffff));
    lv_style_set_radius(style, 16);
    lv_style_set_text_font(style, &ui_font_barlow_condensed_medium);
    lv_style_set_text_color(style, lv_color_hex(0xffffffff));
};

lv_style_t *get_style_dropdown_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_dropdown_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_dropdown(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_dropdown_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_dropdown(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_dropdown_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Black_Image
//

void init_style_black_image_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_image_recolor(style, lv_color_hex(0xff000000));
    lv_style_set_image_recolor_opa(style, 255);
};

lv_style_t *get_style_black_image_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_black_image_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_black_image(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_black_image_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_black_image(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_black_image_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: White_Image
//

void init_style_white_image_MAIN_DEFAULT(lv_style_t *style) {
    init_style_black_image_MAIN_DEFAULT(style);
    
    lv_style_set_image_recolor_opa(style, 0);
};

lv_style_t *get_style_white_image_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_white_image_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_white_image(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_white_image_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_white_image(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_white_image_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Arc
//

void init_style_arc_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_arc_width(style, 2);
    lv_style_set_arc_color(style, lv_color_hex(0xffffffff));
    lv_style_set_bg_color(style, lv_color_hex(0xff000000));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_radius(style, 255);
};

lv_style_t *get_style_arc_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_arc_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_arc_width(style, 7);
    lv_style_set_arc_color(style, lv_color_hex(0xffffffff));
    lv_style_set_arc_rounded(style, true);
};

lv_style_t *get_style_arc_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_INDICATOR_DEFAULT(style);
    }
    return style;
};

void init_style_arc_KNOB_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
};

lv_style_t *get_style_arc_KNOB_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_KNOB_DEFAULT(style);
    }
    return style;
};

void add_style_arc(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_arc_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_arc_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_arc_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
};

void remove_style_arc(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_arc_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_arc_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_arc_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_large_button,
        add_style_large_button_white,
        add_style_inset_button_white,
        add_style_small_button,
        add_style_inset_button,
        add_style_small_title,
        add_style_small_title_black,
        add_style_large_title,
        add_style_default_screen,
        add_style_xl_watch_face,
        add_style_xxl_pixel_watch_face,
        add_style_large_doto_title,
        add_style_xl_title,
        add_style_xl_title_black,
        add_style_default_container,
        add_style_chart,
        add_style_dropdown,
        add_style_black_image,
        add_style_white_image,
        add_style_arc,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_large_button,
        remove_style_large_button_white,
        remove_style_inset_button_white,
        remove_style_small_button,
        remove_style_inset_button,
        remove_style_small_title,
        remove_style_small_title_black,
        remove_style_large_title,
        remove_style_default_screen,
        remove_style_xl_watch_face,
        remove_style_xxl_pixel_watch_face,
        remove_style_large_doto_title,
        remove_style_xl_title,
        remove_style_xl_title_black,
        remove_style_default_container,
        remove_style_chart,
        remove_style_dropdown,
        remove_style_black_image,
        remove_style_white_image,
        remove_style_arc,
    };
    remove_style_funcs[styleIndex](obj);
}

