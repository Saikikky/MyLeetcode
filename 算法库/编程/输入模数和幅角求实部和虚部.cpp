#include <stdio.h>
#include <math.h> 
int main ()

{
	double r,theta,a,b;
	printf("Ä£Êý=");
	scanf("%lg",&r);
	printf("·ù½Ç=");
	scanf("%lg",&theta);
	a=r*cos(theta);
	b=r*sin(theta);
	printf("a=%.15g\nb=%.15g",a,b); 
	return 0;
}
