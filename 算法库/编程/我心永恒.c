#include <stdio.h>

int main()
{
forever:
	printf("I\3U!");
	goto forever;
	return 0;
}

