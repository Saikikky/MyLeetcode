#include <stdio.h>
#include "MyMath.h"
INTEGER SumDigit(INTEGER x);
int main()
{
	INTEGER x,y;
	printf("��������");
	scanf(ISF,&x);
	y = SumDigit(x);
	printf("��λ����֮�ͣ�"IPF"\n",y);
	return 0; 
}
INTEGER SumDigit(INTEGER x)
{
	int p = 0,q;
	INTEGER y = x;
    if(y < 10)
    {
    	p = y;
    }
    else
    {
    	while(y > 0)
    	{
    		q = y % 10;
    		p += q;
    		y = y / 10;
    	}
    }
    return p;
}
