/**
 * @file helloworld_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "helloworld_gen.h"
#include "ES_01_Firmware_LVGL_UI.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * helloworld_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "helloworld_#");

    lv_obj_t * lv_button_0 = lv_button_create(lv_obj_0);
    lv_obj_set_align(lv_button_0, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(lv_button_0, lv_color_hex(0xFFFFFF), 0);
    lv_obj_set_style_border_color(lv_button_0, lv_color_hex(0x000000), 0);
    lv_obj_set_style_border_width(lv_button_0, 3, 0);
    lv_obj_set_style_radius(lv_button_0, 20, 0);
    lv_obj_set_width(lv_button_0, 174);
    lv_obj_set_height(lv_button_0, 78);
    lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
    lv_label_set_text(lv_label_0, "Hello World!");
    lv_obj_set_style_text_font(lv_label_0, Doto_Sans_Bold, 0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0x000000), 0);
    lv_obj_set_y(lv_label_0, -6);
    lv_obj_set_x(lv_label_0, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_button_0);
    lv_label_set_text(lv_label_1, "This is a caption");
    lv_obj_set_style_text_font(lv_label_1, Smooch_Sans_Semibold, 0);
    lv_obj_set_style_text_color(lv_label_1, lv_color_hex(0x000000), 0);
    lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
    lv_obj_set_y(lv_label_1, 15);
    lv_obj_set_x(lv_label_1, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

