#include <iostream>
#include <windows.h>

int main() {
    unsigned char NAME[32],SERIAL[32];
    unsigned int eax,ebx,ecx,edx;

    printf("Enter a NAME: ");
    scanf("%s",NAME);

    eax=ebx=ecx=edx=0;

    while(NAME[ecx]!=0)     //assumption:esi string of null chars
    {
        edx=edx+NAME[ecx];
        eax=eax|edx;
        eax++;
        edx=(edx<<(ecx&0xff))|(edx>>(sizeof(edx)*8-(ecx&0xFF)));
        eax=~eax;
        ecx++;
        eax=eax+edx;
    }

    char s1[32],s2[32];
    wsprintfA(s1,"%X",edx);
    //wsprintfA(s2,"%X",eax);
    printf("%s",s1);
    return 0;
}