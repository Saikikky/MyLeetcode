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
	int k = 1;
	while(k <= number)
	{
		putchar(symol);
		k++; 
	}
} 
