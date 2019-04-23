#include <stdio.h>

int main()

{
	char d1,d2,d3;
	int v;
	scanf("%c%c%c",&d1,&d2,&d3);
	v=(d1-48)*100+(d2-48)*10+(d3-48);
	printf("ֵ=%d\n",v);
	return 0;
}
