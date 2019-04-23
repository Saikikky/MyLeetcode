#include <stdio.h>
#include "MyMath.h"

void Rhombus(int h,int s);
void IsoscelesTriangle(int height,char symbol);

int main()
{
	int h;
	char s;
	printf("h = ? ");
	scanf("%d", &h);
	printf("s = ? ");
	scanf(" %c", &s);
	Rhombus(h, s);
	return 0;
}
void Rhombus(int h, int s)
{
	if(h % 2 == 1)
	{
		int i,j;
		IsoscelesTriangle((h + 1) / 2,s);
		for(i = (h + 1) / 2 - 1;i > 0;i--)
		{
			for(j = (h + 1) / 2 - i;j > 0;j--)
			{
				putchar(' ');
			}
			for(j = 2 * i - 1;j > 0;j--)
			{
				putchar(s);
			}
			putchar('\n');
		}
	}
	else
	{
		puts("不正确的参数！"); 
	}
}
void IsoscelesTriangle(int height,char symbol)
{
	int i,j;
	if(height > 0)
	{
		for(i = 1;i <= height;i++)
		{
			for(j = height - i;j > 0;j--)
			{
				putchar(' ');
			}
			for(j = 2 * i - 1;j > 0;j--)
			{
				putchar(symbol);
			}
			putchar('\n');
		}
	}
}
