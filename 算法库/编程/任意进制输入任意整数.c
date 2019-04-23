#include <stdio.h>
#include "MyMath.h"
BOOL ScanInteger(INTEGER *x,INTEGER r);
BOOL IsRDigit(char x, INTEGER r); 
int main()
{
	INTEGER x, r;
	printf("����: ");
	scanf(ISF, &r);
	printf("����: ");
	ScanInteger(&x, r);
	printf("ʮ����: ");
	PrintInteger(x, 10);
	putchar('\n');
	return 0;
}
BOOL ScanInteger(INTEGER *x,INTEGER r)
{
	char c;
	int n = 0,ok = 0,m = 0;
	c = getchar();//��ȡ��һ���ַ� 
	while(isspace(c))//�ַ��Ƿ�Ϊ�ո� 
	{
		c = getchar();//������ȡ�ַ� 
	}
	if(c == '-')//�ַ��Ƿ�Ϊ���� 
	{
		m = 1;// �Ǹ��� 
		c = getchar();//������ȡ�ַ� 
	}
	if(r <= 10)//�ж��Ƿ�Ϊr������ �Ǿͽ�ѭ�� 
	{
		while(IsRDigit(c,r))
		{
			ok = 1;//����ѭ�� 
		    n = n * r + c - '0';//��r��������ת��Ϊʮ�������� ������n�б��� 
		    c = getchar();//���������ַ� 
		} 
	}
	else 
	{
		while(IsRDigit(c,r))
		{
			ok = 1;
			c = toupper(c); //���ô�д��ĸ��ʾ 
		    n = n * r + c - 'A' + 10;//��r��������ת��Ϊʮ�������� ������n�б��� 
		    c = getchar();//���������ַ� 
		}
	}
	ungetc(c, stdin);//�������ַ��˻ص������� 
	if(ok)
	{
		*x = m == 1?-n:n;//��n�д�������ݽ���*x��� 
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
		puts("����ȷ�Ļ���!");
	}
	else if (x < 0)
	{
		putchar('-');
		PrintInteger(-x, r);
	}
	else
	{
		// �����λ����
		if (x >= r)
		{
			PrintInteger(x / r, r);
		}
		// ������λ
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

