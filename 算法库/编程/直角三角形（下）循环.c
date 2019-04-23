#include <stdio.h>
#include "MyMath.h"
void ShowDnTrg(int height,char symbol);
void Show(int number,char symol);
int main()
{
	int h;
	char s;
	printf("h = ?");
	scanf("%d",&h);
	printf("s = ?");
	scanf(" %c",&s);
	ShowDnTrg(h,s);
	return 0;
} 
void ShowDnTrg(int height,char symbol)
{
	if(height > 0)
	{
		int k = 1,H = height;
		while(k <= H)
		{
		   Show(height,symbol);
		   putchar('\n');
		   height--;
		   k++;
		}
	}
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
