#include <stdio.h>
#include <ctype.h>

int main()
{
	int k,a[26] = {0};
	char x;
	printf("������һ�����֣�\n");
	//while((x = toupper(getchar()) != '\n) 	
	for(x = getchar();x != '\n';x = getchar())
	{
		if(isalpha(x))
		{
			x = toupper(x);
			k = x - 'A';
			a[k]++;
		}
	}
	for(k = 0;k < 26;k++)
	{
		printf("%c:%d\n",k + 'A',a[k]);
	}
	return 0;
}
//for������������δ֪ѭ�������ĳ��� 
