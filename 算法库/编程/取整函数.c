#include <stdio.h>
#include <math.h> 
#include "MyMath.h"
INTEGER ToInteger(REAL x);
int main()
{
	REAL a;
	INTEGER n;
	printf("ʵ����");
	scanf(RSF,&a);
	n = ToInteger(a);
	printf("�����"IPF"\n",n);
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
