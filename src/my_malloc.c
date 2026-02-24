#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/mman.h>

#include "my_malloc_private.h"

#define R_MEM_SIZE 4096


void *my_malloc (size_t size) {
    static page_block *block = NULL;
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

/*int main () {
    uint32_t *memoria = (uint32_t*)my_malloc (sizeof(uint32_t));
    *memoria = 200;
    printf ("\n%p\n", memoria);
    printf ("%d", *memoria);
    return 0;
}


int main () {
    uint8_t *memoria = (uint8_t *)my_alloc (5 * sizeof(uint8_t));
    printf ("\n%p\n", memoria);
    *memoria = 10;
    printf ("%p\n", memoria + 1 * sizeof (uint8_t));
    printf ("%d\n", *memoria);
    return 0;
}
*/
