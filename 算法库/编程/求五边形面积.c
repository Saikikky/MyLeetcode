#include <stdio.h>
#include <math.h>
double TriangleArea(double side1,double side2,double side3);
int main()
{
	printf("五边形面积=%g\n",TriangleArea(3.18,4.02,5.86)+TriangleArea(5.86,4.11,5.76)+TriangleArea(5.76,2.75,3.89));
	return 0;
}
double TriangleArea(double side1,double side2,double side3)
{
	double s,A;
	s=(side1+side2+side3)/2;
	A=sqrt(s*(s-side1)*(s-side2)*(s-side3));
	return A; 
}
