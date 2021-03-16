#include "definitions.h"
sensor_data_t* init_sensor_array()
{
    sensor_data_t* array_pointer=NULL;
    array_pointer = calloc(NO_OF_ENTRIES,sizeof(sensor_data_t));
    return array_pointer;
}

FLOOR which_floor(char* floor_data)
{
    if(strcmp(floor_data,"Ground")==0)
        return GROUND;
    if(strcmp(floor_data,"First")==0)
        return FIRST;
    if(strcmp(floor_data,"Second")==0)
        return SECOND;
    if(strcmp(floor_data,"Third")==0)
        return THIRD;
    if(strcmp(floor_data,"Fourth")==0)
        return FOURTH;
    if(strcmp(floor_data,"Fifth")==0)
        return FIFTH;
    else{
        printf("invalid Data");
        exit(-1);
    }
}

int sensor_data_read(sensor_data_t* sensor_data_array, FILE* sensor_data_file)
{
    char buffer[1024];  
    int row = 0;
    int column = 0;  
    while (fgets(buffer, 1024, sensor_data_file)) {  
        char* data = strtok(buffer, ", "); 
        while (data) { 
            switch(column)
            {
                case 0:
                    sensor_data_array[row].floor=which_floor(data);
                    break;
                case 1:
                    sensor_data_array[row].room_no=atoi(data);
                    break;
                case 2:
                    sensor_data_array[row].power_consumption=atof(data);
                    break;
                case 3:
                    sensor_data_array[row].ac_state=(!strcmp(data,"ON"))?ON:OFF;
                    break;
                case 4:
                    sensor_data_array[row].room_temp=atof(data);
                    break;
                default:
                    printf("invalid column\n");
                    break;
            }
            data = strtok(NULL, ", "); 
            column++;
        }     
        column=0;
        row++;
    } 
    return 0; 
}