#include <stdio.h> 
 
int main ()
{
	int i, m = 0, mouse[10];
	printf ("��������Ĵ��״̬��0 - ����  1 - ��\n");
	for (i = 0;i < 10;i ++) 
	{
		printf ("��%dֻ����Ĵ�����:",i+1);
		scanf ("%d",mouse + i);
	}
	for (i = 0;i < 10;i ++)
	{
		m = m * 2+ mouse[i];
	}
	if (m > 0&&m < 1000)
	{
		printf ("��%dͰ���ж�", m);
	}
	return 0;
}
