#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d,e;
	printf("����=");
	scanf("%lg",&a);
	b=a*180/3.141592653589793238;
	c=floor(b);
	d=floor((b-c)*60);
	e=(b-c-d)*3600;
	printf("����=%g\n����=%g\n����=%g\n",c,d,e);
	return 0;
	
 
}

