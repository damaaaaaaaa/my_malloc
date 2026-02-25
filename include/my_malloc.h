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

/**
 * \brief Free all the block allocated with my_malloc. 
 * 
 * 
 * 
 */
void my_free_block ();

/**
 * \brief Reallocate a ptr
 * 
 * 
 * 
 */
void *my_realloc (void *ptr, size_t size);


#endif