#include <stdio.h>
#include "MyMath.h"
#include <stdlib.h>
void ShowDow(INTEGER x);
int main()
{
	INTEGER w;
	printf("���ڣ�");
	scanf(ISF,&w);
	ShowDow(w);
	putchar('\n');
	return 0;
} 
void ShowDow(INTEGER x)
{
	switch(x)
	{
	case 0:
		puts("��");
	    break;
	case 1:
		puts("һ");
		break;
	case 2:
		puts("��");
		break; 
	case 3:
		puts("��");
		break;
	case 4:
		puts("��");
		break;
	case 5:
		puts("��");
		break;
	case 6:
		puts("��");
		break;
	default:
	    exit(1); 
	}
}
