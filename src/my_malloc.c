#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>

#include "my_malloc_private.h"

#define R_MEM_SIZE 4096

static page_block *block = NULL;

void *my_malloc (size_t size) {
    if (block == NULL || size > block->memory_left) { 
        void *raw_memory = mmap (
                                NULL, size,
                                PROT_READ | PROT_WRITE,
                                MAP_ANONYMOUS | MAP_PRIVATE, 
                                -1, 0
                                );

        if (raw_memory == MAP_FAILED) {
            perror ("errore nell'allocazione della memoria");
            return NULL;    
        }
        block = (page_block*)raw_memory;
        block->heap_start = (unsigned char*)raw_memory + sizeof (page_block);
        block->heap_copy = block->heap_start;
        block->memory_left = R_MEM_SIZE - sizeof (page_block);
    }
    void* mem = (void*)block->heap_copy;
    
    block->heap_copy += size;
    block->memory_left -= size;
    return mem;
}

void my_free_block () {
    if (block == NULL) return;
    if (munmap (block, R_MEM_SIZE) == -1) {
        printf ("free failed with error %d <%s>.\n", errno, strerror (errno));
    }
    block = NULL;
}

void *my_realloc (void *ptr, size_t old_size, size_t new_size) {
    if (ptr == NULL) return NULL;
    void *new_ptr = my_malloc (new_size);
    if (new_ptr == NULL) return NULL;
    if (old_size <= new_size) memcpy (new_ptr, ptr, old_size);
    else memcpy (new_ptr, ptr, new_size);
    return new_ptr;
}

void *my_calloc (size_t memsize, size_t size) {
    void *ptr = my_malloc (memsize * size);
    if (ptr == NULL) return NULL;
    memset (ptr, 0, size * memsize);
    return ptr;
}