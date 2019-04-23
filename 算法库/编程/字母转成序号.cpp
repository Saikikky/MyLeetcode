#include <stdio.h>
#include <ctype.h>

int main()

{
	int x,y;
	x=toupper(getchar());
	y=x-64;
	printf("%d",y);
	return 0;
}

