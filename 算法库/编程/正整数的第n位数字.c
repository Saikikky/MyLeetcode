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
INTEGER Digit(INTEGER x,INTEGER n)
{
	INTEGER y;
	if(0 == n)
	{
		y = x % 10;
	}
	else
	{
		y = Digit(x/10,n - 1);
	}
	return y;
}
