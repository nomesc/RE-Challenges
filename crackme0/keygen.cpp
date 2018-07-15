#include <cstdio>
#include <cstring>

union REGISTER
{
    int val;
    char byte[4];
    short H[2];
};

int main() {
    REGISTER eax,ebx;
    char *MEM;
    int length;
    MEM=new char[1000];
    do{
        fgets(MEM,255,stdin);
    }
    while(strlen(MEM)<3);
    MEM[strlen(MEM)-1]='\0';
    length=strlen(MEM);
    for(eax.val=0;eax.val<length;eax.val++)
    {
        ebx.byte[0]=MEM[eax.val];
        ebx.byte[1]=0;
        if(ebx.byte[0]=='Z')ebx.byte[0]--;
        if(ebx.byte[0]=='z')ebx.byte[0]--;
        if(ebx.byte[0]=='9')ebx.byte[0]--;
        eax.val=eax.val+'a';
        ebx.byte[1]=ebx.byte[1]+eax.byte[0];
        ebx.byte[0]++;
        eax.val=eax.val-'a';
        MEM[6+eax.val*2]=ebx.byte[0];
        MEM[6+eax.val*2+1]=ebx.byte[1];
    }
    MEM[6+length*2]='\0';
    printf("\n%s\n",MEM+6);
    return 0;
}