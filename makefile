
EXE = simulador


SRC_DIR = src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc
CC = g++
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS += -Iinclude
CFLAGS += -ansi -Wall -pedantic -O0 -g -ansi -Wpedantic -pg -std=c++14  
LDFLAGS += -Llib
LDLIBS += -lm

.PHONY: all clean

all: prepare $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o  $@

prepare:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(DOC_DIR)
doxy:
	mkdir -p $(DOC_DIR)
	doxygen
clean:
	$(RM) -rf $(OBJ) $(EXE) $(DOC_DIR) *.gch