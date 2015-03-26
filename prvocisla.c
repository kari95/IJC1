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
    unsigned int prvocisla[10];
    for (int i = 10; i >= 0; i--)
    {
        if (!BA_get_bit(array, lenght - i - 1))
            prvocisla[i] = lenght - i - 1;
    }
    for (int i = 0; i < 10; i++)
        printf("%u\n", prvocisla[i]);
    return 0;
} 
