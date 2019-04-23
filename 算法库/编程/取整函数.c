#include <stdio.h>
#include <math.h> 
#include "MyMath.h"
INTEGER ToInteger(REAL x);
int main()
{
	REAL a;
	INTEGER n;
	printf("实数：");
	scanf(RSF,&a);
	n = ToInteger(a);
	printf("结果："IPF"\n",n);
	return 0;
}
INTEGER ToInteger(REAL x)
{
	INTEGER y; 
	if(x>0)
	{
		y = floor(x + epsilon);
	}
	else
	{
		y = ceil(x - epsilon);
	}
	return y;
}
