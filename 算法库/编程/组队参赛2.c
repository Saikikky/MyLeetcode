#include <stdio.h>
#include "MyMath.h"
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
REAL Cmb(INTEGER m,INTEGER n)
{
		INTEGER y;
     if(m<n||m<0||n<0)
     {
          puts("不正确的参数！");
          exit(1); 
     }
     else
     {
     	if(0==n)
     	{
     		y = 1;
     	}
     	else
     	{
     		y = Cmb(m,n-1)*(m-n+1)/n;
     	}
     	return y;
     }
}
