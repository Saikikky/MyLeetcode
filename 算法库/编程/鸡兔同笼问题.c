#include <stdio.h>
int ChickenRabbit(int *chicken,int *rabbit,int head,int foot);
int main()
{
	int h,f,c,r;
	printf("ͷ:");
	scanf("%d",&h);
	printf("��:");
	scanf("%d",&f);
	if(ChickenRabbit(&c,&r,h,f))
	{
		printf("��:%d\n",c);
		printf("��:%d\n",r);
	}
	else
	{
		printf("�޽�\n");
	}
	return 0;
}
int ChickenRabbit(int *chicken,int *rabbit,int head,int foot)
{
	*chicken=(4*head-foot)/2;
	*rabbit=(foot-2*head)/2;
	if(*chicken-(int)*chicken==0&&*rabbit-(int)*rabbit==0&&*chicken>=0&&*rabbit>=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
