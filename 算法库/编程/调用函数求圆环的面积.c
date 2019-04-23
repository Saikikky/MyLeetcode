#include <stdio.h>
const double pi=3.14159265358979;
double CircleArea(double radius);
int main()
{
	double d1,d2,s;
	printf("内径=");
	scanf("%lg",&d1);
	printf("外径=");
	scanf("%lg",&d2);
	s= CircleArea(d2/2)- CircleArea(d1/2);
	printf("面积=%.15g",s);
	return 0;
}
double CircleArea(double radius)
{
	return pi*radius*radius;
}
