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

// һԪһ�η���
//  0 �޽�
// -1 Ψһ��
// -2 ������
INTEGER LinearEquation(REAL *x, REAL a, REAL b);

int main()
{
	INTEGER r;
	REAL a, b, x;
	puts("һԪһ�η��� ax + b = 0");
	printf("a, b = ? ");
	scanf(RSF RSF, &a, &b);

	r = LinearEquation(&x, a, b);

	if (0 == r)
	{
		puts("�޽�");
	}
	else if (-1 == r)
	{
		printf("Ψһ��: x = " RPF "\n", x);
	}
	else if (-2 == r)
	{
		puts("������");
	}
	else
	{
		puts("�쳣");
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

// һԪһ�η���
//  0 �޽�
// -1 Ψһ��
// -2 ������
INTEGER LinearEquation(REAL *x, REAL a, REAL b)
{
	INTEGER r;
	if (NE(a, 0)) // a != 0
	{
		r = -1; // Ψһ��
		*x = -b / a;
	}
	else // a == 0
	{
		if (NE(b, 0)) // b != 0
		{
			r = 0; // �޽�
		}
		else // b == 0
		{
			r = -2; // ������
		}
	}
	return r;
}

