#include <stdio.h>
#include <math.h>
int main()

{
	int a,b;
	printf("����="); 
	scanf("%d",&a);
	b=floor(log10(a))+1;
	printf("λ��=%d",b); 
	return 0;
}
