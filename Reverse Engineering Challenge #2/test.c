#include <iostream>

using namespace std;

union numar
{
    unsigned int x;
    char byte[4];
};

int main() {
    numar eax,edx;
    eax.x=5152;

    cout<<eax.x<<endl;

    edx.byte[3]=eax.byte[0];
    edx.byte[2]=eax.byte[1];
    edx.byte[1]=eax.byte[2];
    edx.byte[0]=eax.byte[3];

    eax.x=edx.x;

    eax.x=(eax.x)&0x0f0f0f0f;
    edx.x=(edx.x)&0xf0f0f0f0;
    eax.x=(eax.x)<<4;
    edx.x=edx.x>>4;
    eax.x=eax.x|edx.x;
    edx.x=eax.x;

    eax.x=eax.x&0x33333333;
    edx.x=edx.x&0xcccccccc;
    eax.x=eax.x<<2;
    edx.x=edx.x>>2;
    eax.x=eax.x|edx.x;
    edx.x=eax.x;

    eax.x=eax.x&0x55555555;
    edx.x=edx.x&0xaaaaaaaa;
    eax.x=eax.x*2;
    edx.x=edx.x>>1;
    eax.x=eax.x|edx.x;
    cout<<eax.x;
    return 0;
}