#include <stdio.h>
#include "MyMath.h"
REAL Power(REAL x,INTEGER n);
int EQ(REAL x, REAL y);
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
	INTEGER k = 1;
	REAL ok,y = 1.0;
	if(EQ(x,0))
	{
		if(n > 0)
		{
			ok = 0;
		}
		else
		{
			puts("����ȷ�Ĳ�����");
		}
	}
	else
	{
		if(0 == n)
		{
			ok = 1;
		}
		else if(n > 0)
		{
			while(k <= n)
			{
				y *= x;
				ok = y;
				k++;
			}
       	}
		else
		{
			n = -n;
			while(k <= n)
			{
				y /= x;
				ok = y;
				k++;
			}
		}
	}
	return ok;
}

int EQ(REAL x,REAL y)
{
	return fabs(x-y)<=epsilon;
}


