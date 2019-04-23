#include <stdio.h>
#include <math.h>
#include "MyMath.h"

// �ж�����
BOOL IsLeapYear(INTEGER year);

int main()
{
	INTEGER y;
	printf("���: ");
	scanf(ISF, &y);
	if (IsLeapYear(y))
	{
		puts("����");
	}
	else
	{
		puts("ƽ��");
	}
	return 0;
}

// �ж�����
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

