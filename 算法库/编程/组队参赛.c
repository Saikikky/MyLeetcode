#include <stdio.h>
#include "MyMath.h"
#include <stdlib.h> 
REAL Cmb(INTEGER m,INTEGER n);
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
REAL Fac(INTEGER n)
{
     REAL y;
     if(n<=1.0)
    {
         y=1.0;
    } 
    else
    {
         y=n*Fac(n-1);
    }
    return y;
}
REAL Cmb(INTEGER m, INTEGER n)
{
     if(m<n||m<0||n<0)
     {
          puts("不正确的参数！");
          exit(1); 
     }
     return Fac(m)/Fac(m-n)/Fac(n);
}

