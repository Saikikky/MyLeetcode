#include <stdio.h>
#include "MyMath.h"
int IsNarcissus(int n);
int main()
{
	int n;
	printf("ÕûÊı£º");
	scanf("%d",&n);
	if(IsNarcissus(n))
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
int IsNarcissus(int n)
{
	int n1,n2,n3;
	n1 = n / 100;
	n2 = (n % 100) / 10;
	n3 =(n % 100) % 10;
	return (n == Cube(n1) + Cube(n2) + Cube(n3));
}
