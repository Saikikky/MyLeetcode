#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

int main()
{
	REAL a, b;
	printf("a, b = ? ");
	scanf(RSF RSF, &a, &b);
	printf("����ǰ: " RPF " " RPF "\n", a, b);
	SwapReal(&a, &b);
	printf("������: " RPF " " RPF "\n", a, b);
	return 0;
}
