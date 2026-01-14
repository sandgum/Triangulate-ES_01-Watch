/**
 * @file ES_01_Firmware_LVGL_UI.h
 */

#ifndef ES_01_FIRMWARE_LVGL_UI_H
#define ES_01_FIRMWARE_LVGL_UI_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "ES_01_Firmware_LVGL_UI_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the component library
 */
void ES_01_Firmware_LVGL_UI_init(const char * asset_path);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*ES_01_FIRMWARE_LVGL_UI_H*/