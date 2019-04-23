#include <stdio.h>

int main()
{
	int code;
	printf("ÇøÎ»Âë: ");
	scanf("%d", &code);
	printf("ºº  ×Ö: %c%c\n",  code/100+160  ,   code%100+160        );
	return 0;
}
