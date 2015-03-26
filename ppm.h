// ppm.h
// IJC-DU1 b) 
// 26.2.2015
// Autor: Miroslav Karásek, FIT

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
};
 
struct ppm * ppm_read(const char * filename);

int ppm_write(struct ppm *p, const char * filename);

