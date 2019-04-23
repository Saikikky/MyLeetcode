#include <stdio.h>
int main()
{
	int a;
	do
	{
		static int a = 2;
		a--;
		printf("abc");
	}
	while(a > 0);
}
