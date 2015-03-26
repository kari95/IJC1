# Makefile
# IJC-DU1 2015-02-26
# Author: Miroslav Karásek, FIT


# Compiler options
CC=gcc
CFLAGS=-O2 -std=c99 -pedantic -Wall -Wextra -lm -m64 -g
SHELL=C:/Windows/System32/cmd.exe

%.o: ../%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: prvocisla steg-decode prvocisla-inline

prvocisla: prvocisla.o error.o eratosthenes.o
	$(CC) $(CFLAGS) error.o eratosthenes.o prvocisla.o -o prvocisla

prvocisla-inline: prvocisla.o error.o eratosthenes.o
	$(CC) $(CFLAGS) -DUSE_INLINE error.o eratosthenes.o prvocisla.o -o prvocisla-inline

steg-decode: steg-decode.o ppm.o ppm.h error.o eratosthenes.o
	$(CC) $(CFLAGS) ppm.c error.c eratosthenes.c steg-decode.c -o steg-decode