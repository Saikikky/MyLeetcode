#include <stdio.h>
#include "MyMath.h"
BOOL IsOdd(INTEGER n);
BOOL IsEven(INTEGER n);
int main()
{
	INTEGER n;
	printf("����:");
	scanf(ISF,&n);
	if(IsOdd(n))
	{
		puts("����"); 
	}
	if(IsEven(n))
	{
		puts("ż��"); 
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
