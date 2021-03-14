#ifndef __DEFINITONS_H__
#define __DEFINITONS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NO_OF_ENTRIES 5
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



#endif
