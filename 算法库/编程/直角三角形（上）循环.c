#include <stdio.h>
#include "MyMath.h"
void ShowUpTrg(int height,char symbol);
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
	if(height > 0)
	{
		int i,j;
		for(i = 1;i <= height;i++)
		{
			for(j = 1;j <= i;j++)
			{
				putchar(symbol);
			}
			putchar('\n');
		}
	}
} 
