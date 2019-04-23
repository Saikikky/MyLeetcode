#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	if (a >= b) goto tag1;
	if (a >= c) goto tag3;
	if (c >= b) goto tag4;
	goto tag3;
tag1:
	if (b >= c) goto tag2;
	if (c >= a) goto tag4;

tag2:
	printf("%d\n", a);
	goto tag5;

tag3:
	printf("%d\n", b);
	goto tag5;

tag4:
	printf("%d\n", c);

tag5:
	return 0;
}
