#include <stdio.h>
#include "MyMath.h"
INTEGER Digit(INTEGER x,INTEGER n);
int main()
{
	INTEGER x,n,y;
	printf("��������");
	scanf(ISF,&x);
	printf("λ�ţ�");
	scanf(ISF,&n);
	y = Digit(x,n);
	printf("���֣�"IPF"\n",y);
	return 0;
}
/*INTEGER Digit(INTEGER x,INTEGER n)
{
	int k,y = x,p;
	for(k = 0;k <= n;k++)
	{
		p = y % 10;
		y /= 10;
	}
	return p;
} */
INTEGER Digit(INTEGER x,INTEGER n)
{
	while(n > 0)
	{
		x /= 10;
		n--;
	}
	return x % 10;
}
