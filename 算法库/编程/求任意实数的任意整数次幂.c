#include <stdio.h>
#include "MyMath.h"
REAL Power(REAL x,INTEGER n);
int GT(REAL x,REAL y);
int GE(REAL x,REAL y);
int LT(REAL x,REAL y);
int LE(REAL x,REAL y);
int EQ(REAL x,REAL y);
int NE(REAL x,REAL y);
int main()
{
	REAL x,f;
	INTEGER n;
	printf("底数：");
	scanf(RSF,&x);
	printf("指数：");
	scanf(ISF,&n);
	f = Power(x,n);
	if(0 == f)
	{
		puts("不正确的参数!"); 
	}
	else
	{
		printf("结果："RPF"\n",f);
	}
	return 0;
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

