#include <stdio.h>
 
int main()
{
	int n=0;
	double Chinese,Math,Physics,Chemistry,English;
	printf("���ģ�");
	scanf("%lg",&Chinese);
	printf("��ѧ��");
	scanf("%lg",&Math); 
	printf("����");
	scanf("%lg",&Physics);
	printf("��ѧ��");
	scanf("%lg",&Chemistry);
	printf("Ӣ�");
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
		puts("����"); 
	}
	else if(n<=2)
	{
	    puts("����"); 
    }
    else if(n==5) 
    {
    	puts("��ѧ"); 
    }
    else
    {
    	puts("����");
    }
	return 0;
}
