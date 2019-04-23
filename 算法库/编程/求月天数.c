#include <stdio.h>
#include "MyMath.h"
int IsLeapYear(int year);
INTEGER MonthDay(INTEGER year,INTEGER month);
int main()
{
	INTEGER y,m,n;
	printf("年份：");
	scanf(ISF,&y);
	printf("月份：");
	scanf(ISF,&m);
	n = MonthDay(y,m);
	printf("天数："IPF"\n",n);
	return 0;
} 
int IsLeapYear(int year)
{
    int n;
    if(0 == year % 100)
    {
         if(0 == year % 400)
         {
         	n = 1;
         }
         else
		 {
		 	n = 0;
         }
    }
    else
    {
         if(0 == year % 4)
         {
         	n = 1;
         }
         else 
         {
         	n = 0;
         }
    }
    return n;
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

