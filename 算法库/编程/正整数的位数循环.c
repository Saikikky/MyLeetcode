#include <stdio.h>
#include "MyMath.h"
INTEGER NumDigit(INTEGER x);
int main()
{
	INTEGER x,n;
	printf("��������");
	scanf(ISF,&x);
	n = NumDigit(x);
	printf("λ����"IPF"\n",n);
	return 0;
}
INTEGER NumDigit(INTEGER x)
{
	int k = 1;
	INTEGER y = x;
	while(y >= 10)
	{
		y = y / 10;
		k++;
	}
	return k;
} 
