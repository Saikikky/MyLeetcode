#include <stdio.h> 
#include "MyMath.h"
BOOL IsBinDigit(char x);//二进制 
BOOL IsOctDigit(char x);//八进制 
BOOL IsDecDigit(char x);//十进制 
BOOL IsHexDigit(char x);//十六进制 
int main()
{
	char x;
	printf("字符: ");
	scanf("%c", &x);
	if (IsBinDigit(x))
	{
		puts("二进制数字");
	}
	if (IsOctDigit(x))
	{
		puts("八进制数字");
	}
	if (IsDecDigit(x))
	{
		puts("十进制数字");
	}
	if (IsHexDigit(x))
	{
		puts("十六进制数字");
	}
	return 0;
}
BOOL IsBinDigit(char x)
{
	return x == '1'||x == '0';
}
BOOL IsOctDigit(char x)
{
	return x >= '0'&&x <= '7';
}
BOOL IsDecDigit(char x)
{
	return x >= '0'&&x <= '9';
}
BOOL IsHexDigit(char x)
{
	return x >= '0'&&x <= '9'||x >= 'a'&&x <= 'f'||x >= 'A'&&x <= 'F';
}
