/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


void display_menu()
{
   
    printf("원하는 메뉴를 입력하세요.:(1. 입고, 2. 종료)\n");

}

int main()
{
    char choice;
    int i=0;
    
   while(1)
    {
        display_menu();
        printf(" ");
        choice = getchar();
        getchar();
    
        switch(choice)
        {
        case '1' : printf("입고수량 입력:전체 상품 입고 수량 입력 1 , 개별 상품 입력 2 \n");
        continue;
        if(i)
        {
            printf("");
        
        }
       
        case '2' :printf("종료");
        return 0;
        
        default:
        printf("잘못된 선택");
        break;
        }
    
    }
   return 0;
}