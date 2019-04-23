#include <stdio.h>
#include "MyMath.h"
int IsLeapYear(int year);
int main()
{
	int y;
	printf("年份：");
	scanf("%d",&y);
	if(IsLeapYear(y))
	{
		puts("闰年"); 
	} 
	else
	{
		puts("平年");
	}
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

