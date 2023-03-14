EXEC = tp2
CC = gcc
CFLAGS = -std=c17 -Wall -g

SRC_DIR = src/
INCLUDE_DIR = include/
BIN_DIR = bin/

HEADER = $(INCLUDE_DIR)AB.h
OBJECTS = $(addprefix $(BIN_DIR), $(EXEC).o AB.o)


$(EXEC) : $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

$(BIN_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -o $@ $< $(CFLAGS)


clean: 
	rm -f $(BIN_DIR)*.o $(EXEC)