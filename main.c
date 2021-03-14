#include "definitions.h"

int main(){
    sensor_data_t* sensor_data_array=NULL;
    FILE* sensor_data_file;
    sensor_data_file=fopen("sensor.csv","r");
    if(!sensor_data_file)
        printf("File opening error");
    sensor_data_array=init_sensor_array();
    sensor_data_read(sensor_data_array,sensor_data_file);
    return 0;
}