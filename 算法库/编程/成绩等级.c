#include <stdio.h>
char Rank(double score);
int main()
{
	double s;
	char r;
	printf("³É¼¨:");
	scanf("%lg",&s);
	r = Rank(s);
    printf("µÈ¼¶:%c\n",r);
	return 0;
}
char Rank(double score)
{
	char A,B,C,D,E;
	if(score<60)
	{
		return 'E';
	}
	else if(score>=60&&score<70)
	{
		return  'D';
	}
	else if(score>=70&&score<80)
	{
		return  'C';
	}
	else if(score>=80&&score<90)
	{
	    return 	 'B'; 
	}
	else
	{
		return 'A';
	}
	
}
