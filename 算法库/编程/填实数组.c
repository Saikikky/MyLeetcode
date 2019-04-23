#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void FillValueRArray(REAL array[],INTEGER size,REAL value);
//填实数值 
void InputRArray(REAL array[],INTEGER size);
//输入全部数组元素
void OutputRArray(REAL array[],INTEGER size);
//输出全部数组元素

int main()
{
	REAL a[maxRArraySize], x;
	INTEGER n;

	printf("项数: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("不正确的项数!");
		exit(1);
	}

	printf("填充: ");
	scanf(RSF, &x);
	FillValueRArray(a, n, x);

	printf("数组:");
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
