#include "morse_bin.h"
#include <stdio.h>
#include <string.h>

/*
    In this struct, "bin" can vary from three characters ("10\0" for a dot), to
    7 characters ("000000\0" for a space between words).
    As I understand it, my options were:
    1: Make an array with the largest possible size. This would allow the array
    to be statically/automatically allocated, which means I don't have to think
    about it.
    2: Dynamically allocate the array. This would approximately halve the memory
    use if I did it correctly, but means I would have to manually free the
    array before the struct went out of scope (I think?).
    3: Use a flexible array member. I don't yet understand the implications of
    this approach, so I have disqualified this.
    For the time being, I have picked (1) because I'm still learning the basics.
*/
struct MorseBinMapping {
    char[7] bin_string;
    int bin_string_size;
    char morse_character;
}

