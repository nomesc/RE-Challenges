RDI and RDX have the adress of a char array  
RSI has the number of chars in the RDI array  
RCX has the numbar of chars int the RDX array

The function returns the addres of the first array from RDI that begins  
with the first RCX chars (int the same order) from the RDX array.

eg:  
char rdi[]="xxxxxxxxxxxxfffabcfffabc",rdx[]="fabc";  
unsigned int rsi=24,rcx=4;  
RAX will have the address of the fabcfffabc array.  
