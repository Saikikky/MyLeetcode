#include <stdio.h>
#include <math.h>
#include "MyMath.h"
int GT(REAL x,REAL y);
int GE(REAL x,REAL y);
int LT(REAL x,REAL y);
int LE(REAL x,REAL y);
int EQ(REAL x,REAL y);
int NE(REAL x,REAL y);
int main()
{
	REAL a,b;
	printf("a=?");
	scanf(RSF,&a);
	printf("b=?");
	scanf(RSF,&b);
	if(GT(a,b))
	{
		puts("a>b");
	}
	if(GE(a,b))
	{
		puts("a>=b");
	}
	if(LT(a,b))
	{
		puts("a<b");
	}
	if(LE(a,b))
	{
		puts("a<=b");
	}
	if(EQ(a,b))
	{
		puts("a==b");
	}
	if(NE(a,b))
	{
		puts("a!=b");
	}
	return 0;
}
int GT(REAL x,REAL y)
{
	return x>y+epsilon?1:0;
}
int GE(REAL x,REAL y)               
{
	return x>=y-epsilon?1:0;
}
int LT(REAL x,REAL y)
{
	return x<y-epsilon?1:0;
}
int LE(REAL x,REAL y)
{
	return x<=y+epsilon?1:0;
}
int EQ(REAL x,REAL y)
{
	return fabs(x-y)<=epsilon?1:0;
}
int NE(REAL x,REAL y)
{
	return fabs(x-y)>epsilon?1:0;
}
