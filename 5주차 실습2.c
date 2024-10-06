/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char input[200]="";
    int count[26]={0};
    int ch;
    int i=0;
    
    while((ch=getchar())!=EOF){
        input[i++]=ch;
    }
    i=0;
    while(input[i]!='\0'){
        if(input[i]>='a'&&input[i]<='z'){
            count[input[i]-'a']++;
        }
        i++;
    }
    printf("입력 문자열:%s\n",input);
    for(int i=0;i<26;i++) printf("%c 출현 횟수:%d\n",'a'+i,count[i]);
    return 0;
}
