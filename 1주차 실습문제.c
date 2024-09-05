#include <stdio.h>


int main()
{
	int array[99];
	int count = 0;
	int i = 0;
	int sell = 0;
	printf("상품 개수(종류) 입력:");

	scanf_s("%d", &count);

	printf("상품 별 입고 수량 입력:");

	for (i = 0; i < count; i++)
	{
		scanf_s("%d", &array[i]);
	}

	printf("상품 별 판매수량 입력:");

	for (i = 0; i < count; i++)
	{
		scanf_s("%d", &sell);
		array[i] -= sell;
	}

	printf("ID입력:");

	scanf_s("%d", &sell);

	sell -= 1;

	printf("%d\n",array[sell]);

	for ( i = 0; i < count; i++)
	{
		printf("%d ",array[i]);
	}

	

		return 0;
}
