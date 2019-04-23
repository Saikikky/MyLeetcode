#include <stdio.h>
#include <math.h>
#include "MyMath.h"
int GE(REAL x,REAL y);
int LE(REAL x,REAL y);
REAL Round(REAL x);
int main()
{
	REAL x,y;
	printf("x = ?");
	scanf(RSF,&x);
	y = Round(x);
	printf("y = "RPF"\n",y);
	return 0;
}
REAL Round(REAL x)
{
	int m,n,p;
    n = floor(x);
	p = ceil(x);
	if(GE(x,0))
	{
	   m = GE(x + 0.5,p)?p:p-1;	
	}
	else 
	{
		m = LE(x - 0.5,n)?n:n+1;
	}
	return m;
}
int GE(REAL x,REAL y)               
{
	return x>=y-epsilon?1:0;
}
int LE(REAL x,REAL y)
{
	return x<=y+epsilon?1:0;
}
