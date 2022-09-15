#include "morse_bin.h"
#include <stdio.h>

void morse_to_bin(char * morse_str, int morse_size, char * bin_str, int bin_size)
{
    int i = 0; //track where you are on the morse string
    int j = 0; //track where you are on the binary string
    int a = -1; //track where you are within a character; initialised to a deliberately nonsensical value
    int response_high;
    int response_low;
    char c;
    char response[] = "111000000";

    while ((i < morse_size) && (j < bin_size))  //while we still have morse input AND space for binary output
    {
        if (a == -1)   //if we need to decode the next character, do so
        {
            c = morse_str[i];
            switch (c) //encode the character from morse to binary
            {
            case '.' :
                response_low = 2;
                response_high = 4;
                break;
            case '-' :
                response_low = 0;
                response_high = 4;
                break;
            case ' ' :
                response_low = 3;
                response_high = 5;
                break;
            case '/' :
                response_low = 3;
                response_high = 9;
                break;
            }
            i++;
            a = response_low;
        }

        if (a < response_high) //if we have not finished outputting the binary representation of the morse character
        {
            bin_str[j] = response[a];
            a++;
            j++;
        }
        else
        {
            a = -1;
        }
    }
    while((a < response_high) && (j < bin_size)) //previous while loop stops at the beginning of the last morse character (whoops!)
    {
        bin_str[j] = response[a];
        a++;
        j++;
    }
}
