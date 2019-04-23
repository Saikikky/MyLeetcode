#include <stdio.h>
#include "MyMath.h"
#include "MyDate.h"

BOOL IsValidDate(INTEGER year,INTEGER month,INTEGER day);


int main()
{
	INTEGER y, m, d;
	printf("日期: ");
	while (scanf(DSF, &y, &m, &d) < 3 || !IsValidDate(y, m, d))
	{
		printf("不正确的数据, 请重新输入: ");
		fflush(stdin);
	}
	printf("日期: " DPF "\n", y, m, d);
	return 0;
} 
BOOL IsValidDate(INTEGER year,INTEGER month,INTEGER day)
{
    BOOL ok = 1;
	if(year < 1||month > 12||month < 1)
	{
		ok = 0;
	} 
	else if(day != MonthDay(year,month))
	{
		ok = 0;
	}
	return ok;
}
INTEGER IsLeapYear(INTEGER year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
INTEGER MonthDay(INTEGER year,INTEGER month)
{
	INTEGER d;
	switch(month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	   d = 31;
	   break;
	case 4:
	case 6:
	case 9:
	case 11:
	   d = 30;
	   break;
	case 2:
	   d = IsLeapYear(year)?29:28;
	   break;
	default:
	   d = 0; 
	}
	return d;
}



