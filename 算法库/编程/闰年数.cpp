#include <stdio.h>
int NumleapYear(int year);
int main ()
{
	int y,s;
	printf("今年年份=");
	scanf("%d",&y);
	s= NumleapYear(y)-NumleapYear(1896);
	printf("生日次数=%d",s);
	return 0;
}
int NumleapYear(int year)
{
	return year/4-year/100+year/400;
}
