INCLUDE := $(wildcard ./include/*.c)
SRC := $(wildcard ./src/*.c)

PROG := ./bin/cobalt
MAIN := ./main.c
CC := gcc

all: mkbin $(PROG)

mkbin:
	@mkdir -p bin

$(PROG): $(MAIN)
	$(CC) $(MAIN) -o $(PROG)