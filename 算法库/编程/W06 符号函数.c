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

// 符号函数
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

// 符号函数
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

