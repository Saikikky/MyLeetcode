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

