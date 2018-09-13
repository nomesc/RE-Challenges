The username must be between 5 and 49 charcters.  
There is a function func(char*,char*,...) that gets as arguments a pointer to a char array, the string "%lX" and EAX.  
The password and the array of characters are the compared using lstrcmpA.  
So we need to see what that function does and how is EAX calculated.  
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
this is the eax that will be given to the function as one of the arguments.  
The function had a huge jumptable but I observed that it checkd for '%' characters and treated the "%%" cases.  
I assumed it is a implementation of the wsprintfA function.  
I tested this but the passwords were only working when they had no letters(A,B,C,D,E,F).  
I thought I was wrong and have to really look at that jumptable.  
Fortunately it was just that I put a lower case 'x'("%lx") insted of upper case in the keygen.  
