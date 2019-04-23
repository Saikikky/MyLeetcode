#include<stdio.h>
#include<math.h>
double Power(double x,long long int n);
int EQ(double x,double y);
int main()
{
	double x;
	long long int n;
	printf("����:");
	scanf("%lg",&x);
	printf("ָ��:");
	scanf("%i64d",&n);
	if(EQ(x,0))
	{
		puts("����ȷ�Ĳ���!"); 
	}
	else
	{
		printf("���:%.15g",Power(x,n));
	}
	return 0;
}

double Power(double x,long long int n)
{
	double m,p,q;
	if(n==0)
	{
     	m=1;
	}
	else if(n>0) 
	{
		p=Power(x,n/2);
		m = n%2!=0 ? p*p*x : p*p ;
	}
	else
	{
		n=-n;
		m = 1.0/Power(x,n);    
	}
	return m;
}
 

int EQ(double x,double y)
{
	 return fabs(x-y)<=1e-8;
}

