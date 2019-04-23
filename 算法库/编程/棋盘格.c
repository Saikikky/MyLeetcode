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
	    printf("©³"); 
		for(j = 1;j < n;j++)
		{
			printf("©Ñ"); 
		}
		printf("©·\n");
		for(i = 1;i < n;i++)
		{
			printf("©Ç");
			for(j = 1;j < n;j++)
			{
				printf("©ç");
			}
			printf("©Ï\n");
		}
		printf("©»");
		for(i = 1;i < n;i++)
		{
			printf("©Û");
		}
		printf("©¿");
	}
}
