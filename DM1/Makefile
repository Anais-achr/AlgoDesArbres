CC=gcc
CFLAGS = -std=c17 -Wall

INCLUDE_DIR = include/
BIN_DIR = bin/
SRC_DIR = src/

TEST_DIR = test/
TEST_BIN_DIR = test/bin/


HEADER = $(addprefix $(INCLUDE_DIR), ABR.h Visualisation.h Utils.h) 
OBJECTS = $(addprefix $(BIN_DIR), test_ABR ABR Filtrage Utils Visualisation)
UTILS = $(addprefix $(BIN_DIR), ABR.o Visualisation.o Utils.o)

#all: test_ABR filtre


filtre: $(BIN_DIR)Filtrage.o $(UTILS)
	$(CC) -o $@ $^

$(BIN_DIR)%.o: $(SRC_DIR)%.c $(HEADER) 
	mkdir -p $(BIN_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)



#TESTS
test_ABR: $(TEST_BIN_DIR)test_ABR.o $(UTILS)
	$(CC) -o $@ $^

$(TEST_BIN_DIR)%.o: $(TEST_DIR)%.c $(HEADER) 
	$(CC) -c -o $@ $< $(CFLAGS)




.PHONY: clean

clean:
	rm -f $(BIN_DIR)*.o test_ABR filtre $(TEST_BIN_DIR)*.o
	rm -r $(BIN_DIR)




