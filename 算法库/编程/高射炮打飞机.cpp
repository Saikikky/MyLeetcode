#include <stdio.h>
#include <math.h>
int main ()

{
	int n;
	double b;
	printf("正整数=");
	scanf ("%d",&n);
	b=(1-pow((1-1.0/n),n))*100;  
	printf("命中率=%.2f%%",b);
	return 0;
}
