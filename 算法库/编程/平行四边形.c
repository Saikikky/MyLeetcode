#include <stdio.h>
#include "MyMath.h"

void Parallelogram(int height,int width,char symbol);
void Show(int number,char symol);
int main()
{
	int h, w;
	char s;
	printf("h = ? ");
	scanf("%d", &h);
	printf("w = ? ");
	scanf("%d", &w);
	printf("s = ? ");
	scanf(" %c", &s);
	Parallelogram(h, w, s);
	return 0;
}
void Parallelogram(int height,int width,char symbol)
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
		    Show(width,symbol);
		    putchar('\n');
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
