#include <stdio.h>


int main()
{
	int array[99];
	int count = 0;
	int i = 0;
	int sell = 0;
	printf("��ǰ ����(����) �Է�:");

	scanf_s("%d", &count);

	printf("��ǰ �� �԰� ���� �Է�:");

	for (i = 0; i < count; i++)
	{
		scanf_s("%d", &array[i]);
	}

	printf("��ǰ �� �Ǹż��� �Է�:");

	for (i = 0; i < count; i++)
	{
		scanf_s("%d", &sell);
		array[i] -= sell;
	}

	printf("ID�Է�:");

	scanf_s("%d", &sell);

	sell -= 1;

	printf("%d\n",array[sell]);

	for ( i = 0; i < count; i++)
	{
		printf("%d ",array[i]);
	}

	

		return 0;
}
