#include<stdio.h>
#include<windows.h>

int main()
{
	unsigned int Mounce;
	int i,j;
	unsigned int  a[10]={0};
	printf("请输入老鼠的生(0)和死(1)：\n");
	for(i=0;i<10;i++)
	{
	  printf("第%2d只老鼠的生死:",i+1);
	  scanf("%d",&a[i]);
	}
	Mounce = a[9];
	for(j=8;j>=0;j--)
	{
		Mounce = Mounce*2+a[j];
	}

	if(Mounce<1001)
	{
		printf("\n第%d桶酒有毒\n",Mounce);
	}
	else
	{
		printf("\n哥，你去偷酒了吧！\n");
	}
	system("pause");
 return 0;
}
