/*******************************************************************************
 * Size: 15 px
 * Bpp: 1
 * Opts: --bpp 1 --size 15 --no-compress --font ..\Assets\Fonts\Barlow_Condensed\BarlowCondensed-Medium.ttf --range 32-127 --format lvgl
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#ifndef UI_FONT_BARLOW_CONDENSED_MEDIUM
#define UI_FONT_BARLOW_CONDENSED_MEDIUM 1
#endif

#if UI_FONT_BARLOW_CONDENSED_MEDIUM

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xaa, 0xa8, 0x3c,

    /* U+0022 "\"" */
    0xb6, 0x80,

    /* U+0023 "#" */
    0x36, 0x36, 0x7f, 0x24, 0x24, 0x24, 0xfe, 0x64,
    0x6c, 0x6c,

    /* U+0024 "$" */
    0x23, 0xa3, 0x18, 0x61, 0xc3, 0xc, 0x62, 0xe2,
    0x0,

    /* U+0025 "%" */
    0x61, 0x24, 0x89, 0x22, 0x50, 0x64, 0x2, 0x0,
    0xb8, 0x51, 0x14, 0x49, 0x12, 0x38,

    /* U+0026 "&" */
    0x30, 0x91, 0x22, 0x47, 0xe, 0x34, 0x4f, 0x8d,
    0x19, 0xd8,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x5a, 0xaa, 0xab, 0x40,

    /* U+0029 ")" */
    0xad, 0x55, 0x5e, 0x80,

    /* U+002A "*" */
    0x27, 0xc9, 0xf2, 0x0,

    /* U+002B "+" */
    0x20, 0x82, 0x3f, 0x20, 0x80,

    /* U+002C "," */
    0xf0,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x18, 0x84, 0x63, 0x11, 0x8c, 0x42, 0x30,

    /* U+0030 "0" */
    0x74, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x5c,

    /* U+0031 "1" */
    0x7c, 0x92, 0x49, 0x24, 0x80,

    /* U+0032 "2" */
    0x74, 0x62, 0x11, 0x88, 0xc4, 0x46, 0x3e,

    /* U+0033 "3" */
    0xf8, 0xc4, 0x63, 0x4, 0x21, 0xce, 0x5c,

    /* U+0034 "4" */
    0x30, 0x86, 0x18, 0x41, 0x2c, 0xbf, 0x8, 0x20,
    0x80,

    /* U+0035 "5" */
    0xf4, 0x21, 0xf, 0x64, 0x21, 0x8c, 0x5c,

    /* U+0036 "6" */
    0x74, 0x63, 0xf, 0x46, 0x31, 0x8c, 0x5c,

    /* U+0037 "7" */
    0xfc, 0x46, 0x31, 0x18, 0xc6, 0x23, 0x18,

    /* U+0038 "8" */
    0x74, 0x63, 0x18, 0xba, 0x31, 0x8c, 0x5c,

    /* U+0039 "9" */
    0x74, 0x63, 0x18, 0xc5, 0xe1, 0x8c, 0x5c,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0xf0, 0xe, 0x80,

    /* U+003C "<" */
    0x4, 0x77, 0x30, 0xe0, 0xe0, 0xc0,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0x83, 0x83, 0x83, 0x1b, 0x88, 0x0,

    /* U+003F "?" */
    0x74, 0x62, 0x11, 0x98, 0x84, 0x1, 0x8,

    /* U+0040 "@" */
    0x1f, 0xc, 0x64, 0x5, 0x39, 0x92, 0x64, 0x99,
    0x6e, 0x7e, 0xc0, 0x18, 0x83, 0xc0,

    /* U+0041 "A" */
    0x30, 0xc3, 0x1c, 0x59, 0x24, 0x92, 0xff, 0x38,
    0xc0,

    /* U+0042 "B" */
    0xf4, 0xe3, 0x19, 0xfa, 0x71, 0x8c, 0xfc,

    /* U+0043 "C" */
    0x74, 0x63, 0x8, 0x42, 0x10, 0x8c, 0x5c,

    /* U+0044 "D" */
    0xf4, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x7c,

    /* U+0045 "E" */
    0xfc, 0x21, 0x8, 0x72, 0x10, 0x84, 0x3e,

    /* U+0046 "F" */
    0xfc, 0x21, 0x8, 0x72, 0x10, 0x84, 0x20,

    /* U+0047 "G" */
    0x74, 0x63, 0x8, 0x4e, 0x31, 0x8c, 0x5c,

    /* U+0048 "H" */
    0x8c, 0x63, 0x18, 0xfe, 0x31, 0x8c, 0x62,

    /* U+0049 "I" */
    0xff, 0xe0,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x84, 0x31, 0x8c, 0x5c,

    /* U+004B "K" */
    0x9c, 0xad, 0x4e, 0x72, 0xd6, 0x94, 0xe2,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x42, 0x10, 0x84, 0x3e,

    /* U+004D "M" */
    0x8f, 0x3f, 0xff, 0xb6, 0x18, 0x61, 0x86, 0x18,
    0x40,

    /* U+004E "N" */
    0x8e, 0x73, 0x9e, 0xd6, 0xf3, 0x9c, 0xe2,

    /* U+004F "O" */
    0x74, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x5c,

    /* U+0050 "P" */
    0xf4, 0xe3, 0x19, 0xfa, 0x10, 0x84, 0x20,

    /* U+0051 "Q" */
    0x74, 0x63, 0x18, 0xc6, 0x31, 0x8b, 0x88, 0x40,

    /* U+0052 "R" */
    0xf2, 0x68, 0xa2, 0x9b, 0xc9, 0x24, 0x9a, 0x28,
    0x80,

    /* U+0053 "S" */
    0x74, 0x63, 0xc, 0x38, 0x61, 0x8c, 0x5c,

    /* U+0054 "T" */
    0xfc, 0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x82,
    0x0,

    /* U+0055 "U" */
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c, 0x5c,

    /* U+0056 "V" */
    0xcf, 0x3c, 0x92, 0x49, 0x67, 0x9c, 0x30, 0xc3,
    0x0,

    /* U+0057 "W" */
    0xc9, 0xe4, 0xf7, 0x6a, 0xa5, 0x52, 0xa9, 0xdc,
    0xee, 0x36, 0x1b, 0x8, 0x80,

    /* U+0058 "X" */
    0x45, 0x36, 0x8a, 0x38, 0x43, 0x8a, 0x69, 0x34,
    0x40,

    /* U+0059 "Y" */
    0xde, 0xd4, 0xa7, 0x10, 0x84, 0x21, 0x8,

    /* U+005A "Z" */
    0xf8, 0xc4, 0x63, 0x11, 0x88, 0x46, 0x3e,

    /* U+005B "[" */
    0xea, 0xaa, 0xaa, 0xb0,

    /* U+005C "\\" */
    0x8c, 0xc4, 0x46, 0x62, 0x23, 0x10,

    /* U+005D "]" */
    0xd5, 0x55, 0x55, 0x70,

    /* U+005E "^" */
    0x30, 0xc3, 0x12, 0x49, 0x20,

    /* U+005F "_" */
    0xf8,

    /* U+0060 "`" */
    0x48,

    /* U+0061 "a" */
    0x76, 0x42, 0xf8, 0xc6, 0x2f,

    /* U+0062 "b" */
    0x84, 0x21, 0xe8, 0xc6, 0x31, 0x8c, 0x7c,

    /* U+0063 "c" */
    0x74, 0x63, 0x8, 0x46, 0x2e,

    /* U+0064 "d" */
    0x8, 0x42, 0xf8, 0xc6, 0x31, 0x8c, 0x5e,

    /* U+0065 "e" */
    0x74, 0x63, 0xf8, 0x42, 0x6e,

    /* U+0066 "f" */
    0x69, 0x74, 0x92, 0x49, 0x0,

    /* U+0067 "g" */
    0x7c, 0x63, 0x18, 0xc6, 0x2f, 0x8, 0xdc,

    /* U+0068 "h" */
    0x84, 0x21, 0xe8, 0xc6, 0x31, 0x8c, 0x62,

    /* U+0069 "i" */
    0xf1, 0x55, 0x54,

    /* U+006A "j" */
    0x6c, 0x24, 0x92, 0x49, 0x25, 0x0,

    /* U+006B "k" */
    0x84, 0x21, 0x2b, 0x73, 0x9e, 0x94, 0xa6,

    /* U+006C "l" */
    0xff, 0xe0,

    /* U+006D "m" */
    0xff, 0x44, 0x62, 0x31, 0x18, 0x8c, 0x46, 0x23,
    0x11,

    /* U+006E "n" */
    0xf4, 0x63, 0x18, 0xc6, 0x31,

    /* U+006F "o" */
    0x74, 0x63, 0x18, 0xc6, 0x2e,

    /* U+0070 "p" */
    0xf4, 0x63, 0x18, 0xc6, 0x3e, 0x84, 0x20,

    /* U+0071 "q" */
    0x7c, 0x63, 0x18, 0xc6, 0x2f, 0x8, 0x42,

    /* U+0072 "r" */
    0xf2, 0x49, 0x24,

    /* U+0073 "s" */
    0x74, 0xe1, 0xc3, 0x87, 0x2e,

    /* U+0074 "t" */
    0x4b, 0xa4, 0x92, 0x4c,

    /* U+0075 "u" */
    0x8c, 0x63, 0x18, 0xc6, 0x2f,

    /* U+0076 "v" */
    0xcd, 0x24, 0x9e, 0x78, 0xc3, 0xc,

    /* U+0077 "w" */
    0x99, 0xdb, 0xdb, 0x5a, 0x5a, 0x66, 0x66, 0x24,

    /* U+0078 "x" */
    0xcd, 0x67, 0x8c, 0x31, 0xe4, 0xb3,

    /* U+0079 "y" */
    0x9c, 0xf4, 0xa5, 0x39, 0x8c, 0x23, 0x30,

    /* U+007A "z" */
    0xf8, 0xcc, 0x66, 0x33, 0x1f,

    /* U+007B "{" */
    0x69, 0x24, 0xb6, 0x49, 0x24, 0xc0,

    /* U+007C "|" */
    0xff, 0xf8,

    /* U+007D "}" */
    0xc4, 0x44, 0x44, 0x66, 0x44, 0x44, 0x4c,

    /* U+007E "~" */
    0x70, 0x18
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 48, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 63, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 66, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 6, .adv_w = 144, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 102, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 25, .adv_w = 186, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 135, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 49, .adv_w = 33, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 50, .adv_w = 61, .box_w = 2, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 54, .adv_w = 61, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 58, .adv_w = 87, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 62, .adv_w = 106, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 67, .adv_w = 45, .box_w = 1, .box_h = 4, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 68, .adv_w = 77, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 69, .adv_w = 48, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 87, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 107, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 64, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 100, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 100, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 106, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 101, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 101, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 91, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 103, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 140, .adv_w = 99, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 147, .adv_w = 56, .box_w = 2, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 50, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 152, .adv_w = 106, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 158, .adv_w = 106, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 161, .adv_w = 106, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 167, .adv_w = 95, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 182, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 188, .adv_w = 105, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 197, .adv_w = 109, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 108, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 113, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 104, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 98, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 110, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 114, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 246, .adv_w = 53, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 104, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 112, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 98, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 127, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 120, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 111, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 292, .adv_w = 108, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 108, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 307, .adv_w = 109, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 102, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 105, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 114, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 110, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 155, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 361, .adv_w = 108, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 106, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 377, .adv_w = 96, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 76, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 388, .adv_w = 87, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 76, .box_w = 2, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 398, .adv_w = 97, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 403, .adv_w = 94, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 47, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 9},
    {.bitmap_index = 405, .adv_w = 102, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 103, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 417, .adv_w = 99, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 103, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 100, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 68, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 102, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 446, .adv_w = 104, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 453, .adv_w = 51, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 456, .adv_w = 49, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 462, .adv_w = 101, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 46, .box_w = 1, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 158, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 104, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 102, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 490, .adv_w = 104, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 497, .adv_w = 104, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 504, .adv_w = 73, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 93, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 512, .adv_w = 66, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 516, .adv_w = 104, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 138, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 93, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 548, .adv_w = 88, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 553, .adv_w = 72, .box_w = 3, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 559, .adv_w = 38, .box_w = 1, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 561, .adv_w = 72, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 568, .adv_w = 113, .box_w = 7, .box_h = 2, .ofs_x = 0, .ofs_y = 4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 0,
    1, 0, 0, 0, 2, 3, 4, 3,
    5, 0, 6, 7, 8, 9, 10, 11,
    12, 13, 13, 0, 0, 0, 0, 0,
    0, 0, 14, 15, 16, 15, 17, 18,
    16, 19, 0, 20, 21, 22, 0, 0,
    16, 23, 24, 25, 26, 27, 20, 28,
    28, 29, 30, 0, 0, 0, 0, 0,
    0, 0, 31, 32, 33, 0, 34, 35,
    36, 32, 37, 0, 38, 0, 32, 32,
    4, 32, 36, 39, 40, 41, 0, 42,
    42, 43, 42, 44, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 1, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 2, 3, 2,
    4, 5, 6, 7, 0, 0, 0, 0,
    8, 0, 0, 0, 0, 0, 0, 0,
    9, 0, 10, 11, 12, 11, 11, 11,
    12, 0, 0, 13, 14, 15, 0, 11,
    12, 11, 12, 16, 17, 18, 0, 19,
    19, 20, 21, 0, 0, 0, 0, 0,
    0, 0, 22, 0, 3, 3, 3, 23,
    24, 0, 25, 26, 0, 0, 27, 27,
    3, 27, 24, 27, 28, 23, 29, 30,
    30, 31, 30, 32, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 0, -6, 0, 0, 0, 0, 0,
    0, -9, 0, 0, -10, 0, 0, 0,
    0, 0, 0, 0, 0, -3, 1, 0,
    0, 0, -1, -5, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -5,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -9, 0, 0, -7,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -1, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, -3, 0,
    0, 0, -12, 0, 0, 0, 0, 0,
    0, -16, -3, -7, 0, -4, -5, -3,
    -3, 0, 0, 0, 0, -12, 0, -3,
    0, 0, -2, -5, -3, -4, 0, -3,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -8, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -12, 0, -12,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -12, 0, -17, 0, -1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -7, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -9, 0, 0, 2, 0, 0, 0, 0,
    0, 7, 0, -3, 1, 0, 0, 0,
    -5, -14, -15, 1, -10, 0, -1, 0,
    0, 0, 0, -1, -2, -6, 4, 0,
    0, -3, 0, -1, 0, 0, 0, 0,
    0, -5, -1, 0, 0, -1, 0, 0,
    0, 0, -5, -4, -5, 0, 0, 0,
    0, 0, 0, -3, 0, -1, 0, 0,
    0, -1, -2, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -2, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, -1, 1, 0, 0, 0, 0,
    0, 5, 0, 0, 4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -1, 0, 0, 0, 0,
    0, 0, -7, -10, 0, 0, 0, 0,
    0, -8, 0, 0, -3, 0, 0, 0,
    0, 0, 0, 0, 0, -4, -1, -7,
    0, 0, -7, -6, -3, -3, -3, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, 0, -4, 0, 0, 0, 0,
    0, -2, -3, -1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 3, 0, 3, 0, 0, 0, 0,
    0, 4, 0, -3, 0, 0, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 3, 0, 3, 0, 0, 0, 0,
    -2, 8, 0, 0, 0, 0, 0, 0,
    -1, -17, 0, 0, -7, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -8, 0, -12, 0, 0, 0, 0,
    0, -7, 0, 0, -8, 0, 0, 0,
    0, 0, -2, -3, -3, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, -2, 0, 0, 0, 0, 0,
    2, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -2, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, 3, 0, 0, 0, 0,
    0, 2, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, 0, 0, 0, 0,
    0, -3, -2, -6, -5, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, -11, -14, -4, 0, 0, 0, 0,
    4, -10, 0, -6, 0, 0, -1, 0,
    0, 0, 0, 0, 0, -7, -2, -12,
    0, 0, -6, -9, -3, -7, -4, -4,
    0, -7, -10, -9, 0, 0, 0, 0,
    0, -14, 0, -3, -5, 0, 0, -1,
    -3, 0, 0, 0, 0, -5, -2, -8,
    0, 0, -3, -8, -1, -2, -3, -2,
    0, 1, -2, 0, 0, 0, 0, 0,
    0, 1, 0, -2, -1, 0, 0, 0,
    -6, 0, 0, 0, 0, 0, -2, -2,
    0, 0, 0, -2, -2, -8, 0, 0,
    0, -15, -12, -9, 0, 0, 0, 0,
    0, -14, -4, -4, -9, 0, -1, -1,
    -4, 0, 0, 0, 0, 0, -4, -12,
    0, 0, -7, -1, -5, -6, -3, -3,
    -4, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    -2, -3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, -2, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -1, 0,
    0, 0, 0, 0, 0, -3, -2, 0,
    -2, -1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, -1, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, -3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, 0, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -3,
    0, 0, 0, -3, 0, 0, 0, 0,
    1, 0, -1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, -2,
    0, 0, 0, 0, 0, 3, 0, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -5, 0, -3, -2, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -3, -2, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, -4,
    0, 0, 0, -2, 0, 3, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 44,
    .right_class_cnt     = 32,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_barlow_condensed_medium = {
#else
lv_font_t ui_font_barlow_condensed_medium = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_BARLOW_CONDENSED_MEDIUM*/

