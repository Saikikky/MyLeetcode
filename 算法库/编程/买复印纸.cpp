#include <stdio.h>
#include <math.h>
int main()

{
	double a,b,c,d,e;
	printf("Ԥ��="); 
	scanf("%lg",&a);
	printf("����=");
	scanf("%lg",&b);
	c=floor(a/b);
	d=c*b;
	e=a-d;
	printf("����%.2f",c);
	printf("���%.2f",d);
	printf("���%.2f",e); 
	return 0;
}
