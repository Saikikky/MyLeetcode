#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

BOOL EQRArray(const REAL array1[],const REAL array2[],INTEGER size);
//�����������ӦԪ��ȫ����ͬ������ֵΪ1���棩������Ϊ0���٣�
BOOL NERArray(const REAL array1[],const REAL array2[],INTEGER size);
//�����������ӦԪ�ز�ȫ��ͬ������ֵΪ1���棩������Ϊ0���٣�
void InputRArray(REAL array[],INTEGER size);
//����ȫ������Ԫ��
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��
int NE(REAL x, REAL y);
int EQ(REAL x, REAL y);

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
	printf("����b: ");
	InputRArray(b, n);

	printf("����a:");
	OutputRArray(a, n);
	putchar('\n');
	printf("����b:");
	OutputRArray(b, n);
	putchar('\n');

	if (EQRArray(a, b, n))
	{
		puts("a == b");
	}
	if (NERArray(a, b, n))
	{
		puts("a != b");
	}
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

 int NE(REAL x,REAL y)
{
	return fabs(x-y)>epsilon;
}

int EQ(REAL x,REAL y)
{
	return fabs(x-y)<=epsilon;
}

BOOL EQRArray(const REAL array1[],const REAL array2[],INTEGER size)//�����������ӦԪ��ȫ����ͬ������ֵΪ1���棩������Ϊ0���٣�
{
	INTEGER k,ok = 1;
	for(k = 0;k < size;k++)
	{
	   if(EQ(array1[k],array2[k]))
	   {
	   	
	   }
	   else
	   {
	   	ok = 0;
	   	break;
	   }
	}
	return ok;
}

BOOL NERArray(const REAL array1[],const REAL array2[],INTEGER size)//�����������ӦԪ�ز�ȫ��ͬ������ֵΪ1���棩������Ϊ0���٣�
{
	INTEGER k,ok = 0;
	for(k = 0;k < size;k++)
	{
		while(NE(array1[k],array2[k]))
		{
			ok = 1;
			break;
		}
	}
	return ok;
}
