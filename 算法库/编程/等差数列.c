#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void FillArithmeticRArray(REAL array[],INTEGER size,REAL start,REAL increment);
//等差数列（将首项为start，增量为increment的等差数列填充到数组中。）
void OutputRArray(REAL array[],INTEGER size);
//输出全部数组元素

int main()
{
	REAL a[maxRArraySize], f, d;
	INTEGER n;

	printf("项数: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("不正确的项数!");
		exit(1);
	}

	printf("首项: ");
	scanf(RSF, &f);
	printf("增量: ");
	scanf(RSF, &d);
	FillArithmeticRArray(a, n, f, d);

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

void FillArithmeticRArray(REAL array[],INTEGER size,REAL start,REAL increment)
{
	int k;
	double p = start;
	for(k = 0;k < size;k++)
	{
		array[k] = p;
		p += increment;
	}
} 
