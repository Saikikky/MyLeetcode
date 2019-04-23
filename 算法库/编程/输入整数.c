#include <stdio.h>
#include "MyMath.h"
#include <ctype.h>
BOOL ScanBin(INTEGER *x);//������������Ȼ�� 
BOOL ScanOct(INTEGER *x);//�˽���������Ȼ�� 
BOOL ScanDec(INTEGER *x);//ʮ����������Ȼ�� 
BOOL ScanHex(INTEGER *x);//ʮ������������Ȼ�� 
BOOL IsBinDigit(char x);//�ж϶����� 
BOOL IsOctDigit(char x);//�жϰ˽��� 
BOOL IsDecDigit(char x);//�ж�ʮ���� 
BOOL IsHexDigit(char x);//�ж�ʮ������ 
int main()
{
	INTEGER r, x;
	BOOL ok = TRUE;
	printf("����: ");
	scanf(ISF, &r);
	switch (r)
	{
	case 2:
		printf("������: ");
		ScanBin(&x);
		break;
	case 8:
		printf("�˽���: ");
		ScanOct(&x);
		break;
	case 10:
		printf("ʮ����: ");
		ScanDec(&x);
		break;
	case 16:
		printf("ʮ������: ");
		ScanHex(&x);
		break;
	default:
		puts("����ȷ������!");
		ok = FALSE;
	}
	if (ok)
	{
		printf("ʮ����: " IPF "\n", x);
	}
	return 0;
}
BOOL ScanBin(INTEGER *x)
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
	while(IsBinDigit(c))
	{
		ok = 1;//����ѭ�� �Ƕ��������� 
		n = n * 2 + c - '0';//������������ת��Ϊʮ�������� ������n�б��� 
		c = getchar();//���������ַ� 
	}
	ungetc(c, stdin);//�������ַ��˻ص������� 
	if(ok)
	{
		*x = m == 1?-n:n;//��n�д�������ݽ���*x��� 
	} 
} 
BOOL ScanOct(INTEGER *x)
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
	while(IsOctDigit(c))
	{
		ok = 1;//����ѭ�� �ǰ˽������� 
		n = n * 8 + c - '0';//���˽�������ת��Ϊʮ�������� ������n�б��� 
		c = getchar();//���������ַ� 
	}
	ungetc(c, stdin);//�������ַ��˻ص������� 
	if(ok)
	{
		*x = m == 1?-n:n;//��n�д�������ݽ���*x��� 
	} 
} 
BOOL ScanDec(INTEGER *x)
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
	while(IsDecDigit(c))
	{
		ok = 1;//����ѭ�� ��ʮ�������� 
		n = n * 10 + c - '0';//��ʮ��������ת��Ϊʮ�������� ������n�б��� 
		c = getchar();//���������ַ� 
	}
	ungetc(c, stdin);//�������ַ��˻ص������� 
	if(ok)
	{
		*x = m == 1?-n:n;//��n�д�������ݽ���*x��� 
	} 
}
BOOL ScanHex(INTEGER *x)
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
	while(IsHexDigit(c))
	{
		ok = 1;//����ѭ�� ��ʮ��������
		c = toupper(c); //���ô�д��ĸ��ʾ 
		n = n * 16 + c - 'A' + 10;//��ʮ����������ת��Ϊʮ�������� ������n�б��� 
		c = getchar();//���������ַ� 
	}
	ungetc(c, stdin);//�������ַ��˻ص������� 
	if(ok)
	{
		*x = m == 1?-n:n;//��n�д�������ݽ���*x��� 
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
