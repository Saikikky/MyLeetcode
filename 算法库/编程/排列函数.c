#include <stdio.h>
#include "MyMath.h"
#include <stdlib.h> 
REAL Arg(INTEGER m,INTEGER n);
REAL Fac(INTEGER n);
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
	REAL s;
	if(m<n||m<0||n<0)
	{
		puts("不正确的参数！"); 
		exit(1);
	}
	s = Fac(m) / Fac(m - n); 
    return s;
}
REAL Fac(INTEGER n)
{
	REAL m = 1;
	if(n < 0)
	{
		puts("不正确的参数！");
		exit(1);
	}
	while(n > 0)
	{
		m *=n;
		n--;
	}
	return m;
}
