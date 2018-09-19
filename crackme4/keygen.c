#if 0
The user name must be at least 4 characters long.
aFunc and PrelucrareParola are functions called in the KeygenMe
They are not needed in this final version of the keygen
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int aFunc(char *String)
{
    long long esi=strlen(String);
    char al;
    int ecx,eax=0,ebx=0,edi=0;

    while(esi!=0)
    {
        al=String[edi];
        if(al<65)
            al=al-48;
        else
        {
            if(al-87>0)
                al=al+32;
            al=al-87;
        }
        ecx=esi-1;
        eax=(al&0x0F);
        eax=eax&0x0F;
        ecx=ecx<<2;
        eax=eax<<(ecx&0xFF);
        ebx=ebx+eax;
        edi++;
        esi--;
    }
    return ebx;
};
*/
/*
void prelucrareParola(char * sir)
{
    int i,L=strlen(sir);
    for(i=0;i<L;i++)
    {
        if(sir[i]=='-')
        {
            sir[i]=0;
        }
    }
}
*/
int main() {
    char USER[40],PAROLA[4][9];
    int i=0,j;

    printf("USER: ");
    scanf("%s",USER);

    unsigned AUXparola=0x401284,lengthUSER,ebx,eax;
    for(j=3;j>=0;j--)
    {
        lengthUSER=strlen(USER);
        ebx=0;
        i=0;
        while (lengthUSER)
        {
            if (USER[i] != ' ')
            {
                eax = USER[i];
                eax = eax & 0xFF;
                eax = eax * AUXparola;
                eax = (eax >> 19) | (eax << (sizeof(eax) * 8 - 19));
                ebx = ebx + eax;
            }
        i++;
        lengthUSER--;
        }
        sprintf(PAROLA[j], "%X", ebx);
        AUXparola=ebx;
    }

    printf("Serial: %s-%s-%s-%s",PAROLA[0],PAROLA[1],PAROLA[2],PAROLA[3]);
    return 0;
}