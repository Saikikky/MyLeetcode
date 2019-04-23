#include <stdio.h>
#include <math.h>
#include "MyMath.h"
int EQ(REAL x,REAL y);
int NE(REAL x,REAL y);
int EquationGroup(REAL *x,REAL *y,REAL a1,REAL b1,REAL c1,REAL a2,REAL b2,REAL c2);
int main()
{
	int r;
	REAL a1,b1,c1,a2,b2,c2,x,y;
	puts("二元一次方程组");
	puts("a1x + b1y = c1");
	puts("a2x + b2y = c2");
	printf("a1,b1,c1 = ?");
	scanf(RSF RSF RSF,&a1,&b1,&c1);
	printf("a2,b2,c2 = ?");
	scanf(RSF RSF RSF ,&a2,&b2,&c2); 
	r = EquationGroup(&x,&y,a1,b1,c1,a2,b2,c2);
	if(0==r)
	{
		puts("无解");
	}
	else if(1==r)
	{
		printf("唯一解:x = "RPF",y = "RPF"\n",x,y);
	}
	else if(2==r)
	{
		puts("无穷多解"); 
	}
	else
	{
		puts("异常"); 
	}
	return 0;
}
int EQ(REAL x,REAL y)
{
	return fabs(x-y)<=epsilon?1:0;
}
int NE(REAL x,REAL y)
{
	return fabs(x-y)>epsilon?1:0;
}
int EquationGroup(REAL *x,REAL *y,REAL a1,REAL b1,REAL c1,REAL a2,REAL b2,REAL c2)
{
	int ok;
    if(EQ(a1,0)&&EQ(a2,0)&&EQ(b1,0)&&(b2,0))
    {
    	if(EQ(c1,0)&&EQ(c2,0))
    	{
    		ok = 2;
    	}
    	else 
    	{
    		ok = 0;
    	}
    }
    else if(NE(a1,0)||NE(a2,0)||NE(b1,0)||NE(b2,0))
    {
    	if(NE(a1*b2-a2*b1,0))
    	{
    		ok = 1;
    		*x = (c1*b2 - c2*b1)/(a1*b2-a2*b1);
    		*y = (a1*c2 - a2*c1)/(a1*b2-a2*b1);
    	}
    	else 
		if(EQ(c1*b2 - c2*b1,0)&&EQ(a1*c2 - a2*c1,0))
    	{
    		ok = 2;
    	}
    	else 
    	{
    		ok = 0;
    	}
    }
    else 
    {
    	ok = 1;
    	*x = (c1*b2 - c2*b1)/(a1*b2-a2*b1);
    	*y = (a1*c2 - a2*c1)/(a1*b2-a2*b1);
    }
    return ok;
}
