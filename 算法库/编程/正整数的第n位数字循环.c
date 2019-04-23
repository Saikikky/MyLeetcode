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
/*INTEGER Digit(INTEGER x,INTEGER n)
{
	int k,y = x,p;
	for(k = 0;k <= n;k++)
	{
		p = y % 10;
		y /= 10;
	}
	return p;
} */
INTEGER Digit(INTEGER x,INTEGER n)
{
	while(n > 0)
	{
		x /= 10;
		n--;
	}
	return x % 10;
}
