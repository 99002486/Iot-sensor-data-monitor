PROJECT_NAME = iot_sensor_data_monitor

COVERAGE_FLAG = -fprofile-arcs -ftest-coverage
SRC = main.c \
src/data_read.c \
src/functions.c

OBJ=data_read.o \
functions.o

INC = -Iinc

all:
	gcc $(SRC) $(INC) -o $(PROJECT_NAME).out

static-library:
	gcc $(SRC) $(INC) -c
	ar rc libsensordata.a $(OBJ)
	gcc -L. main.o $(INC) -o $(PROJECT_NAME).out -lsensordata

coverage:
	gcc $(COVERAGE_FLAG) $(SRC) $(INC) -o $(PROJECT_NAME).out
	./$(PROJECT_NAME).out
	gcov -a main.c 

clean:
	rm *.o *.out *.a *.gc*