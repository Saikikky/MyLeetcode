#include <stdio.h>
 
int main()
{
	int n=0;
	double Chinese,Math,Physics,Chemistry,English;
	printf("语文：");
	scanf("%lg",&Chinese);
	printf("数学：");
	scanf("%lg",&Math); 
	printf("物理：");
	scanf("%lg",&Physics);
	printf("化学：");
	scanf("%lg",&Chemistry);
	printf("英语：");
	scanf("%lg",&English);
	if(Chinese<=60.0)
	{
		n++;
	}
	if(Math<=60.0)
	{
		n++;
	}
	if(Physics<=60.0)
	{
		n++;
	}
	if(Chemistry<=60.0)
	{
		n++;
	}
	if(English<=60.0)
	{
		n++;
	}
	if(n==0)
	{
		puts("升级"); 
	}
	else if(n<=2)
	{
	    puts("补考"); 
    }
    else if(n==5) 
    {
    	puts("退学"); 
    }
    else
    {
    	puts("留级");
    }
	return 0;
}
