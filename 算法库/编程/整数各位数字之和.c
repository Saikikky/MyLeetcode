#include <stdio.h>
#include "MyMath.h"
INTEGER SumDigit(INTEGER x);
int main()
{
	INTEGER x,y;
	printf("正整数：");
	scanf(ISF,&x);
	y = SumDigit(x);
	printf("各位数字之和："IPF"\n",y);
	return 0; 
}
INTEGER SumDigit(INTEGER x)
{
	INTEGER y;
	if(x<10)
	{
		y = x;
	}
	else
	{
		y = SumDigit(x/10)+x%10; 
	}
	return y;
}
