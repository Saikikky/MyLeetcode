#include <stdio.h>
#include <math.h>
int main()

{
	double a,b,c,d,e;
	printf("预算="); 
	scanf("%lg",&a);
	printf("单价=");
	scanf("%lg",&b);
	c=floor(a/b);
	d=c*b;
	e=a-d;
	printf("数量%.2f",c);
	printf("金额%.2f",d);
	printf("余额%.2f",e); 
	return 0;
}
