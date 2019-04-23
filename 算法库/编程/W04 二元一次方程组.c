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

// ��Ԫһ�η�����
// a1x + b1y = c1
// a2x + b2y = c2
//  0 �޽�
//  1 Ψһ��
//  2 ������
INTEGER EquationGroup(REAL *x, REAL *y, REAL a1, REAL b1, REAL c1, REAL a2, REAL b2, REAL c2);

int main()
{
	INTEGER r;
	REAL a1, b1, c1, a2, b2, c2, x, y;
	puts("��Ԫһ�η�����");
	puts("a1x + b1y = c1");
	puts("a2x + b2y = c2");
	printf("a1, b1, c1 = ? ");
	scanf(RSF RSF RSF, &a1, &b1, &c1);
	printf("a2, b2, c2 = ? ");
	scanf(RSF RSF RSF, &a2, &b2, &c2);

	r = EquationGroup(&x, &y, a1, b1, c1, a2, b2, c2);

	if (0 == r)
	{
		puts("�޽�");
	}
	else if (1 == r)
	{
		printf("Ψһ��: x = " RPF ", y = " RPF "\n", x, y);
	}
	else if (2 == r)
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

// ��Ԫһ�η�����
// a1x + b1y = c1
// a2x + b2y = c2
//  0 �޽�
//  1 Ψһ��
//  2 ������
INTEGER EquationGroup(REAL *x, REAL *y, REAL a1, REAL b1, REAL c1, REAL a2, REAL b2, REAL c2)
{
	INTEGER r;
	REAL d = a1 * b2 - a2 * b1, dx = c1 * b2 - c2 * b1, dy = a1 * c2 - a2 * c1;
	if (EQ(a1, 0.0) && EQ(a2, 0.0) && EQ(b1, 0.0) && EQ(b2, 0.0)) // a1, a2, b1, b2ȫΪ0
	{
		if (EQ(c1, 0.0) && EQ(c2, 0.0))
		{
			r = 2; // ������
		}
		else
		{
			r = 0; // �޽�
		}
	}
	else // a1, a2, b1, b2��ȫΪ0
	{
		if (NE(d, 0.0)) // d != 0
		{
			r = 1; // Ψһ��
			*x = dx / d;
			*y = dy / d;
		}
		else // d == 0
		{
			if (EQ(dx, 0.0) && EQ(dy, 0.0)) // dx == dy == 0
			{
				r = 2; // ������
			}
			else // dx != 0 �� dy != 0
			{
				r = 0; // �޽�
			}
		}
	}
	return r;
}

