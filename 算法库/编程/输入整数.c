#include <stdio.h>
#include "MyMath.h"
#include <ctype.h>
BOOL ScanBin(INTEGER *x);//二进制输入自然数 
BOOL ScanOct(INTEGER *x);//八进制输入自然数 
BOOL ScanDec(INTEGER *x);//十进制输入自然数 
BOOL ScanHex(INTEGER *x);//十六进制输入自然数 
BOOL IsBinDigit(char x);//判断二进制 
BOOL IsOctDigit(char x);//判断八进制 
BOOL IsDecDigit(char x);//判断十进制 
BOOL IsHexDigit(char x);//判断十六进制 
int main()
{
	INTEGER r, x;
	BOOL ok = TRUE;
	printf("基数: ");
	scanf(ISF, &r);
	switch (r)
	{
	case 2:
		printf("二进制: ");
		ScanBin(&x);
		break;
	case 8:
		printf("八进制: ");
		ScanOct(&x);
		break;
	case 10:
		printf("十进制: ");
		ScanDec(&x);
		break;
	case 16:
		printf("十六进制: ");
		ScanHex(&x);
		break;
	default:
		puts("不正确的数制!");
		ok = FALSE;
	}
	if (ok)
	{
		printf("十进制: " IPF "\n", x);
	}
	return 0;
}
BOOL ScanBin(INTEGER *x)
{
	char c;
	int n = 0,ok = 0,m = 0;
	c = getchar();//读取第一个字符 
	while(isspace(c))//字符是否为空格 
	{
		c = getchar();//继续读取字符 
	}
	if(c == '-')//字符是否为负号 
	{
		m = 1;// 是负号 
		c = getchar();//继续读取字符 
	}
	while(IsBinDigit(c))
	{
		ok = 1;//进入循环 是二进制数字 
		n = n * 2 + c - '0';//将二进制数字转换为十进制数字 储存在n中保存 
		c = getchar();//继续输入字符 
	}
	ungetc(c, stdin);//将错误字符退回到缓冲区 
	if(ok)
	{
		*x = m == 1?-n:n;//将n中储存的数据交给*x输出 
	} 
} 
BOOL ScanOct(INTEGER *x)
{
	char c;
	int n = 0,ok = 0,m = 0;
	c = getchar();//读取第一个字符 
	while(isspace(c))//字符是否为空格 
	{
		c = getchar();//继续读取字符 
	}
	if(c == '-')//字符是否为负号 
	{
		m = 1;// 是负号 
		c = getchar();//继续读取字符 
	}
	while(IsOctDigit(c))
	{
		ok = 1;//进入循环 是八进制数字 
		n = n * 8 + c - '0';//将八进制数字转换为十进制数字 储存在n中保存 
		c = getchar();//继续输入字符 
	}
	ungetc(c, stdin);//将错误字符退回到缓冲区 
	if(ok)
	{
		*x = m == 1?-n:n;//将n中储存的数据交给*x输出 
	} 
} 
BOOL ScanDec(INTEGER *x)
{
	char c;
	int n = 0,ok = 0,m = 0;
	c = getchar();//读取第一个字符 
	while(isspace(c))//字符是否为空格 
	{
		c = getchar();//继续读取字符 
	}
	if(c == '-')//字符是否为负号 
	{
		m = 1;// 是负号 
		c = getchar();//继续读取字符 
	}
	while(IsDecDigit(c))
	{
		ok = 1;//进入循环 是十进制数字 
		n = n * 10 + c - '0';//将十进制数字转换为十进制数字 储存在n中保存 
		c = getchar();//继续输入字符 
	}
	ungetc(c, stdin);//将错误字符退回到缓冲区 
	if(ok)
	{
		*x = m == 1?-n:n;//将n中储存的数据交给*x输出 
	} 
}
BOOL ScanHex(INTEGER *x)
{
	char c;
	int n = 0,ok = 0,m = 0;
	c = getchar();//读取第一个字符 
	while(isspace(c))//字符是否为空格 
	{
		c = getchar();//继续读取字符 
	}
	if(c == '-')//字符是否为负号 
	{
		m = 1;// 是负号 
		c = getchar();//继续读取字符 
	}
	while(IsHexDigit(c))
	{
		ok = 1;//进入循环 是十进制数字
		c = toupper(c); //都用大写字母表示 
		n = n * 16 + c - 'A' + 10;//将十六进制数字转换为十进制数字 储存在n中保存 
		c = getchar();//继续输入字符 
	}
	ungetc(c, stdin);//将错误字符退回到缓冲区 
	if(ok)
	{
		*x = m == 1?-n:n;//将n中储存的数据交给*x输出 
	} 
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
