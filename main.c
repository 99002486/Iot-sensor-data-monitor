#include "definitions.h"

int main(){
    sensor_data_t* sensor_data_array=NULL;
    sensor_data_t* room_ac_on_array=NULL;
    sensor_data_t* room_temp_ac_array=NULL;
    int room_count,room_power;
    FILE* sensor_data_file;
    sensor_data_file=fopen("sensor.csv","r");
    if(!sensor_data_file)
        printf("File opening error");

    sensor_data_array=init_sensor_array();
    sensor_data_read(sensor_data_array,sensor_data_file);
    
    room_ac_on_array=init_sensor_array();
    room_count=room_ac_on_func(sensor_data_array,room_ac_on_array);
    for(int i=0;i<NO_OF_ENTRIES;i++)
    {
        printf("state: %d",room_ac_on_array[i].room_no);
    }
    printf("\n");

    room_temp_ac_array=init_sensor_array();
    room_count=room_temp_ac_state_func(sensor_data_array,room_temp_ac_array,THRESHOLD_TEMP);

    sensor_data_t* highest_power_room; 
    highest_power_room=highest_power_room_func(sensor_data_array);
    printf("high pc room: %d\n",highest_power_room->room_no);

    sensor_data_t* highest_temp_room; 
    highest_temp_room=highest_temp_room_func(sensor_data_array);
    printf("high temp room: %d\n",highest_temp_room->room_no);

    sensor_data_t* sorted_data_array=NULL;
    float highest_temp;
    sorted_data_array=init_sensor_array();
    highest_temp=sort_with_power(sensor_data_array,sorted_data_array);
    for(int i=0;i<NO_OF_ENTRIES;i++)
    {
        printf("temp: %.2f",sorted_data_array[i].room_temp);
    }

    return 0;
}