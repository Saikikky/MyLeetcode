#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"

int main()
{
	REAL a[maxRArraySize];
	INTEGER n, k;

	printf("����: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("����ȷ������!");
		exit(1);
	}

	// ��������
	printf("����: ");
	for (k = 0; k < n; k++)
	{
		scanf(RSF, &a[k]);
	}

	// �������
	printf("����:");
	for (k = 0; k < n; k++)
	{
		printf(" " RPF, a[k]);
	}
	putchar('\n');
	return 0;
}
