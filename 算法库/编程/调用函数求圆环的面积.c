#include <stdio.h>
const double pi=3.14159265358979;
double CircleArea(double radius);
int main()
{
	double d1,d2,s;
	printf("�ھ�=");
	scanf("%lg",&d1);
	printf("�⾶=");
	scanf("%lg",&d2);
	s= CircleArea(d2/2)- CircleArea(d1/2);
	printf("���=%.15g",s);
	return 0;
}
double CircleArea(double radius)
{
	return pi*radius*radius;
}
