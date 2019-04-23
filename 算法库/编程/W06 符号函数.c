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

// ���ź���
REAL Sign(REAL x);

int main()
{
	REAL a, b;
	printf("a = ? ");
	scanf(RSF, &a);
	b = Sign(a);
	printf("b = " RPF "\n", b);
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

// ���ź���
REAL Sign(REAL x)
{
	REAL y;
	if (GT(x, 0)) // x > 0
	{
		y = 1.0;
	}
	else if (LT(x, 0)) // x < 0
	{
		y = -1.0;
	}
	else // x == 0
	{
		y = 0.0;
	}
	return y;
}

