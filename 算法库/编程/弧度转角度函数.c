#include <stdio.h>
#include <math.h>
void ToDegree(int *degree,int *minute,double *second,double radian);
const double pi=3.1415926535897932;
int main()
{
	int degree,minute;
	double second,radian,x;
	printf("����=");
	scanf("%lg",&x);
	radian=asin(x);
	ToDegree(&degree,&minute,&second,radian);
	printf("�Ƕ�=%d��%d��%.2f��\n",degree,minute,second);
	return 0;
}
void ToDegree(int *degree,int *minute,double *second,double radian)
{
	*degree=radian*180/pi;
	*minute=(radian*180/pi-*degree)*60;
	*second=((radian*180/pi-*degree)*60-*minute)*60;
}
