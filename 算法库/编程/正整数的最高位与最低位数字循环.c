#include <stdio.h>
#include "MyMath.h"
INTEGER TopDigit(INTEGER x);
INTEGER LowDigit(INTEGER x);
int main()
{
	INTEGER x,a,b;
	printf("��������");
	scanf(ISF,&x);
	a = TopDigit(x);
	b = LowDigit(x);
	printf("���λ��"IPF"\n",a);
	printf("���λ��"IPF"\n",b);
	return 0;
}
INTEGER TopDigit(INTEGER x)
{
	INTEGER k = x;
	while(k >= 10)
	{
		k /= 10;
	}
	return k;
} 
INTEGER LowDigit(INTEGER x)
{
	return x % 10;
}
