#include <stdio.h>
void Shipping(double *v1,double *v2,double s,double t1,double t2);
int main()
{
	double v1,v2,s,t1,t2;
	printf("航行距离=");
	scanf("%lg",&s);
	printf("顺行时间=");
	scanf("%lg",&t1);
	printf("逆行时间=");
	scanf("%lg",&t2);
	Shipping(&v1,&v2,s,t1,t2);
	printf("船只速度=%.2f\n",v1);
	printf("水流速度=%.2f\n",v2);
	return 0;
}
void Shipping(double *v1,double *v2,double s,double t1,double t2)
{
	*v1=(s/t1+s/t2)/2;
	*v2=(s/t1-s/t2)/2;
}
