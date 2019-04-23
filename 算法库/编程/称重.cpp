#include <stdio.h>

int main()

{
	int a,b,c,d,e,f,g,h,i,j,k;
	printf("a=?");
	scanf("%d",&a);
	b=a/50;
	printf("50g:%d\n",b);
	c=a%50;
	d=c/20;
	printf("20g:%d\n",d);
	e=c%20;
	f=e/10;
	printf("10g:%d\n",f);
	g=e%10;
	h=g/5;
	printf("5g:%d\n",h);
	i=g%5;
	j=i/2;
	printf("2g:%d\n",j);
	k=i%2;
	printf("1g:%d\n",k);
	return 0;
}
