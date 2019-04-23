#include <stdio.h>
#include "math.h"
double Discount(double cash); 

int main()
{
	double c, d;
	printf("¹ºÎï: ");
	scanf("%lg", &c);
	d = Discount(c);
	printf("ÕÛ¿Û: %.2f%%\n", 100.0 * d);
	return 0;
}

double Discount(double cash)
{
	double p = cash,a = cash,q;
	while(cash >= 100)
	{
		cash = floor(cash / 100)*30;
		p += cash;
	}
    q = a / p;
    return q;
}
