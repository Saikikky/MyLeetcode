#include <stdio.h>
#include "MyMath.h"
BOOL ScanInteger(INTEGER *x,INTEGER r);
BOOL IsRDigit(char x, INTEGER r); 
int main()
{
	INTEGER x, r;
	printf("基数: ");
	scanf(ISF, &r);
	printf("整数: ");
	ScanInteger(&x, r);
	printf("十进制: ");
	PrintInteger(x, 10);
	putchar('\n');
	return 0;
}
BOOL ScanInteger(INTEGER *x,INTEGER r)
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
	if(r <= 10)//判断是否为r进制数 是就进循环 
	{
		while(IsRDigit(c,r))
		{
			ok = 1;//进入循环 
		    n = n * r + c - '0';//将r进制数字转换为十进制数字 储存在n中保存 
		    c = getchar();//继续输入字符 
		} 
	}
	else 
	{
		while(IsRDigit(c,r))
		{
			ok = 1;
			c = toupper(c); //都用大写字母表示 
		    n = n * r + c - 'A' + 10;//将r进制数字转换为十进制数字 储存在n中保存 
		    c = getchar();//继续输入字符 
		}
	}
	ungetc(c, stdin);//将错误字符退回到缓冲区 
	if(ok)
	{
		*x = m == 1?-n:n;//将n中储存的数据交给*x输出 
	} 
}
BOOL IsRDigit(char x, INTEGER r)
{
	int ok;
	if(r <= 10)
	{
		if(x >= '0'&&x <= r + '0' - 1)
		{
			ok = 1;
		}
		else
		{
			ok = 0;
		}
	}
	else
	{
		if(x >= '0'&&x <= '9')
		{
			ok = 1;
		}
		else if(x >= 'A'&&x <= r + 'A' - 11)
		{
			ok = 1;
		}
		else if(x >= 'a'&&x <= r + 'a' - 11)
		{
			ok = 1;
		}
		else
		{
			ok = 0;
		}
	}
	return ok;
}
void PrintInteger(INTEGER x, INTEGER r)
{
	INTEGER d;
	if (r < 2 || r > 36)
	{
		puts("不正确的基数!");
	}
	else if (x < 0)
	{
		putchar('-');
		PrintInteger(-x, r);
	}
	else
	{
		// 输出高位部分
		if (x >= r)
		{
			PrintInteger(x / r, r);
		}
		// 输出最低位
		d = x % r;
		if (d < 10)
		{
			putchar(d + '0');
		}
		else
		{
			putchar(d - 10 + 'A');
		}
	}
}

