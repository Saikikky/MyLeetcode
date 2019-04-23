#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;
	int letter = 0,number = 0,space = 0;
	printf("文字：");
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
	printf("字母：%d\n",letter);
	printf("数字：%d\n",number);
	printf("其它：%d",space);
	return 0;
}
