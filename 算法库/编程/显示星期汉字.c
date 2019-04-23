#include <stdio.h>
#include "MyMath.h"
#include <stdlib.h>
void ShowDow(INTEGER x);
int main()
{
	INTEGER w;
	printf("星期：");
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
		puts("日");
	    break;
	case 1:
		puts("一");
		break;
	case 2:
		puts("二");
		break; 
	case 3:
		puts("三");
		break;
	case 4:
		puts("四");
		break;
	case 5:
		puts("五");
		break;
	case 6:
		puts("六");
		break;
	default:
	    exit(1); 
	}
}
