#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"
REAL SumRArry(const REAL array[],INTEGER size);
REAL AvgRArry(const REAL array[],INTEGER size);
void InputRArray(REAL array[],INTEGER size);
//����ȫ������Ԫ��
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��

int main()
{
	REAL a[maxRArraySize], lower, upper;
	INTEGER n;

	printf("����: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("����ȷ������!");
		exit(1);
	}

	printf("����: ");
	InputRArray(a, n);

	printf("����:");
	OutputRArray(a, n);
	putchar('\n');

	printf("��  ��: " RPF "\n", SumRArray(a, n));
	printf("ƽ��ֵ: " RPF "\n", AvgRArray(a, n));
	return 0;
}

void InputRArray(REAL array[],INTEGER size)//���� 
{
	int k;
	for(k = 0;k < size;k++)
	{
		scanf("%lg",&array[k]);
	}
}

void OutputRArray(REAL array[],INTEGER size)//��� 
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

