#include "include/my_malloc.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main () {
    char *my_char = (char*)my_malloc (8 * sizeof (char));
    strcpy (my_char, "ciao");
    uint8_t *my_number = (uint8_t*)my_malloc (sizeof (uint8_t));
    *my_number = 129;
    printf ("%p\n", my_char);
    printf ("%s\n", my_char);
    printf ("%p\n", my_number);
    printf ("%d\n", *my_number);
    my_free_block ();

    char *my_char2 = (char*)my_malloc (8 * sizeof (char));
    strcpy (my_char2, "ciao");
    uint8_t *my_number2 = (uint8_t*)my_malloc (sizeof (uint8_t));
    *my_number2 = 129;
    printf ("%p\n", my_char2);
    printf ("%s\n", my_char2);
    printf ("%p\n", my_number2);
    printf ("%d\n", *my_number2);
    my_free_block ();
    return 0;
}