EXEC = tp3
CC = gcc
CFLAGS = -std=c17 -Wall 

INCLUDE_DIR = include/
BIN_DIR = bin/
SRC_DIR = src/

HEADER = $(addprefix $(INCLUDE_DIR), AB.h ABR.h)
OBJECTS =  $(addprefix $(BIN_DIR), $(EXEC).o AB.o ABR.o)


$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

$(BIN_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -o $@ $< $(CFLAGS)

clean: 
	-rm -f $(BIN_DIR)*.o $(EXEC)
	