#include "morse_bin.h"
#include <stdio.h>

/* Converts a morse signal [composed of dots (.), dashes (-), letter spaces ( )
   and word spaces (/)] into the corresponding telegraph signal, and writes
   the output into a string buffer provided by the caller. Has the typical C
   problem in which the function has to assume that the caller has provided
   'honest' buffer sizes.
*/
void morse_to_bin(char * morse_str, int morse_str_size, char * bin_str, int bin_str_size)
{
    int k = 0; //track where you are on the binary string
    int response_high;
    int response_low;
    char response[] = "111000000";

    for (int i = 0; i < morse_str_size; i++) //for each character in the input string
    {
        switch(morse_str[i]) //translate the morse character into binary by taking appropriate slices of the "response" string
        {
        case '.':
            response_low = 2;
            response_high = 4;
            break;
        case '-':
            response_low = 0;
            response_high = 4;
            break;
        case ' ':
            response_low = 3;
            response_high = 5;
            break;
        case '/':
            response_low = 3;
            response_high = 9;
            break;
        }
        for (int j = response_low; j < response_high; j++) //add the binary representation to the output
        {
            if (k < bin_str_size - 1) //if there is space in the output string before the null termination character, append another character
            {
                bin_str[k] = response[j];
                k++;
            }
        }
    }
    bin_str[bin_str_size - 1] = '\0'; //guarding against the case that the null terminator is overwritten
}
