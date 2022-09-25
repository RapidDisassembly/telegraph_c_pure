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
        default:
            response_low = 6;
            response_high = 6;
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

/*
void morse_to_bin_test() {
    //Test 1: Buffer is large enough, no unexpected characters
    char out_1_correct[] = "10000000111000";
    char in_1[] = "./- ";
    int size_in_1 = 5;
    char out_1[40];
    int size_out_1 = 40;
    morse_to_bin(in_1,size_in_1,out_1,size_out_1);
    printf("case 1\n");
    printf(out_1);
    printf("\n");
    printf(out_1_correct);
    printf("\n");

    //Test 2: Buffer is too small, no unexpected characters
    char out_2_correct[] = "100";
    char in_2[] = "./- ";
    int size_in_2 = 5;
    char out_2[4];
    int size_out_2 = 4;
    morse_to_bin(in_2,size_in_2,out_2,size_out_2);
    printf("case 2\n");
    printf(out_2);
    printf("\n");
    printf(out_2_correct);
    printf("\n");

    //Test 3: Buffer is big enough; unexpected characters are silently dropped
    char out_3_correct[] = "10100000001110";
    char in_3[] = "..y/-";
    int size_in_3 = 6;
    char out_3[70];
    int size_out_3 = 70;
    morse_to_bin(in_3,size_in_3,out_3,size_out_3);
    printf("case 3\n");
    printf(out_3);
    printf("\n");
    printf(out_3_correct);
    printf("\n");

    //Test 4: Buffer is not big enough; unexpected characters are silently dropped
    char out_4_correct[] = "101000";
    char in_4[] = "..y/-";
    int size_in_4 = 6;
    char out_4[7];
    int size_out_4 = 7;
    morse_to_bin(in_4,size_in_4,out_4,size_out_4);
    printf("case 4\n");
    printf(out_4);
    printf("\n");
    printf(out_4_correct);
    printf("\n");
}
*/

void bin_to_morse(char * bin_str, int bin_str_size, char * morse_str, int morse_str_size)
{
}

void bin_to_morse_test() {
    //Test 1: Buffer is large enough, no unexpected characters
    char out_1_correct[] = "..- .-/.-";
    char in_1[] = "1010111000101110000000101110";
    int size_in_1 = 29;
    char out_1[15];
    int size_out_1 = 15;
    bin_to_morse(in_1,size_in_1,out_1,size_out_1);
    printf("case 1\n");
    printf(out_1);
    printf("\n");
    printf(out_1_correct);
    printf("\n");

    //Test 2: Buffer is too small, no unexpected characters
    char out_2_correct[] = "..-";
    char in_2[] = "1010111000101110000000101110";
    int size_in_2 = 29;
    char out_2[4];
    int size_out_2 = 4;
    bin_to_morse(in_2,size_in_2,out_2,size_out_2);
    printf("case 2\n");
    printf(out_2);
    printf("\n");
    printf(out_2_correct);
    printf("\n");

    //Test 3: Buffer is big enough; unexpected characters are silently dropped
    char out_3_correct[] = "..- .-/.-";
    char in_3[] = "1010y111000101110000000n101110";
    int size_in_3 = 31;
    char out_3[10];
    int size_out_3 = 10;
    bin_to_morse(in_3,size_in_3,out_3,size_out_3);
    printf("case 3\n");
    printf(out_3);
    printf("\n");
    printf(out_3_correct);
    printf("\n");

    //Test 4: Buffer is not big enough; unexpected characters are silently dropped
    char out_4_correct[] = "..-";
    char in_4[] = "101011y1000101110000-000101110";
    int size_in_4 = 29;
    char out_4[4];
    int size_out_4 = 4;
    bin_to_morse(in_4,size_in_4,out_4,size_out_4);
    printf("case 4\n");
    printf(out_4);
    printf("\n");
    printf(out_4_correct);
    printf("\n");
}
