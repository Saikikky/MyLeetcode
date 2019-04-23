#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

INTEGER FindRArray(const REAL array[],INTEGER size, REAL x);//查找
void InputRArray(REAL array[],INTEGER size);
//输入全部数组元素
void OutputRArray(REAL array[],INTEGER size);
//输出全部数组元素
int NE(REAL x, REAL y);

int main()
{
	REAL a[maxRArraySize], x;
	INTEGER n, r;

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

	printf("查找: ");
	scanf(RSF, &x);
	r = FindRArray(a, n, x);
	
	if (r)
	{
		puts("查找成功!");
		printf("序号: " IPF "\n", r);
	}
	else
	{
		puts("查找失败!");
	}
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

 INTEGER FindRArray(const REAL array[],INTEGER size, REAL x)//查找
 {
 	INTEGER k = 0,q;
 	while(NE(array[k],x) && k <= size)
 	{
 		k++;
 		q = k + 1;
 	}
 	if(k = size)
 	{
 		q = 0;
 	}
 	return q;
 } 
 
 int NE(REAL x,REAL y)
{
	return fabs(x-y)>epsilon;
}

