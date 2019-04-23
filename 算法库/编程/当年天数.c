#include <stdio.h>
#include "MyMath.h"
#include "MyDate.h"
 
INTEGER DayInYear(INTEGER year,INTEGER month,INTEGER day);
int main()
{
	INTEGER y, m, d, n, t;
	REAL p;
	printf("���������: ");
	ScanDate(&y, &m, &d);
	n = DayInYear(y, m, d);
	t = IsLeapYear(y) ? 366 : 365;
	p = Round(100.0 * n / t, 2);
	printf("����ĵ�" IPF "��, �����ѹ�ȥ" RPF "%%\n", n, p);
	return 0;
}
INTEGER DayInYear(INTEGER year,INTEGER month,INTEGER day)
{
	int n,p = 0;
	for(n = 1;n <= month;n++)
	{
		p += Monthday(year,n);
	}
	return p + day;
}
INTEGER IsLeapYear(INTEGER year)
{
	return year % 4 == 0 && year % 100 != 0 ||year % 400 == 0;
} 

