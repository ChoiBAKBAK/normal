/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char src[100];
    char dest[100];
    int length;
    gets(src);
    gets(dest);
    
    result=strcmp(src,dest);
    printf("result=%d\n",result);
    return 0;
}
