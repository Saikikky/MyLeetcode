#include <stdio.h>
#include "MyMath.h"
INTEGER Digit(INTEGER x,INTEGER n);
int main()
{
	INTEGER x,n,y;
	printf("正整数：");
	scanf(ISF,&x);
	printf("位号；");
	scanf(ISF,&n);
	y = Digit(x,n);
	printf("数字："IPF"\n",y);
	return 0;
}
INTEGER Digit(INTEGER x,INTEGER n)
{
	INTEGER y;
	if(0 == n)
	{
		y = x % 10;
	}
	else
	{
		y = Digit(x/10,n - 1);
	}
	return y;
}
