#include<stdio.h>
#include<windows.h>

int main()
{
	unsigned int Mounce;
	int i,j;
	unsigned int  a[10]={0};
	printf("�������������(0)����(1)��\n");
	for(i=0;i<10;i++)
	{
	  printf("��%2dֻ���������:",i+1);
	  scanf("%d",&a[i]);
	}
	Mounce = a[9];
	for(j=8;j>=0;j--)
	{
		Mounce = Mounce*2+a[j];
	}

	if(Mounce<1001)
	{
		printf("\n��%dͰ���ж�\n",Mounce);
	}
	else
	{
		printf("\n�磬��ȥ͵���˰ɣ�\n");
	}
	system("pause");
 return 0;
}
