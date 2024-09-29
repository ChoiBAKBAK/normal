/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
   int ch;
   char message[100];
   int i=0;
   while((ch=getchar())) !='\n')
   {
       message[i++]=ch;
   }
   message[i]='\0';
   printf("%s",message);
   return 0;
}