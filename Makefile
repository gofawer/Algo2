BIN=erfbin
OBJECTS=erf.o
SRC=erf.c
CFLAGS= -lm -g -Wall -O3 -std=gnu11
LIBS=
CC=gcc

$(BIN): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(SRC)

