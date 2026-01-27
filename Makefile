PROG := ./bin/cobalt
MAIN := ./main.c
CC := gcc

SRC := $(MAIN) $(wildcard ./src/*.c)

FLAGS := -Wall -Wextra -ggdb
CFLAGS := -I./include $(FLAGS)

all: mkbin $(PROG)

mkbin:
	@mkdir -p bin

$(PROG): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(PROG) $(INCLUDE)