/*��n*2�ľ����У�������λ�ÿ�ʼ�����Ժᡢ����б45�ȡ�б135��ˢ��
ÿһ������ֻ��ˢһ�Σ�ˢ�Ӳ��������������ж�����ˢ�����������1000000007��������

��f1(n)��ʾ�����Ͻǳ��������ж�����ˢ��������ƹ�ϵ����
          1                                 n=1 
f1(n)={   6                                 n=2
          2f1(n-1)+4f1(n-2)+2^(n-1)         n>2


��f(n)��ʾ������λ�ó��������ж�����ˢ����������ʼλ����Ҫ��Ϊ�������
һ�������ĸ�����λ�ã�һ���Ƿǽ���λ�ã�
����λ�ó����ļ�Ϊ4f1(n),
���ಿ��Ϊ�ǽ���λ��(1,i)����(2,i)��1<i<n��������
        2                                                n=1
f(n)= { 24                                               n=2
        4f1(n)+4��[2^��i-1��*f1(n-i)+2^��n-i��*f1(i-1)]  n>2,����1<i<n
*/

#include<iostream.h>
#define MAX 100
#define MM  1000000007

int F1[MAX],F[MAX];

int f1(int n)
{
	if(F1[n]) return F1[n];
	else if(n==1) return F1[n]=1;
	else if(n==2) return F1[n]=6;
	else 
	{
		int s=1,i;
		F1[n]=((2*f1(n-1))%MM+((f1(n-2)*2)%MM *2)%MM )%MM;
		for(i=1;i<n;i++) s=(s*2)%MM;
		F1[n]=(F1[n]+s)%MM;
		return F1[n];
	}
}

//4f1(n)+4��[2^��i-1��*f1(n-i)+2^��n-i��*f1(i-1)]  n>2,����1<i<n
int f(int n)
{
	if(F[n])      return F[n];
	else if(n==1) return F[n]=2;
	else if(n==2) return F[n]=24;
	else
	{			
		for(int i=2;i<n;i++)
		{
			int j,s=f1(n-i);
			for(j=1;j<i;j++)  s=(s*2)%MM;
			F[n]=(F[n]+s)%MM;
			s=f1(i-1);
			for(j=0;j<n-i;j++)s=(s*2)%MM;
			F[n]=(F[n]+s)%MM;
		}
		F[n]=(F[n]+f1(n))%MM;
		return F[n]=(((F[n]*2)%MM)*2)%MM;
	}
}

void main()
{
	int n=1;
	while(n<100)
	{
		cout<<endl<<n<<":"<<f(n)<<" "<<f1(n);
		n++;
	}
}