#include <stdio.h>
#include <math.h>
#include "MyMath.h"
int GT(REAL x,REAL y);
int EQ(REAL x,REAL y);
REAL Sign(REAL x);
int main()
{
	REAL a,b;
	printf("a = ?");
	scanf(RSF,&a);
	b = Sign(a);
	printf("b = "RPF"\n",b);
	return 0;
}
REAL Sign(REAL x)
{
	double y;
	if(EQ(x,0))
	{
		y = 0;
	}
	else if(GT(x,0))
	{
		y = 1;
	}
	else
	{
		y = -1;
	}
	return y;
}
int EQ(REAL x,REAL y)
{
	return fabs(x-y)<=epsilon;
}
int GT(REAL x,REAL y)
{
	return x>y+epsilon;
}
