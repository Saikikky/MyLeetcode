#include <stdio.h>
#include <math.h>
#include "MyMath.h"

// 判断大于
BOOL GT(REAL x, REAL y);
// 判断大于等于
BOOL GE(REAL x, REAL y);
// 判断小于
BOOL LT(REAL x, REAL y);
// 判断小于等于
BOOL LE(REAL x, REAL y);
// 判断等于
BOOL EQ(REAL x, REAL y);
// 判断不等于
BOOL NE(REAL x, REAL y);

// 一元一次方程
//  0 无解
// -1 唯一解
// -2 无穷多解
INTEGER LinearEquation(REAL *x, REAL a, REAL b);
// 一元二次方程
//  0 无解
// -1 唯一解
// -2 无穷多解
//  1 两个相等的实根
//  2 两个不等的实根
//  3 两个共轭的虚根
INTEGER QuadraticEquation(REAL *x1, REAL *x2, REAL a, REAL b, REAL c);

int main()
{
	INTEGER r;
	REAL a, b, c, x1, x2;
	puts("一元二次方程 ax2 + bx + c = 0");
	printf("a, b, c = ? ");
	scanf(RSF RSF RSF, &a, &b, &c);

	r = QuadraticEquation(&x1, &x2, a, b, c);

	if (0 == r)
	{
		puts("无解");
	}
	else if (-1 == r)
	{
		printf("唯一解: x = " RPF "\n", x1);
	}
	else if (-2 == r)
	{
		puts("无穷多解");
	}
	else if (1 == r)
	{
		printf("两个相等的实根: x1 = x2 = " RPF "\n", x1);
	}
	else if (2 == r)
	{
		printf("两个不等的实根: x1 = " RPF ", x2 = " RPF "\n", x1, x2);
	}
	else if (3 == r)
	{
		printf("两个共轭的虚根: x1 = " RPF " + " RPF "i, x2 = " RPF " - " RPF "i\n", x1, x2, x1, x2);
	}
	else
	{
		puts("异常");
	}
	return 0;
}

// 最大值
REAL FMax(REAL x, REAL y)
{
	return x >= y ? x : y;
}

// 最小值
REAL FMin(REAL x, REAL y)
{
	return x <= y ? x : y;
}

// 判断大于
BOOL GT(REAL x, REAL y)
{
	return x > y + epsilon;
}

// 判断大于等于
BOOL GE(REAL x, REAL y)
{
	return x >= y - epsilon;
}

// 判断小于
BOOL LT(REAL x, REAL y)
{
	return x < y - epsilon;
}

// 判断小于等于
BOOL LE(REAL x, REAL y)
{
	return x <= y + epsilon;
}

// 判断等于
BOOL EQ(REAL x, REAL y)
{
	return x >= y - epsilon && x <= y + epsilon;
}

// 判断不等于
BOOL NE(REAL x, REAL y)
{
	return x < y - epsilon || x > y + epsilon;
}

// 一元一次方程
//  0 无解
// -1 唯一解
// -2 无穷多解
INTEGER LinearEquation(REAL *x, REAL a, REAL b)
{
	INTEGER r;
	if (NE(a, 0)) // a != 0
	{
		r = -1; // 唯一解
		*x = -b / a;
	}
	else // a == 0
	{
		if (NE(b, 0)) // b != 0
		{
			r = 0; // 无解
		}
		else // b == 0
		{
			r = -2; // 无穷多解
		}
	}
	return r;
}

// 一元二次方程
//  0 无解
// -1 唯一解
// -2 无穷多解
//  1 两个相等的实根
//  2 两个不等的实根
//  3 两个共轭的虚根
INTEGER QuadraticEquation(REAL *x1, REAL *x2, REAL a, REAL b, REAL c)
{
	INTEGER r;
	REAL delta, den, p, q;
	if (EQ(a, 0)) // a == 0
	{
		r = LinearEquation(x1, b, c); // 调用一元一次方程
	}
	else // a != 0
	{
		delta = b * b - 4.0 * a * c; // 判别式
		den = 2.0 * a; // 分母
		p = -b / den;
		if (GT(delta, 0)) // delta > 0
		{
			r = 2; // 两个不等的实根
			q = sqrt(delta) / den;
			*x1 = p + q;
			*x2 = p - q;
		}
		else if (EQ(delta, 0)) // delta == 0
		{
			r = 1; // 两个相等的实根
			*x1 = p;
			*x2 = p;
		}
		else // delta < 0
		{
			r = 3; // 两个共轭的虚根
			q = sqrt(-delta) / fabs(den);
			*x1 = p;
			*x2 = q;
		}
	}
	return r;
}

