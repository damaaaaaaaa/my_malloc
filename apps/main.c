#include "include/my_malloc.h"
#include <stdio.h>
#include <stdint.h>

int main () {
    uint16_t *my_number = (uint16_t*)my_malloc (sizeof (uint16_t));
    *my_number = 69;
    printf ("%p\n", my_number);
    printf ("%d\n", *my_number);
    return 0;
}