#ifndef __DEFINITONS_H__
#define __DEFINITONS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NO_OF_ENTRIES 5
#define THRESHOLD_TEMP 27
typedef enum{GROUND=0,FIRST,SECOND,THIRD,FOURTH,FIFTH} FLOOR;

typedef enum{OFF=0,ON} AC_STATE;

typedef struct sensor_data{
    FLOOR floor;
    int room_no;
    float power_consumption;
    AC_STATE ac_state;
    float room_temp;
}sensor_data_t;

sensor_data_t* init_sensor_array();

FLOOR which_floor(char* floor_data);

int sensor_data_read(sensor_data_t* sensor_data_array, FILE* sensor_data_file);

int room_ac_on_func(sensor_data_t* sensor_data_array,sensor_data_t* room_ac_array);

int room_temp_ac_state_func(sensor_data_t* sensor_data_array,sensor_data_t* room_temp_ac_array, int threshold_temp);

sensor_data_t* highest_power_room_func(sensor_data_t* sensor_data_array);

#endif
