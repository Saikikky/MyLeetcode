#include <stdio.h>

int main()

{
	double a,b,c,d;
	printf("角度="); 
	scanf("%lg",&a);
	printf("分度=");
	scanf("%lg",&b);
	printf("秒度=");
	scanf("%lg",&c);
	a=a+b/60.0+c/3600.0;
	d=a*3.141592653589793238/180.0;
	printf("弧度=%.15g",d);
	return 0;
	 
} 
