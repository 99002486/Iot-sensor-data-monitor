#include "functions.h"

int room_ac_on_func(sensor_data_t* sensor_data_array,sensor_data_t* room_ac_array)
{
    int count=0;
    for(int i=0;i<NO_OF_ENTRIES;i++){
        if(sensor_data_array[i].ac_state==ON){
            room_ac_array[count]=sensor_data_array[i];
            count++;
        }

    }
    return count;
}

int room_temp_ac_state_func(sensor_data_t* sensor_data_array,sensor_data_t* room_temp_ac_array, int threshold_temp)
{
    int count=0;
    for(int i =0;i<NO_OF_ENTRIES;i++){
        if(sensor_data_array[i].ac_state==OFF && sensor_data_array[i].room_temp>threshold_temp){
            room_temp_ac_array[count]=sensor_data_array[i];
            count++;
        }
    }
    return count;
}
sensor_data_t* highest_power_room_func(sensor_data_t* sensor_data_array)
{
    float highest_power=0;
    int highest_power_room_index=0;
    sensor_data_t* highest_power_room;

    for(int i =0;i<NO_OF_ENTRIES;i++){
        if(sensor_data_array[i].power_consumption>highest_power){
            highest_power_room_index=i;
            highest_power=sensor_data_array[i].power_consumption;
        }
    }
    highest_power_room=&sensor_data_array[highest_power_room_index];
    return highest_power_room;
}

sensor_data_t* highest_temp_room_func(sensor_data_t* sensor_data_array)
{
    float highest_temp=0;
    int highest_temp_room_index=0;
    sensor_data_t* highest_temp_room;

    for(int i =0;i<NO_OF_ENTRIES;i++){
        if(sensor_data_array[i].room_temp>highest_temp){
            highest_temp_room_index=i;
            highest_temp=sensor_data_array[i].room_temp;
        }
    }
    highest_temp_room=&sensor_data_array[highest_temp_room_index];
    return highest_temp_room;
}

int struct_swap(sensor_data_t* s1, sensor_data_t* s2)
{
    sensor_data_t temp;
    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
    return 0;
}

float sort_with_power(sensor_data_t* sensor_data_array,sensor_data_t* sorted_array)
{
    int n = NO_OF_ENTRIES;
    for(int i =0;i<NO_OF_ENTRIES;i++)
    {
        sorted_array[i]=sensor_data_array[i];
    } 
    for (int i = 0; i <n-1; i++){       
        // Last i elements are already in place    
        for (int j = 0; j < n-i-1; j++){  
            if (sorted_array[j].power_consumption > sorted_array[j+1].power_consumption) 
                struct_swap(&sorted_array[j], &sorted_array[j+1]);
        }
    }
    float highest_temp = sorted_array[0].power_consumption;
    return highest_temp;
}

