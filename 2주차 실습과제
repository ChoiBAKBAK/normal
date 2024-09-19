#include <stdio.h>

int main()
{
    int array[99];
    int sellitem[99];
    int count = 0;
    int max = 0;
    int min = 1;
    int nummax= 0;
    int nummin = 0;
    int countID = 0;
    float Allsell = 0;
    float Allitem = 0;
    int i = 0;
   printf("상품 개수(종류) 입력:");
   scanf("%d", &count);
   printf("상품 별 입고 수량 입력:");
   for (i = 0; i < count; i++)
   {
      scanf("%d", &array[i]);
   }
   printf("상품 별 판매수량 입력:");
   for(i = 0; i < count; i++) scanf("%d",&sellitem[i]);
   for (i = 0; i < count; i++) Allitem +=array[i];
   for(i = 0; i < count; i++) if(sellitem[i]>max) max = sellitem[i];
   for(i = 0; i < count; i++)
    {
        nummax++;
        if(max == sellitem[i])
        {
            break;
        }
    }
    for(i = 0; i < count; i++) if(sellitem[i]<min) min = sellitem[i];
    for(i = 0; i < count; i++)
    {
        nummin++;
        if(min == sellitem[i])
        {
            break;
        }
    }
    for(i = 0; i< count; i++) array[i] -= sellitem[i];
    printf("\n재고수량: ");
    for(i = 0; i < count; i++)
    printf("%d ", array[i]);
    for(i = 0; i < count; i++) Allsell += sellitem[i];
    printf("\n총 판매량 : %2.0f(판매율 %0.2f)",Allsell,Allsell/Allitem*100);
    printf("\n가장많이 판매된 상품 : ID %d, 판매량 %d\n가장적게 판매된 상품 : ID %d, 판매량 %d",nummax,max,nummin,min);
    for(i = 0; i< count; i++)
    {
        countID++;
        if(array[i]<3)
        {
            printf("\n상품 ID %d : 재고부족(%d)",countID,array[i]);
        }
    }
    return 0;
}
