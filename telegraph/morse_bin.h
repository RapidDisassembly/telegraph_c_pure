#ifndef MORSE_BIN_H_INCLUDED
#define MORSE_BIN_H_INCLUDED

//int single_morse_to_bin(char morse_symbol, char * response_6_char_string);
//void single_morse_to_bin_test();

int morse_to_bin(char * morse_str, int morse_str_size, char * bin_str, int bin_str_size);
//void morse_to_bin_test();

int bin_to_morse(char * bin_str, int bin_str_size, char * morse_str, int morse_str_size);
void bin_to_morse_test();

#endif // MORSE_BIN_H_INCLUDED
