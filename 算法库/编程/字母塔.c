#include <stdio.h>
#include "MyMath.h"
void Tower(int height);

int main()
{
	int h;
	printf("h = ? ");
	scanf("%d", &h);
	Tower(h);
	return 0;
}

void Tower(int height)
{
	int i,j;
	for(i = 1;i <= height;i++)
	{
		for(j = height - i;j > 0;j--)
		{
			putchar(' '); 
		}
		for(j = 1;j <= i;j++)
		{
			putchar(j - 1 + 'a');
		}
		for(j = j - 2;j > 0;j--)
		{
			putchar(j - 1 + 'a');
		} 
		putchar('\n');
	} 
}
