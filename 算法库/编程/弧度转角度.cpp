#include <stdio.h>
#include <math.h>
int main()

{
 
	double a,b,c,d,e;
	printf("����="); 
	scanf("%lg",&a);
	b=180*a/3.141592653589793238;
	c=floor(b);
	d=floor((b-c)*60);
	e=(b-c-d/60)*3600;
	printf("%g��",c);
	printf("%g��",d);
	printf("%.2f��",e);
	return 0;

}
