#include <stdio.h>
int NumleapYear(int year);
int main ()
{
	int y,s;
	printf("�������=");
	scanf("%d",&y);
	s= NumleapYear(y)-NumleapYear(1896);
	printf("���մ���=%d",s);
	return 0;
}
int NumleapYear(int year)
{
	return year/4-year/100+year/400;
}
