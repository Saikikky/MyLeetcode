#include <stdio.h>

int main()
{
	unsigned char c1, c2;
	printf("��  ��: ");
	scanf("%c%c", &c1, &c2);
	printf("��λ��: %04d\n",  (c1-160)*100+c2-160        );
	return 0;
}
