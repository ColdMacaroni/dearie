CC=clang
CC_FLAGS=

OBJ_DIR=obj
SRC_DIR=src

all: dearie

dearie: main.o
	echo made

main.o
	$(CC) $(CC_FLAGS) -o $(OBJ_DIR)
