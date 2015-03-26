// error.c
// IJC-DU1 a) 
// 26.2.2015
// Autor: Miroslav Karásek, FIT

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

void Warning(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
}
void FatalError(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}