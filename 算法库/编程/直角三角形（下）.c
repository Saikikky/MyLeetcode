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
	if(height>0)
	{
		Show(height,symbol);
		putchar('\n');
		ShowDnTrg(height-1,symbol);
	}
}
void Show(int number,char symol)
{
	if(number>=1)
	{
		Show(number-1,symol);
		putchar(symol);
	}
}

