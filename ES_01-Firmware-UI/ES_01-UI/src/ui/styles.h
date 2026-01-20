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

// Style: Small Title
lv_style_t *get_style_small_title_MAIN_DEFAULT();
void add_style_small_title(lv_obj_t *obj);
void remove_style_small_title(lv_obj_t *obj);

// Style: Large Title
lv_style_t *get_style_large_title_MAIN_DEFAULT();
void add_style_large_title(lv_obj_t *obj);
void remove_style_large_title(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/