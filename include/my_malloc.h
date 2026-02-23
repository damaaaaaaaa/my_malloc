/**
 * 
 * \file my_malloc.h
 * 
 * \brief the abstract data types
 * 
 * \author dama
 * 
 * 
 * 
 */


#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stddef.h>

/**
 * \brief Allocates a contiguos block of memory
 * 
 * \param size Number of bytes to allocate
 * 
 * \return Pointer to the allocated memory, or NULL on failure 
 * 
 * 
 */
void* my_malloc (size_t size);

typedef struct block page_block;


#endif