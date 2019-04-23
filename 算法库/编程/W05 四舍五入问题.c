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

// 四舍五入
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

// 四舍五入
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

