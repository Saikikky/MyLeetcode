#include <stdio.h>

int main()
{
	int n = 0;
	double a,b,c,d,e,f,g,h,i,j;
	printf("��ѧ���ģ�");
	scanf("%lg",&a); 
	printf("�ߵ���ѧ��");
	scanf("%lg",&b); 
	printf("��ѧӢ�");
	scanf("%lg",&c); 
	printf("��ѧ�����������");
	scanf("%lg",&d); 
	printf("����ѧԭ��");
	scanf("%lg",&e); 
	printf("ͳ��ѧ��");
	scanf("%lg",&f); 
	printf("���ڹ���ѧ��");
	scanf("%lg",&g); 
	printf("����ѧԭ��");
	scanf("%lg",&h); 
	printf("֤ȯͶ��ѧ��");
	scanf("%lg",&i); 
	printf("�罻���ǣ�");
	scanf("%lg",&j); 
	if(a >= 60)
	{
		n = n + 4;
	} 
    if(b >= 60)
    {
    	n = n + 8;
    }
    if(c >= 60)
    {
    	n = n + 4;
    }
    if(d >= 60)
    {
    	n = n + 2;
    }
    if(e >= 60)
    {
    	n = n + 4;
    }
    if(f >= 60)
    {
    	n = n + 3;
    }
    if(g >= 60)
    {
    	n = n + 3;
    }
    if(h >= 60)
    {
    	n = n + 2;
    }
    if(i >= 60)
    {
    	n = n + 3;
    }
    if(j >= 60)
    {
    	n = n + 1;
    }
    printf("ѧ��=%d\n",n);
    if(n>=28)
    {
    	printf("��ҵ"); 
    }
    else
    {
    	printf("��ҵ"); 
    }
	return 0;
} 
