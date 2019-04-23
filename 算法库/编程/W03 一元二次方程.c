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
// һԪ���η���
//  0 �޽�
// -1 Ψһ��
// -2 ������
//  1 ������ȵ�ʵ��
//  2 �������ȵ�ʵ��
//  3 ������������
INTEGER QuadraticEquation(REAL *x1, REAL *x2, REAL a, REAL b, REAL c);

int main()
{
	INTEGER r;
	REAL a, b, c, x1, x2;
	puts("һԪ���η��� ax2 + bx + c = 0");
	printf("a, b, c = ? ");
	scanf(RSF RSF RSF, &a, &b, &c);

	r = QuadraticEquation(&x1, &x2, a, b, c);

	if (0 == r)
	{
		puts("�޽�");
	}
	else if (-1 == r)
	{
		printf("Ψһ��: x = " RPF "\n", x1);
	}
	else if (-2 == r)
	{
		puts("������");
	}
	else if (1 == r)
	{
		printf("������ȵ�ʵ��: x1 = x2 = " RPF "\n", x1);
	}
	else if (2 == r)
	{
		printf("�������ȵ�ʵ��: x1 = " RPF ", x2 = " RPF "\n", x1, x2);
	}
	else if (3 == r)
	{
		printf("������������: x1 = " RPF " + " RPF "i, x2 = " RPF " - " RPF "i\n", x1, x2, x1, x2);
	}
	else
	{
		puts("�쳣");
	}
	return 0;
}

// ���ֵ
REAL FMax(REAL x, REAL y)
{
	return x >= y ? x : y;
}

// ��Сֵ
REAL FMin(REAL x, REAL y)
{
	return x <= y ? x : y;
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

// һԪ���η���
//  0 �޽�
// -1 Ψһ��
// -2 ������
//  1 ������ȵ�ʵ��
//  2 �������ȵ�ʵ��
//  3 ������������
INTEGER QuadraticEquation(REAL *x1, REAL *x2, REAL a, REAL b, REAL c)
{
	INTEGER r;
	REAL delta, den, p, q;
	if (EQ(a, 0)) // a == 0
	{
		r = LinearEquation(x1, b, c); // ����һԪһ�η���
	}
	else // a != 0
	{
		delta = b * b - 4.0 * a * c; // �б�ʽ
		den = 2.0 * a; // ��ĸ
		p = -b / den;
		if (GT(delta, 0)) // delta > 0
		{
			r = 2; // �������ȵ�ʵ��
			q = sqrt(delta) / den;
			*x1 = p + q;
			*x2 = p - q;
		}
		else if (EQ(delta, 0)) // delta == 0
		{
			r = 1; // ������ȵ�ʵ��
			*x1 = p;
			*x2 = p;
		}
		else // delta < 0
		{
			r = 3; // ������������
			q = sqrt(-delta) / fabs(den);
			*x1 = p;
			*x2 = q;
		}
	}
	return r;
}

