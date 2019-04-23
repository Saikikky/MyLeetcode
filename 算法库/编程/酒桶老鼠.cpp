#include <stdio.h> 
 
int main ()
{
	int i, m = 0, mouse[10];
	printf ("输入老鼠的存活状态（0 - 死亡  1 - 存活）\n");
	for (i = 0;i < 10;i ++) 
	{
		printf ("第%d只老鼠的存活情况:",i+1);
		scanf ("%d",mouse + i);
	}
	for (i = 0;i < 10;i ++)
	{
		m = m * 2+ mouse[i];
	}
	if (m > 0&&m < 1000)
	{
		printf ("第%d桶酒有毒", m);
	}
	return 0;
}
