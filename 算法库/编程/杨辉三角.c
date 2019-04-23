#include <stdio.h>
#include "MyMath.h"

void YangHui(int n);

int main()
{
	int n;
	printf("n = ? ");
	scanf("%d", &n);
	YangHui(n);
	return 0;
}

void YangHui(int n)
{
	INTEGER i,j,k = 1;
	for(i = 1;i <= n;i++)
    {
			for(j = n - i;j > 0;j--)
			{
				putchar(' ');
			}
			for(j = 1;j < i;j++)
			{
				printf("%d ",k);
				k = k * (i - j) / j;
			} 
			printf("%d ",k);
			putchar('\n');
    } 
}
//每次要打印的下一个数等于前一个数乘以其所在行数和列数的差
//在除以其列数

