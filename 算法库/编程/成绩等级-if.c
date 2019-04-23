#include <stdio.h>
#include "MyMath.h"
char Rank(REAL score);
int main()
{
	REAL s;
	char r;
	printf("分数：");
	scanf(RSF,&s);
	r = Rank(s);
	printf("等级：%c\n",r);
	return 0;
}
char Rank(REAL score)
{
	if(score>=90)
	{
	    return 'A';
	} 
	else if(score>=80)
	{
		return 'B';
	}
	else if(score>=70)
	{
		return 'C';
	}
	else if(score>=60)
	{
		return 'D';
	}
	else
	{
		return 'E'; 
	}
}
