#include <stdio.h>
#include "MyMath.h"
REAL Power(REAL x,INTEGER n);
int main()
{
	REAL x,y;
	INTEGER n;
	printf("������");
	scanf(RSF,&x);
	printf("ָ����");
	scanf(ISF,&n);
	y = Power(x,n);
	printf("�����"RPF"\n",y);
	return 0;
}
REAL Power(REAL x,INTEGER n)
{
	REAL f;
	if(0 == n)
	{
		f = 1;
	}
	else 
	{
		f = x*Power(x,n-1);
	}
	return f;
}
