#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size);//��ֵ�����ƣ� 
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

	printf("����a:");
	OutputRArray(a, n);
	putchar('\n');

	printf("����b:");
	OutputRArray(b, n);
	putchar('\n');
	return 0;
}

void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size)//��ֵ�����ƣ� 
{
	int k;
	for(k = 0;k < size;k++)
	{
		dstArray[k] = srcArray[k];
	} 
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
