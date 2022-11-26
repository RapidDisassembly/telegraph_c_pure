# telegraph_c_pure
Intended to translate between "plain text" (defined as a subset of ASCII) and a binary telegraph signal. This is for my own learning; the code will likely be suboptimal and may not be safe to execute.

The characters that will be considered are defined by the International\_Morse\_Code image file. They will be translated first into a string representing morse code, and then into a string representing the resulting telegraph signal.

This version will be written in pure C. I will write another version in C++.

I still need to decide how to handle conversion errors (parts of the telegraph signal that don't translate to morse, or parts of the morse that don't translate to text).
