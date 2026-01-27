#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *launch_screen;
    lv_obj_t *watch_face;
    lv_obj_t *main_menu_page_1;
    lv_obj_t *main_menu_page_2;
    lv_obj_t *new_workout_page;
    lv_obj_t *workout_stats_page;
    lv_obj_t *active_workout_page;
    lv_obj_t *end_workout_confirmation_page;
    lv_obj_t *after_workout_summary_page;
    lv_obj_t *altitude_stats_page;
    lv_obj_t *pressure_stats_page;
    lv_obj_t *activity_today_page;
    lv_obj_t *activity_stats_page;
    lv_obj_t *heart_rate_stats_page;
    lv_obj_t *blood_oxygen_page;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj12;
    lv_obj_t *obj13;
    lv_obj_t *obj14;
    lv_obj_t *obj15;
    lv_obj_t *obj16;
    lv_obj_t *obj17;
    lv_obj_t *obj18;
    lv_obj_t *obj19;
    lv_obj_t *obj20;
    lv_obj_t *obj21;
    lv_obj_t *obj22;
    lv_obj_t *obj23;
    lv_obj_t *obj24;
    lv_obj_t *obj25;
    lv_obj_t *obj26;
    lv_obj_t *obj27;
    lv_obj_t *obj28;
    lv_obj_t *obj29;
    lv_obj_t *obj30;
    lv_obj_t *obj31;
    lv_obj_t *obj32;
    lv_obj_t *obj33;
    lv_obj_t *obj34;
    lv_obj_t *obj35;
    lv_obj_t *obj36;
    lv_obj_t *obj37;
    lv_obj_t *obj38;
    lv_obj_t *obj39;
    lv_obj_t *obj40;
    lv_obj_t *obj41;
    lv_obj_t *obj42;
    lv_obj_t *obj43;
    lv_obj_t *obj44;
    lv_obj_t *obj45;
    lv_obj_t *obj46;
    lv_obj_t *obj47;
    lv_obj_t *obj48;
    lv_obj_t *obj49;
    lv_obj_t *obj50;
    lv_obj_t *obj51;
    lv_obj_t *obj52;
    lv_obj_t *obj53;
    lv_obj_t *obj54;
    lv_obj_t *obj55;
    lv_obj_t *obj56;
    lv_obj_t *obj57;
    lv_obj_t *obj58;
    lv_obj_t *obj59;
    lv_obj_t *obj60;
    lv_obj_t *obj61;
    lv_obj_t *obj62;
    lv_obj_t *obj63;
    lv_obj_t *obj64;
    lv_obj_t *obj65;
    lv_obj_t *obj66;
    lv_obj_t *obj67;
    lv_obj_t *obj68;
    lv_obj_t *obj69;
    lv_obj_t *obj70;
    lv_obj_t *obj71;
    lv_obj_t *obj72;
    lv_obj_t *obj73;
    lv_obj_t *obj74;
    lv_obj_t *obj75;
    lv_obj_t *obj76;
    lv_obj_t *obj77;
    lv_obj_t *obj78;
    lv_obj_t *obj79;
    lv_obj_t *obj80;
    lv_obj_t *obj81;
    lv_obj_t *obj82;
    lv_obj_t *obj83;
    lv_obj_t *obj84;
    lv_obj_t *obj85;
    lv_obj_t *obj86;
    lv_obj_t *obj87;
    lv_obj_t *obj88;
    lv_obj_t *obj89;
    lv_obj_t *obj90;
    lv_obj_t *obj91;
    lv_obj_t *obj92;
    lv_obj_t *obj93;
    lv_obj_t *obj94;
    lv_obj_t *obj95;
    lv_obj_t *obj96;
    lv_obj_t *obj97;
    lv_obj_t *obj98;
    lv_obj_t *obj99;
    lv_obj_t *obj100;
    lv_obj_t *obj101;
    lv_obj_t *obj102;
    lv_obj_t *obj103;
    lv_obj_t *obj104;
    lv_obj_t *obj105;
    lv_obj_t *obj106;
    lv_obj_t *obj107;
    lv_obj_t *obj108;
    lv_obj_t *obj109;
    lv_obj_t *obj110;
    lv_obj_t *obj111;
    lv_obj_t *obj112;
    lv_obj_t *obj113;
    lv_obj_t *obj114;
    lv_obj_t *obj115;
    lv_obj_t *obj116;
    lv_obj_t *obj117;
    lv_obj_t *obj118;
    lv_obj_t *obj119;
    lv_obj_t *obj120;
    lv_obj_t *obj121;
    lv_obj_t *obj122;
    lv_obj_t *obj123;
    lv_obj_t *obj124;
    lv_obj_t *obj125;
    lv_obj_t *obj126;
    lv_obj_t *obj127;
    lv_obj_t *obj128;
    lv_obj_t *obj129;
    lv_obj_t *obj130;
    lv_obj_t *obj131;
    lv_obj_t *obj132;
    lv_obj_t *obj133;
    lv_obj_t *obj134;
    lv_obj_t *obj135;
    lv_obj_t *obj136;
    lv_obj_t *obj137;
    lv_obj_t *obj138;
    lv_obj_t *obj139;
    lv_obj_t *obj140;
    lv_obj_t *obj141;
    lv_obj_t *obj142;
    lv_obj_t *obj143;
    lv_obj_t *obj144;
    lv_obj_t *obj145;
    lv_obj_t *obj146;
    lv_obj_t *obj147;
    lv_obj_t *obj148;
    lv_obj_t *obj149;
    lv_obj_t *obj150;
    lv_obj_t *obj151;
    lv_obj_t *obj152;
    lv_obj_t *obj153;
    lv_obj_t *obj154;
    lv_obj_t *obj155;
    lv_obj_t *obj156;
    lv_obj_t *obj157;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_LAUNCH_SCREEN = 1,
    SCREEN_ID_WATCH_FACE = 2,
    SCREEN_ID_MAIN_MENU_PAGE_1 = 3,
    SCREEN_ID_MAIN_MENU_PAGE_2 = 4,
    SCREEN_ID_NEW_WORKOUT_PAGE = 5,
    SCREEN_ID_WORKOUT_STATS_PAGE = 6,
    SCREEN_ID_ACTIVE_WORKOUT_PAGE = 7,
    SCREEN_ID_END_WORKOUT_CONFIRMATION_PAGE = 8,
    SCREEN_ID_AFTER_WORKOUT_SUMMARY_PAGE = 9,
    SCREEN_ID_ALTITUDE_STATS_PAGE = 10,
    SCREEN_ID_PRESSURE_STATS_PAGE = 11,
    SCREEN_ID_ACTIVITY_TODAY_PAGE = 12,
    SCREEN_ID_ACTIVITY_STATS_PAGE = 13,
    SCREEN_ID_HEART_RATE_STATS_PAGE = 14,
    SCREEN_ID_BLOOD_OXYGEN_PAGE = 15,
};

void create_screen_launch_screen();
void tick_screen_launch_screen();

void create_screen_watch_face();
void tick_screen_watch_face();

void create_screen_main_menu_page_1();
void tick_screen_main_menu_page_1();

void create_screen_main_menu_page_2();
void tick_screen_main_menu_page_2();

void create_screen_new_workout_page();
void tick_screen_new_workout_page();

void create_screen_workout_stats_page();
void tick_screen_workout_stats_page();

void create_screen_active_workout_page();
void tick_screen_active_workout_page();

void create_screen_end_workout_confirmation_page();
void tick_screen_end_workout_confirmation_page();

void create_screen_after_workout_summary_page();
void tick_screen_after_workout_summary_page();

void create_screen_altitude_stats_page();
void tick_screen_altitude_stats_page();

void create_screen_pressure_stats_page();
void tick_screen_pressure_stats_page();

void create_screen_activity_today_page();
void tick_screen_activity_today_page();

void create_screen_activity_stats_page();
void tick_screen_activity_stats_page();

void create_screen_heart_rate_stats_page();
void tick_screen_heart_rate_stats_page();

void create_screen_blood_oxygen_page();
void tick_screen_blood_oxygen_page();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/