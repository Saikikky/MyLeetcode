#include <stdio.h>
#include "MyMath.h"
#include <stdlib.h> 
REAL Arg(INTEGER m,INTEGER n);
REAL Fac(INTEGER n);
int main()
{
	INTEGER m,n;
	REAL a;
	printf("m = ?");
	scanf(ISF,&m);
	printf("n = ?");
	scanf(ISF,&n);
	a = Arg(m,n);
	printf("a = "RPF"\n",a); 
	return 0;
} 
REAL Arg(INTEGER m,INTEGER n)
{
	INTEGER A;
	if(m<n||m<0||n<0)
	{
		puts("不正确的参数！"); 
		exit(1);
	}
	else
	{
		A = Fac(m)/Fac(m-n);
	}
	return A;
}
REAL Fac(INTEGER n)
{
	INTEGER y;
	if(0 == n)
	{
		y = 1;
	}
	else
	{
	    y = n*Fac(n-1);
	}
	return y;
}
