#include <stdio.h>
#include <math.h> 
int main ()

{
	double r,theta,a,b;
	printf("ģ��=");
	scanf("%lg",&r);
	printf("����=");
	scanf("%lg",&theta);
	a=r*cos(theta);
	b=r*sin(theta);
	printf("a=%.15g\nb=%.15g",a,b); 
	return 0;
}
