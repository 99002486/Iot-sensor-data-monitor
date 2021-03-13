#include "definitions.h"
int init_sensor_array(sensor_data_t* array_pointer)
{
    array_pointer = calloc(NO_OF_ENTRIES,sizeof(sensor_data_t));
    return 0;
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
    char buffer[1024];  //To store input.csv data for further processing
  
    int row = 0; //represents array index
    int column = 0;  //To store data in various struct variables of same array index

    while (fgets(buffer, 1024, sensor_data_file)) { 
    
        
        // Splitting the data 
        char* data = strtok(buffer, ", "); 
        
        while (data ) { 
            switch(column)
            {
                case 0:
                    char floor_str[10];
                    floor_str=data;
                    sensor_data_array[row].floor=which_floor(floor_str);
                    printf("floor: %d ",sensor_data_array[row].floor);
                    break;
                case 1:
                    sensor_data_array[row].room_no=atoi(data);
                    printf("room: %d ",sensor_data_array[row].room_no);
                    break;
                case 2:
                    sensor_data_array[row].power_consumption=atof(data);
                    printf("pc: %.2f ",sensor_data_array[row].power_consumption;
                    break;
                case 3:
                    sensor_data_array[row].ac_state=(!strcmp(data,"ON"))?ON:OFF;
                    printf("ac state: %d ",sensor_data_array[row].ac_state);
                    break;
                case 4:
                    sensor_data_array[row].room_temp=atof(data);
                    printf("roomtemp: %.2f \n",sensor_data_array[row].room_temp;
                    break;
                default:
                    printf("invalid column\n");
                    break;
            }
            data = strtok(NULL, ", "); 
            
            column++; // incrementing column for next structure member
            
        } 
        
        column=0;  //Again reintialize column value to zero for next row
        row++;      //Incrementing row for next array index 
    } 

    
    // Close the file 
    fclose(fp); 
}