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

// ��������
REAL Round(REAL x);

int main()
{
	REAL x, y;
	printf("x = ? ");
	scanf(RSF, &x);
	y = Round(x);
	printf("y = " RPF "\n", y);
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

// ��������
REAL Round(REAL x)
{
	double y;
	if (GT(x, 0))
	{
		y = floor(x + 0.5 + epsilon);
	}
	else
	{
		y = ceil(x - 0.5 - epsilon);
	}
	return y;
}

