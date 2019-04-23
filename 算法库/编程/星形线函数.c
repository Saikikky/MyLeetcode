#include <stdio.h>
#include <math.h>
void Star(double*x,double*y,double t);
int main()
{
	double t,x,y;
	printf("t=");
	scanf("%lg",&t);
	Star(&x,&y,t);
	printf("x=%f\n",x);
	printf("y=%f\n",y);
	return 0;
}
void Star(double*x,double*y,double t)
{
    *x=cos(t)*cos(t)*cos(t);
    *y=sin(t)*sin(t)*sin(t);
}
