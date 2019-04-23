#include <stdio.h>
#include "MyMath.h"
void PrintInteger(INTEGER x,INTEGER r);
int main()
{
	INTEGER x,r;
	printf("整数：");
	scanf(ISF,&x);
	printf("基数：");
	scanf(ISF,&r);
	printf("结果：");
	PrintInteger(x,r);
	putchar('\n');
	return 0;
}
