/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int x,y,ch;
    char buffer[100];
    
    fscanf(stdin,"%d %d",&x,&y);
    fprintf(stdout,"%d %d",x,y);
    while((ch=getchar())!='\n');
    fgets(buffer,100,stdin);
    fputs(buffer,stdout);

    return 0;
}
