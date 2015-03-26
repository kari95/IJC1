// ppm.c
// IJC-DU1 a) 
// 26.2.2015
// Autor: Miroslav Karásek, FIT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"
#include "error.h"

struct ppm *ppm_read(const char * filename)
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
    {
        Warning("Chyba pri otevirani souboru");
        return NULL;
    }
    char P6[3];
    unsigned xsize;
    unsigned ysize;
    int n255;
    if(fscanf(f, "%2s", P6) != 1 || strcmp(P6, "P6") || fscanf(f, "%u", &xsize) != 1 || fscanf(f, "%u", &ysize) != 1 || fscanf(f, "%d", &n255) != 1 || n255 != 255)
    {
        Warning("Chybny tvar");
        fclose(f);
        return NULL;
    }
    if (xsize > 5000 || ysize > 5000)
    {
        Warning("Prilis velky obrazek. Limit: 5000x5000px");
        fclose(f);
        return NULL;
    }
    struct ppm *image = malloc(sizeof(struct ppm) + 3 * xsize * ysize);
    if (image == NULL)
    {
        Warning("Alokace se nezdarila");
        fclose(f);
        return NULL;
    }
    image->xsize = xsize;
    image->ysize = ysize;
    fgetc(f);
    unsigned size = fread(image->data, 1, 3 * xsize * ysize, f);
    if (size != 3 * xsize * ysize || fgetc(f) != EOF)
    {
        Warning("Pri nacitani doslo k chybe");
        fclose(f);
        free(image);
        return NULL;
    }
    fclose(f);
    return image;
}

int ppm_write(struct ppm *p, const char * filename)
{
    FILE *f = fopen(filename, "wb");
    if (f == NULL)
    {
        Warning("Chyba pri otevirani souboru");
        return -1;
    }
    fprintf(f,"R6\n%d %d\n255\n", p->xsize, p->ysize);
    
    unsigned size = fwrite(p->data, 1, 3 * p->xsize * p->ysize, f);
    if (size != 3 * p->xsize * p->ysize)
    {
        Warning("Pri ukladani doslo k chybe");
        fclose(f);
        return -1;
    }
    fclose(f);
    return 0;
}
