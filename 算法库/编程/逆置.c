#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"
void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size);//��ֵ�����ƣ� 
void ReverseRArray(REAL array[],INTEGER size);//���� 
void InputRArray(REAL array[],INTEGER size);
//����ȫ������Ԫ��
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��

int main()
{
	REAL a[maxRArraySize], b[maxRArraySize];
	INTEGER n;

	printf("����: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("����ȷ������!");
		exit(1);
	}

	printf("����a: ");
	InputRArray(a, n);

	CopyRArray(b, a, n);
	ReverseRArray(b, n);

	printf("����a:");
	OutputRArray(a, n);
	putchar('\n');

	printf("����b:");
	OutputRArray(b, n);
	putchar('\n');
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

void ReverseRArray(REAL array[],INTEGER size)//���� 
{
	REAL c[maxRArraySize];
	int k,i = size - 1;
	CopyRArray(c, array, size);
	for(k = 0;k < size;k++)
	{
		array[i] = c[k];
		i--;
	}
}

void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size)
{
	int k;
	for(k = 0;k < size;k++)
	{
		dstArray[k] = srcArray[k];
	} 
}
