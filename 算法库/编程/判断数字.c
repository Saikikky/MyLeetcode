#include <stdio.h> 
#include "MyMath.h"
BOOL IsBinDigit(char x);//������ 
BOOL IsOctDigit(char x);//�˽��� 
BOOL IsDecDigit(char x);//ʮ���� 
BOOL IsHexDigit(char x);//ʮ������ 
int main()
{
	char x;
	printf("�ַ�: ");
	scanf("%c", &x);
	if (IsBinDigit(x))
	{
		puts("����������");
	}
	if (IsOctDigit(x))
	{
		puts("�˽�������");
	}
	if (IsDecDigit(x))
	{
		puts("ʮ��������");
	}
	if (IsHexDigit(x))
	{
		puts("ʮ����������");
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
