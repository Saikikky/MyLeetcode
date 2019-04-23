#include <stdio.h>
#include <math.h>
#include "MyMath.h"

// �жϴ���
BOOL GT(REAL x, REAL y);
// �жϴ��ڵ���
BOOL GE(REAL x, REAL y);
// �ж�С��
BOOL LT(REAL x, REAL y);
// �ж�С�ڵ���
BOOL LE(REAL x, REAL y);
// �жϵ���
BOOL EQ(REAL x, REAL y);
// �жϲ�����
BOOL NE(REAL x, REAL y);

int main()
{
	REAL a, b;
	printf("a = ? ");
	scanf(RSF, &a);
	printf("b = ? ");
	scanf(RSF, &b);
	if (GT(a, b))
	{
		puts("a > b");
	}
	if (GE(a, b))
	{
		puts("a >= b");
	}
	if (LT(a, b))
	{
		puts("a < b");
	}
	if (LE(a, b))
	{
		puts("a <= b");
	}
	if (EQ(a, b))
	{
		puts("a == b");
	}
	if (NE(a, b))
	{
		puts("a != b");
	}
	return 0;
}

// �жϴ���
BOOL GT(REAL x, REAL y)
{
	return x > y + epsilon;
}

// �жϴ��ڵ���
BOOL GE(REAL x, REAL y)
{
	return x >= y - epsilon;
}

// �ж�С��
BOOL LT(REAL x, REAL y)
{
	return x < y - epsilon;
}

// �ж�С�ڵ���
BOOL LE(REAL x, REAL y)
{
	return x <= y + epsilon;
}

// �жϵ���
BOOL EQ(REAL x, REAL y)
{
	return x >= y - epsilon && x <= y + epsilon;
}

// �жϲ�����
BOOL NE(REAL x, REAL y)
{
	return x < y - epsilon || x > y + epsilon;
}

