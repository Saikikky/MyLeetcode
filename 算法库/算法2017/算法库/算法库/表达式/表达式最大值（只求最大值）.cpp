/*������������������վ��Ŀ  ���ʽ���ֵ�� 
������Ŀ�ܼ򵥣�����n�����֣����ı����ǵ����λ�ã����м����k���˺ź�n-n-1���Ӻţ�
   ���������ӣ�ʹ���ս����������Ϊ�˺źͼӺ�һ������n-1���ˣ�����ǡ��ÿ��������
   ����֮�䶼��һ�����š����磺
����n=5��k=2��5�����ֱַ�Ϊ1��2��3��4��5�����Լӳɣ�
����1*2*(3+4+5)=24
����1*(2+3)*(4+5)=45
����(1*2+3)*(4+5)=45
��������

�⣺�������£� 
���м����ŵı��ʽ������ʽ�϶�Ϊ���� 
(a[i]x[i]...  a[m]) x[m] (a[m+1]x[m+1]...a[j])
//a[]�ǲ�����,x[]�������
// i<= m <j

x[m]��2�������+ ��  *
(1)x[m]��+ʱ����ô���"����벿����s��*���Ұ벿����t-s��*"��������� 
(2)x[m]��*ʱ����ô���"����벿����s��*���Ұ벿����t-1-s��*"���������
�����������е����ֵ���ɡ�

f(i,j,k)��ʾa[i]...a[j]��Щ�������м����k���˷� j-i-k���ӷ���
�ܹ��ɵı��ʽ���ֵ������f(1,n,k)���ɡ������������a[0~n-1]ʱ������f(0,n-1,k)����
����ƹ�ϵʽΪ��
            �������                     j-i<k   //���������<t�����ڲ����쳣����� 
            a[i]*...*a[j]                j-i==k  //ȫ���ǳ˷�
f(i,j,k)={  a[i]+...+a[j]                k==0    //ȫ���Ǽӷ� 
                                         
										 m��[i,j-1],������ 
            max{f(i,m,s)+f(m+1,j,k-s)��  s<=m-i && k-s<=j-(m+1)
                f(i,m,s)*f(m+1,j,k-1-s)} s<=m-i && k-1-s<=j-(m+1)
����ʽдdp�������£� 
*/ 

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>

long long int max(long long int x, long long int y)
{
	return x > y ? x : y;
}

long long int tag[15][15][15];

long long int a[20];

long long int f(int i, int j, int k)//�ݹ���dp 
{
	if (k < 0) return 1LL << 63;
	if (tag[i][j][k] != -1)  return tag[i][j][k];//�Ѿ������ 
	if (k == 0)//ȫ�Ǽ� 
	{
		long long int sum = 0; 
		for (int count = i; count <= j; count++)
		{
			sum += a[count];
		}
		return tag[i][j][k] = sum;
	}
	else if (k == j - i)//ȫ�ǳ� 
	{
		long long int sum = 1;
		for (int count = i; count <= j; count++)
		{
			sum *= a[count];
		}
		return tag[i][j][k] = sum;
	}
	else//�ӡ���  ��� 
	{
		long long int Max = 1LL << 63;//long long���ͳ��� 1LL 
		for (int m = i; m < j; m++)
		{
			for (int s = k - j + m; s <= m - i && s <= k; s++)
			{
				if (s < 0 || k-s-1 < 0) continue;//sΪ���*������k-s-1Ϊ�Ҳ�����*���� 
				
				Max = max(f(i,m,s) + f(m+1,j,k-s), Max);//��ӣ��Ҳ�˺Ų���1 
				Max = max(Max,f(i,m, s) * f(m+1,j,k-s-1));//��ˣ��Ҳ�˺Ÿ�����1				
			}
		}
		return tag[i][j][k] = Max;
	}
}

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		memset(tag, -1, sizeof(tag));//tag[][][]��ʼ��Ϊ��δ���㡱��־��-1Ҳ���Ը���0x80 
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		cout << f(0, n - 1, k) << endl;
	}

	return 0;
}
