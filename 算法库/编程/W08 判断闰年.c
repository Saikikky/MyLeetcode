#include <stdio.h>
#include <math.h>
#include "MyMath.h"

// 判断闰年
BOOL IsLeapYear(INTEGER year);

int main()
{
	INTEGER y;
	printf("年份: ");
	scanf(ISF, &y);
	if (IsLeapYear(y))
	{
		puts("闰年");
	}
	else
	{
		puts("平年");
	}
	return 0;
}

// 判断闰年
BOOL IsLeapYear(INTEGER year)
{
	BOOL ok;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		ok = 1;
	}
	else
	{
		ok = 0;
	}
	return ok;
}

