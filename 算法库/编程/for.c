#include <stdio.h> 

int main()
{
	char i;
	int sum = 0;
	for (i = 0;i < 127; i++)
	{
		sum += i;
	}
	printf ("%d\n",sum);
	return 0;
}

