#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"
REAL SumRArry(const REAL array[],INTEGER size);
REAL AvgRArry(const REAL array[],INTEGER size);
void InputRArray(REAL array[],INTEGER size);
//输入全部数组元素
void OutputRArray(REAL array[],INTEGER size);
//输出全部数组元素

int main()
{
	REAL a[maxRArraySize], lower, upper;
	INTEGER n;

	printf("项数: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("不正确的项数!");
		exit(1);
	}

	printf("数组: ");
	InputRArray(a, n);

	printf("数组:");
	OutputRArray(a, n);
	putchar('\n');

	printf("总  和: " RPF "\n", SumRArray(a, n));
	printf("平均值: " RPF "\n", AvgRArray(a, n));
	return 0;
}

void InputRArray(REAL array[],INTEGER size)//输入 
{
	int k;
	for(k = 0;k < size;k++)
	{
		scanf("%lg",&array[k]);
	}
}

void OutputRArray(REAL array[],INTEGER size)//输出 
{
	int k;
	for(k = 0;k < size;k++)
	{
		printf(" %g",array[k]);
	}
}

REAL SumRArry(const REAL array[],INTEGER size)
{
	double t;
	int k;
	for(k = 1;k < size;k++)
	{
		t += array[k];
	}
	return t;
}

REAL AvgRArry(const REAL array[],INTEGER size)
{
	double t,q;
	int k;
	for(k = 1;k < size;k++)
	{
		t += array[k];
	}
	q = t / size;
	return q;
}

