#include <stdio.h>
#include "MyMath.h"
int IsLeapYear(int year);
int main()
{
	int y;
	printf("��ݣ�");
	scanf("%d",&y);
	if(IsLeapYear(y))
	{
		puts("����"); 
	} 
	else
	{
		puts("ƽ��");
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

