# Majority of file adapated from https://github.com/tomobones/dictcc_wrapper/blob/master/Makefile

CC=clang
CC_FLAGS=-Wall -Wextra -pedantic
CC_LIBS=

BIN_FILE=dearie

OBJ_DIR=obj
SRC_DIR=src
HDR_DIR=include

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)

# Search and replace
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(OBJ_DIR) $(BIN_FILE)

# $@ Means the name of the target
# $^ means all requirements
$(BIN_FILE): $(OBJ_FILES)
	$(CC) $(CC_FLAGS) -o $@ $^ -I$(HDR_DIR) $(CC_LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -o $@ -c $^ -I$(HDR_DIR)

$(OBJ_DIR):
	mkdir $@

clean:
	rm -rf $(BIN_FILE) $(OBJ_DIR)
