#include <stdio.h>
#include <math.h> 
int main ()

{
	double a,b,r,theta;
	printf("a=");
	scanf("%lg",&a);
	printf("b=");
	scanf("%lg",&b);
	r=sqrt((pow(a,2)+pow(b,2)));
	theta=atan2(b,a);
	printf("ģ��=%.15g\n",r);
	printf("����=%.15g\n",theta);
	return 0;
}
