#include <stdio.h>
#include "MyMath.h"

int main()
{
	int m, n;
	double c;
	printf("m = ? ");
	scanf("%d", &m);
	printf("n = ? ");
	scanf("%d", &n);
	c = Cmb(m, n);
	printf("%g\n", c);
	return 0;
}

