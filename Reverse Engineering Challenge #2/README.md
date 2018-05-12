https://challenges.re/2/

Q:What does this code do?

A:It returns a value obtained by reversing the order of the bits of the parameter

[31...0]=>[0...31]

Interesting stuff:
eax+eax=eax*eax which in this case basically means eax<<1 since its most significant bit is 0 after
and    eax,0x55555555;
0x55555555=01010101010101010101010101010101