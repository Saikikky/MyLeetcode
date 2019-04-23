#include <stdio.h>
#include <math.h>
#include "MyMath.h"
int LinearEquation(double *x,double a,double b);
int main()
{
	int r;
	REAL a,b,x;
	puts("一元一次方程 ax + b = 0");
	printf("a,b=?");
	scanf(RSF RSF,&a,&b);
	r=LinearEquation(&x,a,b);
	if(0==r)
	{
		puts("无解"); 
	}
	else if(-1==r)
	{
		printf("唯一解：x="RPF"\n",x);
	}
	else if(-2==r)
	{
		puts("无穷多解"); 
	}
	else
	{
		puts("异常"); 
	}
	return 0;
}
int LinearEquation(double *x,double a,double b)
{   
    int y;
	if(fabs(a)<=epsilon)
	{
       if(fabs(b)>epsilon)	
       {
       	 y=0;
       }
       else
       {
       	 y=-2;
       }
	}
	else 
	{
		y=-1;
		*x=-b/a;
	}
	return y;
}
