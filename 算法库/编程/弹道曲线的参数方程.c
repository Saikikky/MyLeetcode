#include <stdio.h>
#include <math.h>
void Trajectory(double*x,double*y,double v0,double alpha,double t);
const double g=9.80655;
const double pi=3.1415926535897932;
int main ()
{
	double v0,alpha,t,x,y,c;
	int a,b;
	printf("v0=");
	scanf("%lg",&v0);
    printf("alpha=");
    scanf("%d%d%lg",&a,&b,&c);
    alpha=(a+b/60+c/3600)*pi/180;
    printf("t=");
    scanf("%lg",&t);
	Trajectory(&x,&y,v0,alpha,t);
	printf("x=%.4f\n",x);
	printf("y=%.4f\n",y);
	return 0; 
}
void Trajectory(double*x,double*y,double v0,double alpha,double t)
{
	*x=v0*t*cos(alpha);
	*y=v0*t*sin(alpha)-0.5*g*t*t;
}
