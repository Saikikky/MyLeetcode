#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"
REAL MaxRArray(const REAL array[],INTEGER size);
REAL MinRArray(const REAL array[],INTEGER size);
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

	printf("最大值: " RPF "\n", MaxRArray(a, n));
	printf("最小值: " RPF "\n", MinRArray(a, n));
	return 0;
}

REAL MaxRArray(const REAL array[],INTEGER size)
{
	int k = 1,i;
	double t,q;
	for(i = 1;i < size;i++)
	{
		if(array[i]>array[k])
		{
			k = i;
			q = array[k];
		}
	}
	return q;
}

REAL MinRArray(const REAL array[],INTEGER size)
{
	int k = 1,i;
	double t,q;
	for(i = 1;i < size;i++)
	{
		if(array[i]<array[k])
		{
			k = i;
			q = array[k];
		}
	}
	return q;
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
