// prvocisla.c
// IJC-DU1 a) 
// 26.2.2015
// Autor: Miroslav Karásek, FIT

#include <stdio.h>
#include "bit-array.h"
#include "eratosthenes.h"
#include "error.h"

int main()
{ 
    BA_create(array, 201000000);  
    Eratosthenes(array);
    unsigned long lenght = BA_size(array);
    int index = 10;
    unsigned int prvocisla[10];
    for (unsigned long i = lenght - 1; i > 0; i--)
    {
        if (!BA_get_bit(array, i))
            prvocisla[--index] = i;
        if (index == 0)
            break;
    }
    for (index = 0; index < 10; index++)
        printf("%u\n", prvocisla[index]);
    return 0;
} 