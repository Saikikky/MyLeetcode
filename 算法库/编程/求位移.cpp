#include <stdio.h>

int main()

{
	double s,a,t,v;
	printf("初速度=");
	scanf("%lg",&v);
	printf("加速度=");
	scanf("%lg",&a);
	printf("时间=");
	scanf("%lg",&t);
	s=0.5*a*t*t+v*t;
	printf("位移=%g",s);
	return 0;
} 

