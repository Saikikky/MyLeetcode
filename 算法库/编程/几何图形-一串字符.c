#include <stdio.h>
#include "MyMath.h"
void Show(int number,char symol);
int main()
{
	int n;
	char s;
	printf("n = ?");
	scanf("%d",&n);
	printf("s = ?");
	scanf(" %c",&s);
	Show(n,s);
	putchar('\n');
	return 0;
}
void Show(int number,char symol)
{
	if(number>=1)
	{
		Show(number-1,symol);
		putchar(symol);
	}
}
