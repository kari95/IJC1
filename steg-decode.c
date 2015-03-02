// steg-decode.c
// IJC-DU1 b) 
// 26.2.2015
// Autor: Miroslav Karásek, FIT

#include <stdio.h>
#include <stdlib.h>
#include "bit-array.h"
#include "eratosthenes.h"
#include "error.h" 
#include "ppm.h"

void decode(struct ppm *image)
{
    BA_create(array, 3 * 5000 * 5000); 
    Eratosthenes(array);
    char ch = 0;
    int bits = 0;
    for (unsigned i = 0; i < image->xsize * image->ysize * 3; i++)
    {
        if (!BA_get_bit(array, i))
        {
            ch |= (image->data[i]&1) << bits;
            bits++;
            if (bits == 8)
            {
                if (ch == '\0')
                    break;
                putchar(ch);
                ch = 0;
                bits = 0;
            }
        }
    }
}

int main(int argc, char **argv)
{ 
    struct ppm *image;
    if (argc > 1)
    {
        image = ppm_read(argv[1]);
        decode(image);
        free(image);
    }
    else
        Warning("Zadejte obrazek");
    return 0;
} 