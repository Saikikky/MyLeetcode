#include <stdio.h>
#include <math.h>
int main ()

{
	int n;
	double b;
	printf("������=");
	scanf ("%d",&n);
	b=(1-pow((1-1.0/n),n))*100;  
	printf("������=%.2f%%",b);
	return 0;
}
