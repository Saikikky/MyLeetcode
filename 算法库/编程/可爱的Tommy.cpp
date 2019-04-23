#include <stdio.h>
#include <math.h>
int main()

{
 
	double a,b,c,d,e;
	printf("»¡¶È="); 
	scanf("%lg",&a);
	b=180*a/3.141592653589793238;
	c=floor(b);
	d=floor((b-c)*60);
	e=(b-c-d/60)*3600;
	printf("%g¡ã",c);
	printf("%g¡ä",d);
	printf("%.2f¡å",e);
	return 0;

}
