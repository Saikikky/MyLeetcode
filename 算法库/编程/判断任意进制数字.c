#include <stdio.h>
#include "MyMath.h"
BOOL IsRDigit(char x, INTEGER r);
int main()
{
	INTEGER x, r;
	char c;
	printf("»ùÊý: ");
	scanf(ISF, &r);
	printf("Êý×Ö: ", r);
	scanf(" %c", &c);
	if (IsRDigit(c, r)) 
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
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
