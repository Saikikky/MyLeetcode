#include <stdio.h>
#include <math.h>
int main()
{
	int a,b,c;
	printf("�� + �� = ��\n");
	printf("�� - �� = ��\n");
	printf("�� ���� = ��\n");
	printf("�� �¡� = ��\n");
	printf("�� + ��+ �� + ��= ��\n"); 
	printf("��=?");
	scanf("%d",&b);
	c=sqrt(b); 
    if(4*b>=0&&c*c==b)
	{
		a=c - 1;
		printf("�� = %d",a);
	} 
	else 
	{
		printf("�޽�");
	}
	return 0;
}
