#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;
	int letter = 0,number = 0,space = 0;
	printf("���֣�");
	c = getchar();
	while(c != '\n')
	{
		if(isdigit(c))
		{
			number++;
			c = getchar();
		}
		else if(isalpha(c))
		{
			letter++;
			c = getchar();
		}
		else 
		{
			space++;
			c = getchar();
		}
	}
	printf("��ĸ��%d\n",letter);
	printf("���֣�%d\n",number);
	printf("������%d",space);
	return 0;
}
