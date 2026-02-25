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
void *my_realloc (void *ptr, size_t old_size ,size_t new_size);

/**
 * \brief Alloc a contiguos block of memory and set it to 0
 * 
 ** \param memsize Number of element
 * \param size Number of bytes for each element
 * 
 * 
 * 
 * 
 */
void *my_calloc (size_t memsize, size_t size);

#endif