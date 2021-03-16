#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include "definitions.h"
/**
 * function to initialize and dynamically allocate array of struct sensor_data
 * @return Pointer to dynamically allocated struct sensor_data array
 */
sensor_data_t* init_sensor_array();
/**
 * function to convert string read from csv file to enum FLOOR
 * @param[in] floor_data - string read from csv file
 * @return enum FLOOR
 */
FLOOR which_floor(char* floor_data);
/**
 * function to read data from csv file and store it in struct sensor_data
 * @param[in] sensor_data_array pointer to dynamically allocated struct sensor_data array
 * @param[in] sensor_data_file file pointer to csv file
 */
int sensor_data_read(sensor_data_t* sensor_data_array, FILE* sensor_data_file);
/**
 * function to check if the rooms have AC on and store the details into another array
 * @param[in] sensor_data_array pointer to dynamically allocated struct sensor_data array
 * @param[out] room_ac_array pointer to dynamically allocated array for rooms with ac on
 * @return count of rooms with ac on
 */
int room_ac_on_func(sensor_data_t* sensor_data_array,sensor_data_t* room_ac_array);
/**
 * function to find out which rooms have AC OFF and temperature above a threshold temperature
 * @param[in] sensor_data_array pointer to dynamically allocated struct sensor_data array
 * @param[out] room_temp_ac_array dynamically allocated array for desired functions results 
 * @return count of rooms with temperature>THRESHOLD_TEMP and AC is OFF
 */
int room_temp_ac_state_func(sensor_data_t* sensor_data_array,sensor_data_t* room_temp_ac_array, int threshold_temp);
/**
 * function to find room with highest power consumption
 * @param[in] sensor_data_array pointer to dynamically allocated struct sensor_data array
 * @return pointer to struct sensor_data of room with highest power consumption
 */
sensor_data_t* highest_power_room_func(sensor_data_t* sensor_data_array);
/**
 * function to find room with highest temperature
 * @param[in] sensor_data_array pointer to dynamically allocated struct sensor_data array
 * @return pointer to struct sensor_data of room with highest temperature
 */
sensor_data_t* highest_temp_room_func(sensor_data_t* sensor_data_array);
/**
 * function to swap two struct sensor_data
 * @param[in] s1 pointer to first struct
 * @param[in] s2 pointer to second struct
 */
int struct_swap(sensor_data_t* s1, sensor_data_t* s2);
/**
 * function to sort sensor_data_t array according to temperature
 * @param[in] sensor_data_array pointer to dynamically allocated struct sensor_data array
 * @param[out] sorted_array pointer to sorted array
 * @return temperature of first sensor_data_t in sorted array (highest)
 */
float sort_with_power(sensor_data_t* sensor_data_array,sensor_data_t* sorted_array);

#endif