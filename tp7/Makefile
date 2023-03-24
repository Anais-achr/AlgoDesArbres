EXEC=tp7
CC=gcc
CFLAGS= -std=c17 -Wall -g

INCLUDE_DIR= include/
SRC_DIR= src/
BIN_DIR= bin/


HEADER = $(addprefix $(INCLUDE_DIR), UnionFind.h)
OBJECT = $(addprefix $(BIN_DIR), $(EXEC).o UnionFind.o)


$(EXEC) : $(OBJECT)
	$(CC) -o $@ $^ $(CFLAGS)

$(BIN_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	mkdir -p bin/
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm -f $(BIN_DIR)*.o $(EXEC) 
	rm -r $(BIN_DIR)