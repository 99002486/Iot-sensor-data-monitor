PROJECT_NAME = iot_sensor_data_monitor

SRC = main.c \
src/data_read.c

INC = -Iinc

all:
	gcc $(SRC) $(INC) -o $(PROJECT_NAME).out