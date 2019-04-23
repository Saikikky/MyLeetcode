#include <stdio.h>
#include "MyMath.h"
INTEGER TopDigit(INTEGER x);
INTEGER LowDigit(INTEGER x);
int main()
{
	INTEGER x,a,b;
	printf("正整数：");
	scanf(ISF,&x);
	a = TopDigit(x);
	b = LowDigit(x);
	printf("最高位："IPF"\n",a);
	printf("最低位："IPF"\n",b);
	return 0;
}
INTEGER TopDigit(INTEGER x)
{
	int y;
	if(x<10)
	{
		y = x;
	}
	else
	{
		y = TopDigit(x / 10); 
	}
	return y;
}
INTEGER LowDigit(INTEGER x)
{
	int y;
	if(x<10)
	{
		y = x;
	}
	else
	{
		y = x % 10;
	}
	return y;
}
