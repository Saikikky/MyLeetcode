#include <stdio.h>
#include "MyMath.h"
REAL Arg(INTEGER m,INTEGER n);
int main()
{
	INTEGER m,n;
	REAL a;
	printf("m = ?");
	scanf(ISF,&m);
	printf("n = ?");
	scanf(ISF,&n);
	a = Arg(m,n);
	printf("a = "RPF"\n",a); 
	return 0;
} 
REAL Arg(INTEGER m,INTEGER n)
{
	INTEGER A;
	if(m<n||m<0||n<0)
	{
		puts("不正确的参数！"); 
		exit(1);
	}
	else
	{
		if(n == 1)
		{
			A = m;
		}
		else
		{
		    A = (m-n+1)*Arg(m,n-1);	
		}
	}
	return A;
}
