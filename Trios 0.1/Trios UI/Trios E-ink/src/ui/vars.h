#ifndef EEZ_LVGL_UI_VARS_H
#define EEZ_LVGL_UI_VARS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// enum declarations



// Flow global variables

enum FlowGlobalVariables {
    FLOW_GLOBAL_VARIABLE_NONE
};

// Native global variables

extern const char *get_var_current_day_week();
extern void set_var_current_day_week(const char *value);
extern int32_t get_var_current_day();
extern void set_var_current_day(int32_t value);
extern int32_t get_var_heart_rate();
extern void set_var_heart_rate(int32_t value);
extern int32_t get_var_altitude();
extern void set_var_altitude(int32_t value);
extern int32_t get_var_today_stepcount();
extern void set_var_today_stepcount(int32_t value);
extern int32_t get_var_workout_counter_value();
extern void set_var_workout_counter_value(int32_t value);
extern const char *get_var_current_workout();
extern void set_var_current_workout(const char *value);
extern int32_t get_var_curr_workout_cal();
extern void set_var_curr_workout_cal(int32_t value);
extern int32_t get_var_current_pressure_hpa();
extern void set_var_current_pressure_hpa(int32_t value);
extern int32_t get_var_today_cal();
extern void set_var_today_cal(int32_t value);
extern int32_t get_var_today_extime_minutes();
extern void set_var_today_extime_minutes(int32_t value);
extern int32_t get_var_daily_stepcount_goal();
extern void set_var_daily_stepcount_goal(int32_t value);
extern int32_t get_var_daily_cal_goal();
extern void set_var_daily_cal_goal(int32_t value);
extern int32_t get_var_daily_extime_goal();
extern void set_var_daily_extime_goal(int32_t value);
extern int32_t get_var_which_stat_on_graph();
extern void set_var_which_stat_on_graph(int32_t value);
extern int32_t get_var_average_altitude_today();
extern void set_var_average_altitude_today(int32_t value);
extern bool get_var_does_workout_have_distance();
extern void set_var_does_workout_have_distance(bool value);
extern int32_t get_var_workout_average_hr();
extern void set_var_workout_average_hr(int32_t value);
extern int32_t get_var_workout_time_sec();
extern void set_var_workout_time_sec(int32_t value);
extern int32_t get_var_current_month();
extern void set_var_current_month(int32_t value);
extern int32_t get_var_current_year();
extern void set_var_current_year(int32_t value);
extern bool get_var_is_workout_paused();
extern void set_var_is_workout_paused(bool value);
extern int32_t get_var_minutes_since_midnight();
extern void set_var_minutes_since_midnight(int32_t value);
extern int32_t get_var_resting_hr();
extern void set_var_resting_hr(int32_t value);
extern float get_var_blood_o2();
extern void set_var_blood_o2(float value);
extern float get_var_average_blood_o2();
extern void set_var_average_blood_o2(float value);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_VARS_H*/