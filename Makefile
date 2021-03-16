PROJECT_NAME = iot_sensor_data_monitor

COVERAGE_FLAG = -fprofile-arcs -ftest-coverage
SRC = main.c \
src/data_read.c \
src/functions.c

TEST_SRC = test/test_main.c \
src/data_read.c \
src/functions.c

OBJ=data_read.o \
functions.o

INC = -Iinc

.PHONY=all static-library coverage clean test

all:
	gcc $(SRC) $(INC) -o $(PROJECT_NAME).out

static-library:
	gcc $(SRC) $(INC) -c
	ar rc libsensordata.a $(OBJ)
	gcc -L. main.o $(INC) -o $(PROJECT_NAME).out -lsensordata

test-out:
	gcc $(TEST_SRC) $(INC) -o test_$(PROJECT_NAME).out -lcunit -lm
	./test_$(PROJECT_NAME).out

coverage:
	gcc $(COVERAGE_FLAG) $(SRC) $(INC) -o $(PROJECT_NAME).out
	./$(PROJECT_NAME).out
	gcov -a main.c 

clean:
	rm *.o *.out *.a *.gc*