#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void FillRandomRArray(REAL array[],INTEGER size,REAL minValue,REAL maxValue);
//�������
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
	scanf(RSF, &lower);
	printf("����: ");
	scanf(RSF, &upper);
	FillRandomRArray(a, n, lower, upper);
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

void FillRandomRArray(REAL array[],INTEGER size,REAL minValue,REAL maxValue)
{
	
}
