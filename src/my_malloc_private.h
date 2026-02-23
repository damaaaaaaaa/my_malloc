#ifndef MY_MALLOC_PRIVATE_H
#define MY_MALLOC_PRIVATE_H

#include <stddef.h>
#include <stdbool.h>
#include "include/my_malloc.h"

/** \brief Defines the structures of a block of memory */
struct block {
    unsigned char* heap_start;
    unsigned char* heap_copy;
    int memory_left;
};

typedef struct block page_block;


#endif