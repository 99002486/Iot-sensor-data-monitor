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

#endif
