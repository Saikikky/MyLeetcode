#include <stdio.h>

int main()
{
	int a,b;
	for(a = 1;a <= 9;a++)
	{
		for(b = 1;b <= a;b++)
		{
			printf("%dx%d=%d",a,b,a * b);
			putchar('\0');
		}
		putchar('\n');
	}
	return 0;
}
