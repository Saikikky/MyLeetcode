#include <stdio.h>
#include "MyMath.h"

void Parallelogram(int height,int width,char symbol);
void Show(int number,char symol);
void IsoscelesTriangle(int height,char symbol);
void Rhombus(int h,int s);

int main()
{
	int h,w,s;
    char c;
    do
    {
    	printf("I-���������� P-ƽ���ı��� R-���� Q-�˳� >_");
    	scanf("%c",&c);
    	fflush(stdin);
    	if(c == 'I'||c == 'i')
    	{
    		printf("h = ? ");
			scanf("%d", &h);
			printf("s = ? ");
			scanf(" %c", &s);
			IsoscelesTriangle(h, s);
	    }
	    else if(c == 'P'||c == 'p')
	    {
	    	printf("h = ? ");
			scanf("%d", &h);
			printf("w = ? ");
			scanf("%d", &w);
			printf("s = ? ");
			scanf(" %c", &s);
			Parallelogram(h, w, s);
		}
		else if(c == 'r'||c == 'R')
		{
			printf("h = ? ");
            scanf("%d", &h);
        	printf("s = ? ");
	        scanf(" %c", &s);
        	Rhombus(h, s);
		}
		else if(c == 'q'||c == 'Q')
		{
			exit(1);
		}
		else
		{
			puts("����ȷ��ѡ�");
		}
		fflush(stdin);
    	putchar('\n');
    	
    }
    while(c);
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
		puts("����ȷ�Ĳ�����"); 
	}
}
