# Makefile
# IJC-DU1 2015-02-26
# Author: Miroslav Karásek, FIT


# Compiler options
CC=gcc
CFLAGS=-O2 -std=c99 -pedantic -Wall -Wextra -g 

all: prvocisla prvocisla-inline steg-decode

eratosthenes.o: eratosthenes.c bit-array.h error.h
	$(CC) $(CFLAGS) -c eratosthenes.c

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c

ppm.o: ppm.c ppm.h error.h
	$(CC) $(CFLAGS) -c ppm.c

prvocisla.o: prvocisla.c bit-array.h error.h eratosthenes.h
	$(CC) $(CFLAGS) -c prvocisla.c

steg-decode.o: steg-decode.c bit-array.h error.h eratosthenes.h ppm.h
	$(CC) $(CFLAGS) -c steg-decode.c

prvocisla: prvocisla.o error.o eratosthenes.o
	$(CC) $(CFLAGS) prvocisla.o error.o eratosthenes.o -o prvocisla -lm

prvocisla-inline: prvocisla.o error.o eratosthenes.o
	$(CC) $(CFLAGS) -DUSE_INLINE prvocisla.o error.o eratosthenes.o -o prvocisla-inline -lm

steg-decode: steg-decode.o ppm.o ppm.h error.o eratosthenes.o
	$(CC) $(CFLAGS) steg-decode.o ppm.o error.o eratosthenes.o -o steg-decode -lm
