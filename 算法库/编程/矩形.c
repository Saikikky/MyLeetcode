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
void ShowRect(int height,int width,char symbol)
{
	if(height<=0)
	{
		
	}
	else if(width<=0)
	{
		if(height>0)
		{
			putchar('\n');
			Show(height-1,symbol);
		}
	}
	else
	{
		if(height>0)
		{
		    Show(width,symbol);
		    putchar('\n');
		    ShowRect(height-1,width,symbol);
		}
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

