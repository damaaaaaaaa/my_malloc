#include "include/my_malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main () {
    char *my_char = (char*)my_malloc (8 * sizeof (char));
    char* str = "ciao";
    memcpy (my_char, str, 4 * sizeof (char));
    uint8_t *my_number = (uint8_t*)my_malloc (sizeof (uint8_t));
    *my_number = 129;
    printf ("Pointer at char after my_malloc: %p\n", my_char);
    printf ("String: %s\n", my_char);
    printf ("Pointer at integer after my_malloc: %p\n", my_number);
    printf ("Value: %d\n", *my_number);

    uint16_t *my_new_number = (uint16_t*)my_realloc (my_number, sizeof (uint8_t) ,sizeof (uint16_t));
    printf ("Pointer at integer after my_realloc: %p\n", my_new_number);
    printf ("Value: %d\n", *my_new_number);

    my_free_block ();

    char *my_char2 = (char*)my_malloc (8 * sizeof (char));
    memcpy (my_char2, str, 4 * sizeof (char));
    uint8_t *my_number2 = (uint8_t*)my_malloc (sizeof (uint8_t));
    *my_number2 = 129;
    printf ("Pointer at char after my_free and my_malloc: %p\n", my_char2);
    printf ("String: %s\n", my_char2);
    printf ("Pointer at integer after my_free and my_malloc: %p\n", my_number2);
    printf ("Value: %d\n", *my_number2);
    my_free_block ();
    return 0;
}