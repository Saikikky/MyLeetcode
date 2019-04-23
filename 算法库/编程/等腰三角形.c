#include <stdio.h>
#include "MyMath.h"

void IsoscelesTriangle(int height,char symbol);

int main()
{
	int h;
	char s;
	printf("h = ? ");
	scanf("%d", &h);
	printf("s = ? ");
	scanf(" %c", &s);
	IsoscelesTriangle(h, s);
	return 0;
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
