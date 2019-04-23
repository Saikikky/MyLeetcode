#include <stdio.h>
#include <math.h>
int main()

{
	int a,b;
	printf("整数="); 
	scanf("%d",&a);
	b=floor(log10(a))+1;
	printf("位数=%d",b); 
	return 0;
}
