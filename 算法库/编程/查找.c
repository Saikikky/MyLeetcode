#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

INTEGER FindRArray(const REAL array[],INTEGER size, REAL x);//����
void InputRArray(REAL array[],INTEGER size);
//����ȫ������Ԫ��
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��
int NE(REAL x, REAL y);

int main()
{
	REAL a[maxRArraySize], x;
	INTEGER n, r;

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

	printf("����: ");
	scanf(RSF, &x);
	r = FindRArray(a, n, x);
	
	if (r)
	{
		puts("���ҳɹ�!");
		printf("���: " IPF "\n", r);
	}
	else
	{
		puts("����ʧ��!");
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

 INTEGER FindRArray(const REAL array[],INTEGER size, REAL x)//����
 {
 	INTEGER k = 0,q;
 	while(NE(array[k],x) && k <= size)
 	{
 		k++;
 		q = k + 1;
 	}
 	if(k = size)
 	{
 		q = 0;
 	}
 	return q;
 } 
 
 int NE(REAL x,REAL y)
{
	return fabs(x-y)>epsilon;
}

