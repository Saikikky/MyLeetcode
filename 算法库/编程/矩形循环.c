#include <stdio.h>
#include "MyMath.h"
void ShowRect(int height,int width,char symbol);
void Show(int number,char symol);
int main()
{
	int h,w;
	char s;
	printf("h = ?");
	scanf("%d",&h);
	printf("w = ?");
	scanf("%d",&w);
	printf("s = ?");
	scanf(" %c",&s);
	ShowRect(h,w,s);
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
void ShowRect(int height,int width,char symbol)
{
	int k = 1;
	if(height <= 0)
	{
		
	}
	else if(width <= 0)
	{
		if(height > 0)
		{
			while(k <= height)
			{
				putchar('\n');
				k++;
			}
		}
	}
	else
	{
		while(k <= height)
		{
			Show(width,symbol);
			putchar('\n');
		    k++;
		}
	}
} 
