#include <stdio.h>
#include <math.h>
#include "MyMath.h"
REAL F(REAL x,INTEGER n);
REAL Power(REAL x,INTEGER n);
int main()
{
	REAL x,y;
	INTEGER n;
	printf("x = ?");
	scanf(RSF,&x);
	printf("n = ?");
	scanf(ISF,&n);
	y = F(x,n);
	printf("½á¹û£º"RPF"\n",y);
	return 0;
} 
REAL F(REAL x,INTEGER n)
{
	REAL m;
	if(0 == n)
	{
		m = 1;
	}
	else
	{
		m = F(x,n - 1) + pow(-1,n)*Power(x,n); 
	}
	return m;
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
