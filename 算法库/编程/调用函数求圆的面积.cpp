#include <stdio.h>

const double pi=3.14159265358979;
double CircleArea(double radius);
int main()
{
	double r,s;
	printf("°ë¾¶=");
	scanf("%lg",&r);
	s=CircleArea(r);
	printf("Ãæ»ý=%.15g",s);
	return 0;
}
double CircleArea(double radius)
{
	return pi*radius*radius;
} 
