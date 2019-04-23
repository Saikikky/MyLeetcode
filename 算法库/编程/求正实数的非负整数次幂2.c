#include <stdio.h>
#include "MyMath.h"
REAL Power(REAL x,INTEGER n);
int main()
{
	REAL x,y;
	INTEGER n;
	printf("底数：");
	scanf(RSF,&x);
	printf("指数：");
	scanf(ISF,&n);
	y = Power(x,n);
	printf("结果："RPF"\n",y);
	return 0;
}
REAL Power(REAL x,INTEGER n)
{
	REAL f,p;
	if(0 == n)
	{
		f = 1;
	}
	else 
	{
		p = Power(x,n / 2);
		f = n % 2!= 0?p*p*x:p*p;
	}
	return f;
}

