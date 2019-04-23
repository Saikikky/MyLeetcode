#include <stdio.h>
#include <math.h> 
double Loga(double a,double n);
int main ()

{
	double a,n,b;
	scanf("%lg",&a);
	scanf("%lg",&n);
	b=Loga(a,n);
	printf("¶ÔÊý=%g",b);
	return 0;
}
double Loga(double a,double n)
{
	double s;
	s=log(n)/log(a);
	return s;
}
