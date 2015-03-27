// bit-array.h
// IJC-DU1 a)
// 26.3.2015
// Autor: Miroslav Karásek, FIT

#ifndef BIT_ARRAY
#define BIT_ARRAY

#include"error.h"

typedef unsigned long BitArray_t[];

#define ST_BIT(name, index) ((name)[(index)/(sizeof((name)[0])*8) + 1] |= (1L << ((index) % (sizeof((name)[0])*8))))

#define CL_BIT(name, index) ((name)[(index)/(sizeof((name)[0])*8) + 1] &= ~(1L << ((index) % (sizeof((name)[0])*8))))

#define DU1_GET_BIT_(name,index) (((name)[(index)/(sizeof((name)[0])*8) + 1]\
 & (1L << ((index) % (sizeof((name)[0])*8)))) ? 1 : 0)

#define DU1_SET_BIT_(name,index,bit) ((bit) ? ST_BIT((name),(index)) : CL_BIT((name),(index))) 

#define BA_create(name, size) unsigned long (name)\
 [((size + 7)/8 + sizeof(unsigned long) - 1)/sizeof(unsigned long) + 1] = { size, }
 
#ifdef USE_INLINE 
// Inline start
 
inline unsigned long BA_size(BitArray_t array)
{
    return array[0];
}

inline void BA_set_bit(BitArray_t array, unsigned long index, int bit)
{
    if (index >= array[0])
        FatalError("Index %ld mimo rozsah 0..%ld", index, array[0]-1);
    DU1_SET_BIT_(array,index,bit);
}

inline int BA_get_bit(BitArray_t array, unsigned long index)
{
    if (index >= array[0])
        FatalError("Index %ld mimo rozsah 0..%ld", index, array[0]-1);
    return DU1_GET_BIT_(array,index);
}

//Inline end
#else

// Macro start
#define BA_size(name) (name)[0]

#define BA_set_bit(name, index, bit) (((index) >= (name)[0]) ? \
 (FatalError("Index %ld mimo rozsah 0..%ld", (long)(index), (long)(name)[0]-1),0) : \
 DU1_SET_BIT_((name),(index),(bit)))
 
#define BA_get_bit(name, index) (((index) >= (name)[0] ) ? \
 (FatalError("Index %ld mimo rozsah 0..%ld", (long)(index), (long)(name)[0]-1),0) : \
 DU1_GET_BIT_((name),(index)))

// Macro end 
#endif //USE_INLINE

#endif //BIT_ARRAY

