#include <stdio.h>
#include <math.h>
const double pi=3.14159265358979;
double Toradian(degree,minute,second);
int main()
{
	int degree,minute;
	double second,radian;
	printf("�Ƕ�=?");
	scanf("%d%d%lg",&degree,&minute,&second);
	radian=Toradian(degree,minute,second);
	printf("���ң�%.15g\n",sin(radian));
	printf("���ң�%.15g\n",cos(radian));
	printf("���У�%.15g\n",tan(radian));
    return 0; 
}
double Toradian(degree,minute,second)
{
	double radian;
	radian=pi*(degree+minute/60+second/3600)/180;
	return radian;
}
