#include <stdio.h>

void Grid(int n);

int main()
{
	int n;
	printf("n = ? ");
	scanf("%d", &n);
	Grid(n);
	return 0;
}
void Grid(int n)
{
	int j,i;
	if(n)
	{
	    printf("��"); 
		for(j = 1;j < n;j++)
		{
			printf("��"); 
		}
		printf("��\n");
		for(i = 1;i < n;i++)
		{
			printf("��");
			for(j = 1;j < n;j++)
			{
				printf("��");
			}
			printf("��\n");
		}
		printf("��");
		for(i = 1;i < n;i++)
		{
			printf("��");
		}
		printf("��");
	}
}
