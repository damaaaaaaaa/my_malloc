#include "include/my_malloc.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main () {
    char *my_char = (char*)my_malloc (8 * sizeof (char));
    char* str = "ciao";
    memcpy (my_char, str, 4 * sizeof (char));
    uint8_t *my_number = (uint8_t*)my_malloc (sizeof (uint8_t));
    *my_number = 129;
    printf ("%p\n", my_char);
    printf ("%s\n", my_char);
    printf ("%p\n", my_number);
    printf ("%d\n", *my_number);

    uint16_t *my_new_number = (uint16_t*)my_realloc (my_number, sizeof (uint16_t));
    *my_new_number = 1000;
    printf ("%p\n", my_new_number);
    printf ("%d\n", *my_new_number);

    my_free_block ();

    char *my_char2 = (char*)my_malloc (8 * sizeof (char));
    memcpy (my_char2, str, 4 * sizeof (char));
    uint8_t *my_number2 = (uint8_t*)my_malloc (sizeof (uint8_t));
    *my_number2 = 129;
    printf ("%p\n", my_char2);
    printf ("%s\n", my_char2);
    printf ("%p\n", my_number2);
    printf ("%d\n", *my_number2);
    my_free_block ();
    return 0;
}