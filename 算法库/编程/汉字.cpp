#include <stdio.h>

int main()
{
	int code;
	printf("��λ��: ");
	scanf("%d", &code);
	printf("��  ��: %c%c\n",  code/100+160  ,   code%100+160        );
	return 0;
}
