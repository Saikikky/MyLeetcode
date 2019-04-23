#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void FillFibonacciRArray(REAL array[],INTEGER size);
//将value填充到数组所有元素
void OutputRArray(REAL array[],INTEGER size);
//输出全部数组元素
double Fib(int n);
//斐波那契数列 
int main()
{
	REAL a[maxRArraySize];
	INTEGER n;

	printf("项数: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("不正确的项数!");
		exit(1);
	}

	FillFibonacciRArray(a, n);

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

void FillFibonacciRArray(REAL array[],INTEGER size)
{
	 int k;
	 double p;
	 for(k = 0;k < size;k++)
	 {
	 	p = Fib(k + 1);
	 	array[k] = p;
	 }
}  
/////////循环 
double Fib(int n)
{
	double f1 = 1.0,f2 = 1.0,f = 1.0;
	int k;
	for(k = 3;k <= n;k++)
	{
		f = f1 + f2;
		f1 = f2;
		f2 = f;
	}
	return f;
} 
/*递归
double Fib(int n)
{
	double f;
	if(n <= 2)
	{
		f = 1.0;
	}
	else
	{
		f = Fib(n - 1) + Fib(n - 2);  
	}
	return f;
}*/
