#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size);//赋值（复制） 
void InputRArray(REAL array[],INTEGER size);
//输入全部数组元素
void OutputRArray(REAL array[],INTEGER size);
//输出全部数组元素

int main()
{
	REAL a[maxRArraySize], b[maxRArraySize];
	INTEGER n;

	printf("项数: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("不正确的项数!");
		exit(1);
	}

	printf("数组a: ");
	InputRArray(a, n);

	CopyRArray(b, a, n);

	printf("数组a:");
	OutputRArray(a, n);
	putchar('\n');

	printf("数组b:");
	OutputRArray(b, n);
	putchar('\n');
	return 0;
}

void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size)//赋值（复制） 
{
	int k;
	for(k = 0;k < size;k++)
	{
		dstArray[k] = srcArray[k];
	} 
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
