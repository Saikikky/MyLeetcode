#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void InputRArray(REAL array[],INTEGER size);
//����ȫ������Ԫ��
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��

int main()
{
	REAL a[maxRArraySize];
	INTEGER n;

	printf("����: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("����ȷ������!");
		exit(1);
	}

	// ��������
	printf("����: ");
	InputRArray(a, n);

	// �������
	printf("����:");
	OutputRArray(a, n);
	putchar('\n');
	return 0;
}

void InputRArray(REAL array[],INTEGER size)
{
	int k;
	for(k = 0;k < size;k++)
	{
		scanf("%lg",&array[k]);
	}
}

void OutputRArray(REAL array[],INTEGER size)
{
	int k;
	for(k = 0;k < size;k++)
	{
		printf(" %g",array[k]);
	}
}
