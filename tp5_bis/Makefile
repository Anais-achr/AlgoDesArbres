EXEC = tp5_bis
CC=gcc
CFLAGS=-std=c17 -Wall

INCLUDE_DIR = include/
BIN_DIR = bin/
SRC_DIR = src/


HEADER = $(INCLUDE_DIR)Visualisation.h $(INCLUDE_DIR)ArbreIntervalles.h
OBJECTS = $(BIN_DIR)$(EXEC).o $(BIN_DIR)Visualisation.o $(BIN_DIR)ArbreIntervalles.o

$(EXEC) : $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) 


$(BIN_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	mkdir -p $(BIN_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)


clean: 
	rm -f $(BIN_DIR)*.o $(EXEC)
	rm -r $(BIN_DIR)