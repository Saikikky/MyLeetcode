#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

int main()
{
	REAL a, b;
	printf("a, b = ? ");
	scanf(RSF RSF, &a, &b);
	printf("交换前: " RPF " " RPF "\n", a, b);
	SwapReal(&a, &b);
	printf("交换后: " RPF " " RPF "\n", a, b);
	return 0;
}
