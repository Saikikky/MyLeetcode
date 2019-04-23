#include <stdio.h>
#include <math.h>
#include "MyMath.h"
REAL F(REAL x,INTEGER n);
REAL Power(REAL x,INTEGER n);
int GT(REAL x,REAL y);
int GE(REAL x,REAL y);
int LT(REAL x,REAL y);
int LE(REAL x,REAL y);
int EQ(REAL x,REAL y);
int NE(REAL x,REAL y);
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
	REAL y = 1.0,k = 1,p;
	if(0 == n)
	{
		
	}
	else
	{
		while(k <= n)
		{
			p = Power(-1,k)*Power(x,k);
			y += p;
			k++;
		}
	}
	return y;
}
REAL Power(REAL x,INTEGER n)
{
	REAL p,f;
	if(EQ(x,0))
	{
		if(GT(n,0))
		{
			f = 0;
		}
	}
	else
	{
		if(EQ(n,0))
		{
			f = 1;
		}
		else if(GE(n,0))
		{
			p = Power(x,n / 2);
		    f = n % 2!= 0?p*p*x:p*p;
		}
		else
		{
			n = -n;
			f = 1.0/Power(x,n);
		}
	}
	return f;
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

