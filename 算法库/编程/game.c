#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Game();

int main()
{
	int n;
	char ch;
	printf("please enter Y to star\nplease enter N to quit\n");
	scanf("%c", &ch);
	n = ch;
	switch(n)
	{
		case  89: Game();break;
		case  78:     ;break;
	}
	return 0;
}
void Game(void)
{
	printf("c\n");
}

