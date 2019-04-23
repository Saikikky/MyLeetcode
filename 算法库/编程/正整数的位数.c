#include <stdio.h>
#include "MyMath.h"
INTEGER NumDigit(INTEGER x);
int main()
{
	INTEGER x,n;
	printf("正整数：");
	scanf(ISF,&x);
	n = NumDigit(x);
	printf("位数："IPF"\n",n);
	return 0;
}
INTEGER NumDigit(INTEGER x)
{
	INTEGER y;
	if(x<10)
	{
		y = 1;
	}
	else
	{
		y = NumDigit(x/10)+1;
	}
	return y;
}
