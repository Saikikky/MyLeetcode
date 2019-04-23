#include <stdio.h>

void Swap(double *x,double *y);

int main()
{
	double a = 1.0,b = 2.0,t;
	printf("a = %g,b = %g\n",a,b);
	Swap(&a,&b);
	printf("a = %g,b = %g\n",a,b);
	return 0;
}

void Swap(double *x,double *y)
{
	double t;
	t = *x;*x = *y;*y = t;
}
