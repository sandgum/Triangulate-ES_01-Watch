/**
 * @file ES_01_Firmware_LVGL_UI_gen.h
 */

#ifndef ES_01_FIRMWARE_LVGL_UI_GEN_H
#define ES_01_FIRMWARE_LVGL_UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * Doto_Sans_Bold;

extern lv_font_t * Doto_Sans_Light;

extern lv_font_t * Doto_Sans_Thin;

extern lv_font_t * Smooch_Sans_Light;

extern lv_font_t * Smooch_Sans_Semibold;

extern lv_font_t * Smooch_Sans_Thin;

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void ES_01_Firmware_LVGL_UI_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "screens/helloworld/helloworld_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ES_01_FIRMWARE_LVGL_UI_GEN_H*/