#include "MyMath.h"

int GT(REAL x,REAL y)
{
	return x>y+epsilon;
}
int GE(REAL x,REAL y)               
{
	return x>=y-epsilon;
}
int LT(REAL x,REAL y)
{
	return x<y-epsilon;
}
int LE(REAL x,REAL y)
{
	return x<=y+epsilon;
}
int EQ(REAL x,REAL y)
{
	return fabs(x-y)<=epsilon;
}
int NE(REAL x,REAL y)
{
	return fabs(x-y)>epsilon;
}


REAL Power(REAL x,INTEGER n) 
{
	REAL r;
	if (n < 1)
	{
		r = 1;
	}
	else 
	{
		r = x * Power(x,n - 1);
    }
    return r;
}


INTEGER IsLeapYear(INTEGER year) 
{
 	INTEGER r; 
	if(year%4==0 && year%100!=0)
	{
		r = 1; 
	}
	else if(year%400==0) 
	{
		r = 1;
	}
    else 
    {
     	r = 0;
    }
    return r;
}


REAL Fac(INTEGER n) 
{
	return n > 0? n*Fac(n - 1):1;  
}

