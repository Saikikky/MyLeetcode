#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

int main()
{
	REAL a[maxRArraySize];
	INTEGER n, k;

	printf("项数: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("不正确的项数!");
		exit(1);
	}

	// 输入数组
	printf("数组: ");
	for (k = 0; k < n; k++)
	{
		scanf(RSF, &a[k]);
	}

	// 输出数组
	printf("数组:");
	for (k = 0; k < n; k++)
	{
		printf(" " RPF, a[k]);
	}
	putchar('\n');
	return 0;
}
