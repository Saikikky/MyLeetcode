#include <stdio.h>
#include "MyMath.h"
REAL Fac(INTEGER n);
int main()
{
	INTEGER n;
	REAL f;
	printf("n = ? ");
	scanf(ISF, &n);
	f = Fac(n);
	printf("f = " RPF "\n", f);
	return 0;
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
