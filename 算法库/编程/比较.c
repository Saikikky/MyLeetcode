#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

BOOL EQRArray(const REAL array1[],const REAL array2[],INTEGER size);
//若两个数组对应元素全部相同，则函数值为1（真），否则为0（假）
BOOL NERArray(const REAL array1[],const REAL array2[],INTEGER size);
//若两个数组对应元素不全相同，则函数值为1（真），否则为0（假）
void InputRArray(REAL array[],INTEGER size);
//输入全部数组元素
void OutputRArray(REAL array[],INTEGER size);
//输出全部数组元素
int NE(REAL x, REAL y);
int EQ(REAL x, REAL y);

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
	printf("数组b: ");
	InputRArray(b, n);

	printf("数组a:");
	OutputRArray(a, n);
	putchar('\n');
	printf("数组b:");
	OutputRArray(b, n);
	putchar('\n');

	if (EQRArray(a, b, n))
	{
		puts("a == b");
	}
	if (NERArray(a, b, n))
	{
		puts("a != b");
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

 int NE(REAL x,REAL y)
{
	return fabs(x-y)>epsilon;
}

int EQ(REAL x,REAL y)
{
	return fabs(x-y)<=epsilon;
}

BOOL EQRArray(const REAL array1[],const REAL array2[],INTEGER size)//若两个数组对应元素全部相同，则函数值为1（真），否则为0（假）
{
	INTEGER k,ok = 1;
	for(k = 0;k < size;k++)
	{
	   if(EQ(array1[k],array2[k]))
	   {
	   	
	   }
	   else
	   {
	   	ok = 0;
	   	break;
	   }
	}
	return ok;
}

BOOL NERArray(const REAL array1[],const REAL array2[],INTEGER size)//若两个数组对应元素不全相同，则函数值为1（真），否则为0（假）
{
	INTEGER k,ok = 0;
	for(k = 0;k < size;k++)
	{
		while(NE(array1[k],array2[k]))
		{
			ok = 1;
			break;
		}
	}
	return ok;
}
