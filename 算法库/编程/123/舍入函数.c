#include <stdio.h>
#include <math.h>
#include "MyMath.h"
INTEGER ToInteger(REAL x);
REAL Round(REAL x,INTEGER n);
int main()
{
	REAL a,c;
	INTEGER b;
	printf("ʵ����");
	scanf(RSF,&a);
	printf("С����");
	scanf(ISF,&b);
	c = Round(a,b);
	printf("�����"RPF"\n",c);
	return 0;
}
REAL Round(REAL x,INTEGER n)
{
	REAL m,r,q,p,a;
	m = floor(x);
	q = x - (REAL)m;
	if(0 == n)
	{
		if(GE(q + epsilon,0.5))
		{
			if(x>0)
			{
				r = ceil(x);
			}
			else
			{
				r = floor(x);
			}
		}
		else
		{
			r = m;
		}
	}
	else
	{
		p = q * Power(10,n);
		a = ToInteger(q * Power(10,n));
		r = (REAL)m + p/Power(10,n);
	}
	return r;
}
INTEGER ToInteger(REAL x)

{

     INTEGER y; 

     if(x>0)

     {

          y = floor(x + epsilon);

     }

     else

     {

          y = floor(x - epsilon);

     }

     return y;

}


