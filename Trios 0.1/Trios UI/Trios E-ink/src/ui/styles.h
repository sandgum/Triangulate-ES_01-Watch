#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: Large Button
lv_style_t *get_style_large_button_MAIN_DEFAULT();
void add_style_large_button(lv_obj_t *obj);
void remove_style_large_button(lv_obj_t *obj);

// Style: Large Button white
lv_style_t *get_style_large_button_white_MAIN_DEFAULT();
void add_style_large_button_white(lv_obj_t *obj);
void remove_style_large_button_white(lv_obj_t *obj);

// Style: Inset Button White
lv_style_t *get_style_inset_button_white_MAIN_DEFAULT();
void add_style_inset_button_white(lv_obj_t *obj);
void remove_style_inset_button_white(lv_obj_t *obj);

// Style: Small Button
lv_style_t *get_style_small_button_MAIN_DEFAULT();
void add_style_small_button(lv_obj_t *obj);
void remove_style_small_button(lv_obj_t *obj);

// Style: Inset Button
lv_style_t *get_style_inset_button_MAIN_DEFAULT();
void add_style_inset_button(lv_obj_t *obj);
void remove_style_inset_button(lv_obj_t *obj);

// Style: Small Title
lv_style_t *get_style_small_title_MAIN_DEFAULT();
void add_style_small_title(lv_obj_t *obj);
void remove_style_small_title(lv_obj_t *obj);

// Style: Small Title Black
lv_style_t *get_style_small_title_black_MAIN_DEFAULT();
void add_style_small_title_black(lv_obj_t *obj);
void remove_style_small_title_black(lv_obj_t *obj);

// Style: Large Title
lv_style_t *get_style_large_title_MAIN_DEFAULT();
void add_style_large_title(lv_obj_t *obj);
void remove_style_large_title(lv_obj_t *obj);

// Style: Default Screen
lv_style_t *get_style_default_screen_MAIN_DEFAULT();
void add_style_default_screen(lv_obj_t *obj);
void remove_style_default_screen(lv_obj_t *obj);

// Style: XL_WatchFace
lv_style_t *get_style_xl_watch_face_MAIN_DEFAULT();
void add_style_xl_watch_face(lv_obj_t *obj);
void remove_style_xl_watch_face(lv_obj_t *obj);

// Style: XXL Pixel Watch Face
lv_style_t *get_style_xxl_pixel_watch_face_MAIN_DEFAULT();
void add_style_xxl_pixel_watch_face(lv_obj_t *obj);
void remove_style_xxl_pixel_watch_face(lv_obj_t *obj);

// Style: Large Doto Title
lv_style_t *get_style_large_doto_title_MAIN_DEFAULT();
void add_style_large_doto_title(lv_obj_t *obj);
void remove_style_large_doto_title(lv_obj_t *obj);

// Style: XL_Title
lv_style_t *get_style_xl_title_MAIN_DEFAULT();
void add_style_xl_title(lv_obj_t *obj);
void remove_style_xl_title(lv_obj_t *obj);

// Style: XL_Title_Black
lv_style_t *get_style_xl_title_black_MAIN_DEFAULT();
void add_style_xl_title_black(lv_obj_t *obj);
void remove_style_xl_title_black(lv_obj_t *obj);

// Style: Default Container
lv_style_t *get_style_default_container_MAIN_DEFAULT();
void add_style_default_container(lv_obj_t *obj);
void remove_style_default_container(lv_obj_t *obj);

// Style: Chart
lv_style_t *get_style_chart_MAIN_DEFAULT();
void add_style_chart(lv_obj_t *obj);
void remove_style_chart(lv_obj_t *obj);

// Style: Dropdown
lv_style_t *get_style_dropdown_MAIN_DEFAULT();
void add_style_dropdown(lv_obj_t *obj);
void remove_style_dropdown(lv_obj_t *obj);

// Style: Black_Image
lv_style_t *get_style_black_image_MAIN_DEFAULT();
void add_style_black_image(lv_obj_t *obj);
void remove_style_black_image(lv_obj_t *obj);

// Style: White_Image
lv_style_t *get_style_white_image_MAIN_DEFAULT();
void add_style_white_image(lv_obj_t *obj);
void remove_style_white_image(lv_obj_t *obj);

// Style: Arc
lv_style_t *get_style_arc_MAIN_DEFAULT();
lv_style_t *get_style_arc_INDICATOR_DEFAULT();
lv_style_t *get_style_arc_KNOB_DEFAULT();
void add_style_arc(lv_obj_t *obj);
void remove_style_arc(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/