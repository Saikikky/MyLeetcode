#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void FillFibonacciRArray(REAL array[],INTEGER size);
//��value��䵽��������Ԫ��
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��
double Fib(int n);
//쳲��������� 
int main()
{
	REAL a[maxRArraySize];
	INTEGER n;

	printf("����: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("����ȷ������!");
		exit(1);
	}

	FillFibonacciRArray(a, n);

	printf("����:");
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
/////////ѭ�� 
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
/*�ݹ�
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
