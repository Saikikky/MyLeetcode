#include <stdio.h>
void Shipping(double *v1,double *v2,double s,double t1,double t2);
int main()
{
	double v1,v2,s,t1,t2;
	printf("���о���=");
	scanf("%lg",&s);
	printf("˳��ʱ��=");
	scanf("%lg",&t1);
	printf("����ʱ��=");
	scanf("%lg",&t2);
	Shipping(&v1,&v2,s,t1,t2);
	printf("��ֻ�ٶ�=%.2f\n",v1);
	printf("ˮ���ٶ�=%.2f\n",v2);
	return 0;
}
void Shipping(double *v1,double *v2,double s,double t1,double t2)
{
	*v1=(s/t1+s/t2)/2;
	*v2=(s/t1-s/t2)/2;
}
