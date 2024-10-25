/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main()
{
    int s[SIZE];
    int most;
    int temp;
    srand(time(NULL));
    
    for(int i=0; i<SIZE; i++) {
        s[i]= (rand() % 1000)+1;
        
    }
    for(int i=0; i<SIZE-1; i++){//안에 있는 포문이 그 방의 제일 큰값을 찾을 때
        most=i;
        for(int j=i+1; j<SIZE; j++){
            if(s[most]<s[j]) most=j; // 반복
        }
        temp=s[i];
        s[i]=s[most];
        s[most]=temp; //정렬문
    }
    
    for(int i=0; i<SIZE; i++) {
        printf("s=%3d\t",s[i]);
        if((i+1)%10==0) printf("\n");
    }
    
    
    
    return 0;
}
