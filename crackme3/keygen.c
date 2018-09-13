#include <stdio.h>
#include <string.h>

int main() {
    char username[50];
    unsigned int lengthusername,ok;
    do
    {
        fgets(username, 50, stdin);
        lengthusername=strlen(username)-1;
        username[lengthusername] = 0;
        if((lengthusername<=4)||(lengthusername>=50))
        {
            ok=0;
            printf("Username must be 5 or more characters and 49 or less\n");
        }
        else
            ok=1;
    }
    while(!ok);

    unsigned long int ecx,eax,ebx;
    ecx=eax=ebx=0;
    ok=1;
    while(ok)
    {
        eax=(unsigned int)username[ecx];
        ecx++;
        eax=eax^ecx;
        ebx=ebx+eax;
        ok=lengthusername-ecx;
    }

    eax=eax*6;
    ebx=ebx*128;
    eax=eax+ebx;

    printf("Parola: %lX",eax);

    return 0;
}