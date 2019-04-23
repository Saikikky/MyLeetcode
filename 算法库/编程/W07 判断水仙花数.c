#include <stdio.h>
#include <math.h>
#include "MyMath.h"

// 立方“函数”
#define Cube(x) ((x) * (x) * (x))

// 判断水仙花数
BOOL IsNarcissus(INTEGER n);

int main()
{
	INTEGER n;
	printf("整数: ");
	scanf(ISF, &n);
	if (IsNarcissus(n))
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}

// 判断水仙花数
BOOL IsNarcissus(INTEGER n)
{
	BOOL ok;
	INTEGER d0, d1, d2, m;
	d0 = n % 10;
	d1 = n / 10 % 10;
	d2 = n / 100;
	m = Cube(d0) + Cube(d1) + Cube(d2);
	if (m == n)
	{
		ok = 1;
	}
	else
	{
		ok = 0;
	}
	return ok;
}

