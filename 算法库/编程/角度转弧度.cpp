#include <stdio.h>

int main()

{
	double a,b,c,d;
	printf("�Ƕ�="); 
	scanf("%lg",&a);
	printf("�ֶ�=");
	scanf("%lg",&b);
	printf("���=");
	scanf("%lg",&c);
	a=a+b/60.0+c/3600.0;
	d=a*3.141592653589793238/180.0;
	printf("����=%.15g",d);
	return 0;
	 
} 
