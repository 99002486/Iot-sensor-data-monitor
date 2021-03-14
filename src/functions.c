#include "definitions.h"
int sensor_struct_copy_func(sensor_data_t* destination,sensor_data_t* source)
{
    destination->ac_state=source->ac_state;
    destination->floor=source->floor;
    destination->power_consumption=source->floor;
    destination->room_no=source->floor;
    destination->room_temp=source->floor;
    return 0;
}
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
            printf("ac state: %d\n",room_temp_ac_array[count].ac_state);
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
        if(sensor_data_array[i].power_consumption>highest_power)
            highest_power_room_index=i;
    }
    highest_power_room=&sensor_data_array[highest_power_room_index];
    printf("high pc room: %d\n",highest_power_room->room_no);
    return highest_power_room;
}