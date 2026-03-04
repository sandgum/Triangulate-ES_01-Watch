#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_rocket_launch;
extern const lv_img_dsc_t img_very_smiley;
extern const lv_img_dsc_t img_excited_smiley;
extern const lv_img_dsc_t img_steps;
extern const lv_img_dsc_t img_heart_rate;
extern const lv_img_dsc_t img_altitude;
extern const lv_img_dsc_t img_bolt;
extern const lv_img_dsc_t img_earth;
extern const lv_img_dsc_t img_back_arrow;
extern const lv_img_dsc_t img_back_arrow_44p;
extern const lv_img_dsc_t img_running;
extern const lv_img_dsc_t img_workout;
extern const lv_img_dsc_t img_weather_cloudy;
extern const lv_img_dsc_t img_notifications;
extern const lv_img_dsc_t img_clock;
extern const lv_img_dsc_t img_stopwatch;
extern const lv_img_dsc_t img_settings;
extern const lv_img_dsc_t img_plus;
extern const lv_img_dsc_t img_stats_24p;
extern const lv_img_dsc_t img_minus;
extern const lv_img_dsc_t img_pause;
extern const lv_img_dsc_t img_play;
extern const lv_img_dsc_t img_flame_50p;
extern const lv_img_dsc_t img_bin;
extern const lv_img_dsc_t img_speed;
extern const lv_img_dsc_t img_flame_32p;
extern const lv_img_dsc_t img_compress;
extern const lv_img_dsc_t img_weather_sunny;
extern const lv_img_dsc_t img_road;
extern const lv_img_dsc_t img_blood_oxygen;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[30];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/