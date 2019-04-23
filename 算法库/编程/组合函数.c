#include <stdio.h>
#include "MyMath.h"
#include <stdlib.h> 
REAL Cmb(INTEGER m,INTEGER n);
REAL Arg(INTEGER m,INTEGER n);
REAL Fac(INTEGER n);
int main()
{
	INTEGER m,n;
	REAL c;
	printf("m = ?");
	scanf(ISF,&m);
	printf("n = ?");
	scanf(ISF,&n);
	c = Cmb(m,n);
    printf("c = "RPF"\n",c);
	return 0; 
}
REAL Cmb(INTEGER m,INTEGER n)
{
	 return Arg(m,n) / Fac(n);
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
