#include "include/my_malloc.h"
#include <stdio.h>
#include <stdint.h>

int main () {
    uint8_t *my_number = (uint8_t*)my_malloc (sizeof (uint8_t));
    *my_number = 128;
    printf ("%p\n", my_number);
    printf ("%d\n", *my_number);
    return 0;
}