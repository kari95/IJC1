// eratosthenes.c
// IJC-DU1 a) 
// 26.2.2015
// Autor: Miroslav Karásek, FIT

#include <stdio.h>
#include <math.h>
#include "bit-array.h"
#include "error.h"

void Eratosthenes(BitArray_t array)
{  
    unsigned long lenght = BA_size(array);
    BA_set_bit(array, 0, 1);
    BA_set_bit(array, 1, 1);
    for (unsigned long i = 2; i < (unsigned long) sqrt((unsigned long) lenght); i++)
    {
        for (unsigned long j = 2*i; j < lenght; j += i)
            BA_set_bit(array, j, 1);
    }
}
