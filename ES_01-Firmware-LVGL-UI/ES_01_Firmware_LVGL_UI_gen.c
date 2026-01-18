/**
 * @file ES_01_Firmware_LVGL_UI_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "ES_01_Firmware_LVGL_UI_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * Doto_Sans_Bold;
extern uint8_t Doto_Bold_ttf_data[];
extern size_t Doto_Bold_ttf_data_size;
lv_font_t * Doto_Sans_Light;
extern uint8_t Doto_Light_ttf_data[];
extern size_t Doto_Light_ttf_data_size;
lv_font_t * Doto_Sans_Thin;
extern uint8_t Doto_Thin_ttf_data[];
extern size_t Doto_Thin_ttf_data_size;
lv_font_t * Smooch_Sans_Light;
extern uint8_t SmoochSans_Light_ttf_data[];
extern size_t SmoochSans_Light_ttf_data_size;
lv_font_t * Smooch_Sans_Semibold;
extern uint8_t SmoochSans_Semibold_ttf_data[];
extern size_t SmoochSans_Semibold_ttf_data_size;
lv_font_t * Smooch_Sans_Thin;
extern uint8_t SmoochSans_Thin_ttf_data[];
extern size_t SmoochSans_Thin_ttf_data_size;

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void ES_01_Firmware_LVGL_UI_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Fonts
     *----------------*/

    /* create tiny ttf font 'Doto_Sans_Bold' from C array */
    Doto_Sans_Bold = lv_tiny_ttf_create_data(Doto_Bold_ttf_data, Doto_Bold_ttf_data_size, 22);
    /* create tiny ttf font 'Doto_Sans_Light' from C array */
    Doto_Sans_Light = lv_tiny_ttf_create_data(Doto_Light_ttf_data, Doto_Light_ttf_data_size, 22);
    /* create tiny ttf font 'Doto_Sans_Thin' from C array */
    Doto_Sans_Thin = lv_tiny_ttf_create_data(Doto_Thin_ttf_data, Doto_Thin_ttf_data_size, 22);
    /* create tiny ttf font 'Smooch_Sans_Light' from C array */
    Smooch_Sans_Light = lv_tiny_ttf_create_data(SmoochSans_Light_ttf_data, SmoochSans_Light_ttf_data_size, 16);
    /* create tiny ttf font 'Smooch_Sans_Semibold' from C array */
    Smooch_Sans_Semibold = lv_tiny_ttf_create_data(SmoochSans_Semibold_ttf_data, SmoochSans_Semibold_ttf_data_size, 16);
    /* create tiny ttf font 'Smooch_Sans_Thin' from C array */
    Smooch_Sans_Thin = lv_tiny_ttf_create_data(SmoochSans_Thin_ttf_data, SmoochSans_Thin_ttf_data_size, 16);


    /*----------------
     * Images
     *----------------*/
    /*----------------
     * Subjects
     *----------------*/
    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "Doto_Sans_Bold", Doto_Sans_Bold);
    lv_xml_register_font(NULL, "Doto_Sans_Light", Doto_Sans_Light);
    lv_xml_register_font(NULL, "Doto_Sans_Thin", Doto_Sans_Thin);
    lv_xml_register_font(NULL, "Smooch_Sans_Light", Smooch_Sans_Light);
    lv_xml_register_font(NULL, "Smooch_Sans_Semibold", Smooch_Sans_Semibold);
    lv_xml_register_font(NULL, "Smooch_Sans_Thin", Smooch_Sans_Thin);

    /* Register subjects */

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/