#include <stdio.h>
#include <stdlib.h>
#include "morse_bin.h"

int main()
{
    char b[] = ".--. ..-/.--";
    int b_size = 12;
    char c[10];
    int c_size = 10;
    morse_to_bin(b,b_size,c,c_size);
    printf(c);
}
