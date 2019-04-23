#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"
REAL MaxRArray(const REAL array[],INTEGER size);
REAL MinRArray(const REAL array[],INTEGER size);
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

	printf("���ֵ: " RPF "\n", MaxRArray(a, n));
	printf("��Сֵ: " RPF "\n", MinRArray(a, n));
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
