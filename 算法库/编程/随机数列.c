#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void FillRandomRArray(REAL array[],INTEGER size,REAL minValue,REAL maxValue);
//随机数列
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

	printf("下限: ");
	scanf(RSF, &lower);
	printf("上限: ");
	scanf(RSF, &upper);
	FillRandomRArray(a, n, lower, upper);
	printf("数组:");
	OutputRArray(a, n);
	putchar('\n');
	return 0;
}


void OutputRArray(REAL array[],INTEGER size)
{
	int k;
	for(k = 0;k < size;k++)
	{
		printf(" %g",array[k]);
	}
}

void FillRandomRArray(REAL array[],INTEGER size,REAL minValue,REAL maxValue)
{
	
}
