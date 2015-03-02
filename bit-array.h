// bit-array.h
// IJC-DU1 a)
// 26.2.2015
// Autor: Miroslav Karásek, FIT

#ifndef BIT_ARRAY
#define BIT_ARRAY

typedef unsigned long BitArray_t[];

#define DU1_GET_BIT_(name,index) ((name[index/(sizeof(name[0])*8) + 1]\
 & (1 << (index % (sizeof(name[0])*8)))) ? 1 : 0)

#define DU1_SET_BIT_(name,index,bit) (name[index/(sizeof(name[0])*8) + 1]\
 = (bit ? (name[index/(sizeof(name[0])*8) + 1] | (1 << (index % (sizeof(name[0])*8))))\
 : (name[index/(sizeof(name[0])*8) + 1] & ~(1 << (index % (sizeof(name[0])*8))))))

#define BA_create(name, size) unsigned long name\
 [((size + 7)/8 + sizeof(unsigned long) - 1)/sizeof(unsigned long) + 1] = { size, }

#define BA_size(name) name[0]

#define BA_set_bit(name, index, bit) ((index >= name[0]) ? \
 (FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long)name[0]-1),1) : \
 DU1_SET_BIT_(name,index,bit))

#define BA_get_bit(name, index) ((index >= name[0] ) ? \
 (FatalError("Index %ld mimo rozsah 0..%ld", (long)index, (long)name[0]-1),1) : \
 DU1_GET_BIT_(name,index))

#endif //BIT_ARRAY

