#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "definitions.h"

sensor_data_t* init_sensor_array();

FLOOR which_floor(char* floor_data);

int sensor_data_read(sensor_data_t* sensor_data_array, FILE* sensor_data_file);

int room_ac_on_func(sensor_data_t* sensor_data_array,sensor_data_t* room_ac_array);

int room_temp_ac_state_func(sensor_data_t* sensor_data_array,sensor_data_t* room_temp_ac_array, int threshold_temp);

sensor_data_t* highest_power_room_func(sensor_data_t* sensor_data_array);

sensor_data_t* highest_temp_room_func(sensor_data_t* sensor_data_array);

int struct_swap(sensor_data_t* s1, sensor_data_t* s2);

float sort_with_power(sensor_data_t* sensor_data_array,sensor_data_t* sorted_array);

#endif