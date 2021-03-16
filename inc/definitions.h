/**
 * @file - definitions.h
 * defines all the necessary data structures needed for the applications as well as the headers needed
 */
#ifndef __DEFINITONS_H__
#define __DEFINITONS_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NO_OF_ENTRIES 5    /**Macro for the number of entries*/                                         
#define THRESHOLD_TEMP 27   /**Threshold temperature whish is used for comparison in @func room_temp_ac_state_func*/
/**
 * @enum FLOOR - For floor in which room resides
 */
typedef enum{GROUND=0,FIRST,SECOND,THIRD,FOURTH,FIFTH} FLOOR;
/**
 * @enum AC_STATE - For AC state, 0 if OFF/1 if ON
 */
typedef enum{OFF=0,ON} AC_STATE;
/**
 * @struct sensor_data - struct to hold the data specifiec from the sensor.csv
 */      
typedef struct sensor_data{
    /**enum to hold floor*/
    FLOOR floor;
    /**int to hold room_no*/                
    int room_no;
    /**float to hold power consumption*/                
    float power_consumption;
    /**enum to hold state of the ac*/    
    AC_STATE ac_state;
    /**float to hold the room temperature*/          
    float room_temp;            
}sensor_data_t;

#endif
