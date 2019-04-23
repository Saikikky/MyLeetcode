#include <stdio.h>

int main()

{
	int a,b,c;
	printf("a=?\n");
	scanf("%d",&a);
	printf("b=?\n");
	scanf("%d",&b);
	c=(a+a+b-1)*b/2;
	printf("n=%d",c);
	return 0; 
}
