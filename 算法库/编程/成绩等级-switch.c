#include <stdio.h>
#include "MyMath.h"
char Rank(REAL score);
int main()
{
	REAL s;
	char r;
	printf("������");
	scanf(RSF,&s);
	r = Rank(s);
	printf("�ȼ���%c\n",r);
	return 0;
}
char Rank(REAL score)
{
	int x;
	char y;
	x = score/10;
	switch(x)
	{
	case 10:
	case 9:
	    y = 'A';
	    break;
	case 8:
		y = 'B';
		break;
	case 7:
		y = 'C';
		break;
	case 6:
		y = 'D';
		break;
	default:
		y = 'E';
	} 
	return y;
}
