#include "morse_bin.h"
#include <stdio.h>
#include <string.h>

/*  Converts a single character of morse code into the corresponding telegraph
    signal and writes it to a string buffer provided by the caller.*/
int single_morse_to_bin(char morse_symbol, char * response_6_char_string)
{
    switch(morse_symbol) {
    case '.' :
        strcpy(response_6_char_string,"100000");
        response_6_char_string[2] = '\0';
        return 2;
    case '-' :
        strcpy(response_6_char_string,"111000");
        response_6_char_string[4] = '\0';
        return 4;
    case ' ' :
        strcpy(response_6_char_string,"000000");
        response_6_char_string[2] = '\0';
        return 2;
    case '/' :
        strcpy(response_6_char_string,"000000");
        return 6;
    default:
        return -1;
    }
}

void single_morse_to_bin_test()
{
    char response[7];
    int r_length = single_morse_to_bin('.',response);

    for (int i = 0; i < r_length; i++) {
        putchar(response[i]);
    }
    printf("\n10\n\n");

    r_length = single_morse_to_bin('-',response);
    for (int i = 0; i < r_length; i++) {
        putchar(response[i]);
    }
    printf("\n1110\n\n");

    r_length = single_morse_to_bin('/',response);
    for (int i = 0; i < r_length; i++) {
        putchar(response[i]);
    }
    printf("\n000000\n\n");
}


/* Converts a morse signal [composed of dots (.), dashes (-), letter spaces ( )
   and word spaces (/)] into the corresponding telegraph signal, and writes
   the output into a writable string buffer provided by the caller. The function
   has to assume that the caller has provided 'honest' buffer sizes. Presumably,
   this could be worked around by more experienced C programmers.
*/
int morse_to_bin(char * morse_str, int morse_str_size, char * bin_str, int bin_str_size)
{
    bin_str[0] = '\0'; //The string buffer doesn't need to actually BE empty, just appear empty
    int bin_index = 0;

    //If this is true, it means that the string buffer provided for output is
    //probably not big enough. Immediate fail.
    if (bin_str_size < 4*morse_str_size) {
        return -1;
    }

    for (int i = 0; i < morse_str_size - 1; i++) {
        char single_response[7];
        int single_response_length = single_morse_to_bin(morse_str[i], single_response);

        //unexpected character
        if (single_response_length == -1) {
            bin_str[0] = '\0'; //"empty" the string
            return -1; //propagate the failure
        }

        //if there's enough remaining space in the string buffer
        if (single_response_length < (bin_str_size - bin_index)) {
            strcat(bin_str, single_response);
            bin_index += single_response_length;
        } else {
            bin_str[0] = '\0'; //"empty" the string
            return -1; //propagate the failure
        }
    }
    return 0;
}

void morse_to_bin_test()
{
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
    char out_2_correct[] = "";
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

    //Test 3: Buffer is big enough; unexpected characters cause failure
    char out_3_correct[] = "";
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

    //Test 4: Buffer is not big enough; unexpected characters cause failure
    char out_4_correct[] = "";
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

char single_bin_to_morse(char * bin_str, int initial_index)
{

}


int bin_to_morse(char * bin_str, int bin_str_size, char * morse_str, int morse_str_size)
{
    //User-provided string buffer is likely not big enough.
    //Immediate fail.
    if (4*morse_str_size < bin_str_size) {
        return -1;
    }
}

void bin_to_morse_test()
{
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

    //Test 3: Buffer is big enough; unexpected characters cause failure
    char out_3_correct[] = "";
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

    //Test 4: Buffer is not big enough; unexpected characters cause failure
    char out_4_correct[] = "";
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
