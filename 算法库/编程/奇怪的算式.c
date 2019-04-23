#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c;
	printf("¡î + ¡î = ¡÷\n");
	printf("¡î - ¡î = ¡õ\n");
	printf("¡î ¡Á¡î = ¡ó\n");
	printf("¡î ¡Â¡î = ¡ð\n");
	printf("¡÷ + ¡õ+ ¡ó + ¡ð= ¡ï\n"); 
	printf("¡ï=?");
	scanf("%d",&b);
	c=sqrt(b); 
    if(4*b>=0&&c*c==b)
	{
		a=c - 1;
		printf("¡î = %d",a);
	} 
	else 
	{
		printf("ÎÞ½â");
	}
	return 0;
}
