#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void FillGeometricRArray(REAL array[],INTEGER size,REAL start,REAL ratio);
//������Ϊstart������Ϊratio�ĵȱ�������䵽�����С�
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��

int main()
{
	REAL a[maxRArraySize], f, r;
	INTEGER n;

	printf("����: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("����ȷ������!");
		exit(1);
	}

	printf("����: ");
	scanf(RSF, &f);
	printf("����: ");
	scanf(RSF, &r);
	FillGeometricRArray(a, n, f, r);

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
 
void FillGeometricRArray(REAL array[],INTEGER size,REAL start,REAL ratio)
{
	int k;
	double p = start;
	for(k = 0;k < size;k++)
	{
		array[k] = p;
		p *= ratio;
	}
}
