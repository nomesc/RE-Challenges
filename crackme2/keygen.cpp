#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
    char *username,*NAME;
    username=new char[100];
    long unsigned int *size=new long unsigned int;
    *size=10;
    GetUserNameA(username,size);
    //printf("user: %s\n",username);

    NAME=new char[100];
    printf("NAME=");
    scanf("%s",NAME);
    //printf("\nNAME: %s\n",NAME);


    int var_8=0,var_4=0;
    while(var_4<strlen(username))
    {
        var_8=username[var_4]+0x186A0+var_8;
        var_4++;
    }

    var_4=0;
    while(var_4<strlen(NAME))
    {
        var_8=NAME[var_4]+0x186A0+var_8;
        var_4++;
    }

    //printf("\nvar_8: %d\n",var_8);

    var_8=var_8+0x7A69;
    char PASS[100];
    wsprintfA(PASS,"RS-%ld",var_8);

    printf("\nPASS: %s\n",PASS);

    return 0;
}