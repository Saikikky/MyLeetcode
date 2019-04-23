#include <stdio.h>
#include "MyMath.h"
BOOL IsOdd(INTEGER n);
BOOL IsEven(INTEGER n);
int main()
{
	INTEGER n;
	printf("整数:");
	scanf(ISF,&n);
	if(IsOdd(n))
	{
		puts("奇数"); 
	}
	if(IsEven(n))
	{
		puts("偶数"); 
	}
	return 0;
}
BOOL IsOdd(INTEGER n)
{
	return 1 == n % 2;
}
BOOL IsEven(INTEGER n)
{
	return 0 == n % 2;
}
