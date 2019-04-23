#include <stdio.h>
#include "MyMath.h"
void PrintDec (INTEGER x);
void PrintBin (INTEGER x);
void PrintOct (INTEGER x);
void PrintHex (INTEGER x);
int main()
{
	INTEGER x;
	printf("自然数：");
	scanf(ISF,&x);
	
	printf("十进制：");
	PrintDec(x);
	putchar('\n');
	
	printf("二进制：");
	PrintBin(x);
	putchar('\n');
	
	printf("八进制：");
	PrintOct(x);
	putchar('\n');
	
	printf("十六进制：");
	PrintHex(x);
	putchar('\n');
	return 0; 
} 
void PrintDec (INTEGER x)
{
	if(x<10)
	{
		putchar(x % 10 + '0');
	}
	else
	{
		PrintDec(x / 10);
		putchar(x % 10 + '0');
	}
}
void PrintBin (INTEGER x)
{
	if(x<2)
	{
		putchar(x % 2 + '0');
	}
	else
	{
		PrintBin(x / 2);
		putchar(x % 2 + '0');
	}
}
void PrintOct (INTEGER x)
{
	if(x<8)
	{
		putchar(x % 8 + '0');
	}
	else
	{
		PrintOct(x / 8);
		putchar(x % 8 + '0');
	}
}
void PrintHex (INTEGER x)
{
	if(x<16)
	{
		if(x<10)
		{
			putchar(x + '0');
		}
		else
		{
			putchar(x + 'A' - 10);
		}
	}
	else
	{
	    if(x % 16 <10)
	    {
	    	PrintHex(x/16);
	    	putchar(x % 16 + '0');
	    }
	    else
	    {
	    	PrintHex(x/16);
	    	putchar(x%16 + 'A' - 10);
	    }
	}
}
