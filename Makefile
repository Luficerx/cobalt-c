PROG := ./bin/cobalt
MAIN := ./main.c
CC := gcc

SRC := $(MAIN) $(wildcard ./src/*.c)

CFLAGS := -I./include

all: mkbin $(PROG)

mkbin:
	@mkdir -p bin

$(PROG): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(PROG) $(INCLUDE)