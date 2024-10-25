/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int s[100];
    int total;
    int max,min;
    float avg=0.0;
    
    srand(time(NULL));
    
    for(int i=0; i<100; i++) {
        s[i]= (rand() % 1000)+1;
        
    }
    for(int i=0; i<10; i++) {
        total +=s[i];
    }
    
    for(int i=0; i<100; i++) {
        printf("s=%3d\t",s[i]);
        if((i+1)%5==0) printf("\n");
    }
    avg= (float)total / 100.0; //평균값과 형변환(float)
    max=s[0];
    min=s[0];
    for(int i=0; i<100; i++){
        if(max<s[i]) max=s[i]; //최대값
        if(min>s[i]) min=s[i]; //최소값
    }
    printf("max=%d min=%d %f",max,min,avg);
    
    
    
    return 0;
}
