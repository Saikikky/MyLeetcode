#include <stdio.h>
#include "MyMath.h"
void ShowUpTrg(int height,char symbol);
void Show(int number,char symol);
int main()
{
	int h;
	char s;
	printf("h = ?");
	scanf("%d",&h) ;
	printf("s = ?");
	scanf(" %c",&s);
	ShowUpTrg(h,s);
	return 0;
} 
void ShowUpTrg(int height,char symbol)
{
	if(height>0)
	{
		ShowUpTrg(height-1,symbol);
		Show(height,symbol);
		putchar('\n');
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

