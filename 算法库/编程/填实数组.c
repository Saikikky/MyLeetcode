#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void FillValueRArray(REAL array[],INTEGER size,REAL value);
//��ʵ��ֵ 
void InputRArray(REAL array[],INTEGER size);
//����ȫ������Ԫ��
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��

int main()
{
	REAL a[maxRArraySize], x;
	INTEGER n;

	printf("����: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("����ȷ������!");
		exit(1);
	}

	printf("���: ");
	scanf(RSF, &x);
	FillValueRArray(a, n, x);

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

void FillValueRArray(REAL array[],INTEGER size,REAL value)
{
	int k;
	for(k = 0;k < size;k++)
	{
		array[k] = value;
	}
} 
