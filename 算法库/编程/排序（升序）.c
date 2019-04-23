#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

void SortRArray(REAL array[],INTEGER size);//��������
void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size);//��ֵ�����ƣ� 
void ReverseRArray(REAL array[],INTEGER size);//���� 
void InputRArray(REAL array[],INTEGER size);
//����ȫ������Ԫ��
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��

int main()
{
	REAL a[maxRArraySize], b[maxRArraySize], c[maxRArraySize];
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
	SortRArray(b, n);
	CopyRArray(c, b, n);
	ReverseRArray(c, n);

	printf("����a:");
	OutputRArray(a, n);
	putchar('\n');

	printf("����b:");
	OutputRArray(b, n);
	putchar('\n');

	printf("����c:");
	OutputRArray(c, n);
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

void SortRArray(REAL array[],INTEGER size)//������������
{
	REAL x;
	int i,j;
	for(i = 1;i < size;i++)
	{
		if(array[i] < array[i - 1])
		{
			x = array[i];
			for(j = i - 1;j >= 0 && array[j] > x;j--)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = x;
		}
	}
}
