# Makefile
# IJC-DU1 2015-02-26
# Author: Miroslav Karásek, FIT


# Compiler options
CC=gcc
CFLAGS=-O2 -std=c99 -pedantic -Wall -Wextra -lm -m64 -g
SHELL=C:/Windows/System32/cmd.exe

all: prvocisla.exe steg-decode.exe

prvocisla.exe: prvocisla.c error.c error.h eratosthenes.c eratosthenes.h bit-array.h
	$(CC) $(CFLAGS) error.c eratosthenes.c prvocisla.c -o prvocisla.exe -Wl,--stack,100000000

steg-decode.exe: steg-decode.c ppm.c ppm.h error.c error.h eratosthenes.c eratosthenes.h bit-array.h
	$(CC) $(CFLAGS) ppm.c error.c eratosthenes.c steg-decode.c -o steg-decode.exe -Wl,--stack,100000000