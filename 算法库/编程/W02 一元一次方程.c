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

int main()
{
	INTEGER r;
	REAL a, b, x;
	puts("一元一次方程 ax + b = 0");
	printf("a, b = ? ");
	scanf(RSF RSF, &a, &b);

	r = LinearEquation(&x, a, b);

	if (0 == r)
	{
		puts("无解");
	}
	else if (-1 == r)
	{
		printf("唯一解: x = " RPF "\n", x);
	}
	else if (-2 == r)
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

