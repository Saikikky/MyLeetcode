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

// 二元一次方程组
// a1x + b1y = c1
// a2x + b2y = c2
//  0 无解
//  1 唯一解
//  2 无穷多解
INTEGER EquationGroup(REAL *x, REAL *y, REAL a1, REAL b1, REAL c1, REAL a2, REAL b2, REAL c2);

int main()
{
	INTEGER r;
	REAL a1, b1, c1, a2, b2, c2, x, y;
	puts("二元一次方程组");
	puts("a1x + b1y = c1");
	puts("a2x + b2y = c2");
	printf("a1, b1, c1 = ? ");
	scanf(RSF RSF RSF, &a1, &b1, &c1);
	printf("a2, b2, c2 = ? ");
	scanf(RSF RSF RSF, &a2, &b2, &c2);

	r = EquationGroup(&x, &y, a1, b1, c1, a2, b2, c2);

	if (0 == r)
	{
		puts("无解");
	}
	else if (1 == r)
	{
		printf("唯一解: x = " RPF ", y = " RPF "\n", x, y);
	}
	else if (2 == r)
	{
		puts("无穷多解");
	}
	else
	{
		puts("异常");
	}
	return 0;
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

// 二元一次方程组
// a1x + b1y = c1
// a2x + b2y = c2
//  0 无解
//  1 唯一解
//  2 无穷多解
INTEGER EquationGroup(REAL *x, REAL *y, REAL a1, REAL b1, REAL c1, REAL a2, REAL b2, REAL c2)
{
	INTEGER r;
	REAL d = a1 * b2 - a2 * b1, dx = c1 * b2 - c2 * b1, dy = a1 * c2 - a2 * c1;
	if (EQ(a1, 0.0) && EQ(a2, 0.0) && EQ(b1, 0.0) && EQ(b2, 0.0)) // a1, a2, b1, b2全为0
	{
		if (EQ(c1, 0.0) && EQ(c2, 0.0))
		{
			r = 2; // 无穷多解
		}
		else
		{
			r = 0; // 无解
		}
	}
	else // a1, a2, b1, b2不全为0
	{
		if (NE(d, 0.0)) // d != 0
		{
			r = 1; // 唯一解
			*x = dx / d;
			*y = dy / d;
		}
		else // d == 0
		{
			if (EQ(dx, 0.0) && EQ(dy, 0.0)) // dx == dy == 0
			{
				r = 2; // 无穷多解
			}
			else // dx != 0 或 dy != 0
			{
				r = 0; // 无解
			}
		}
	}
	return r;
}

