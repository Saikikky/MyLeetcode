/*2015��ʡ����
13����ֵ���˿��ƣ�ÿ������4�ֻ�ɫ����52���ƣ������ó�13�ţ�һ���ж����ֿ��ܣ������ǻ�ɫ����

 ��f(n,k)��ʾ��n������ȡ��k�ţ��ж��ٷ���������f(13,13)���ɡ�
             0                k>4n��k<0   
    f(n,k)={ 1                k=4n��k=0 
	         f(n-1,k)+
			 f(n-1,k-1)+
			 f(n-1,k-2)+      0<k<4n   
			 f(n-1,k-3)+
			 f(n-1,k-4)
*/
#include<iostream>
using namespace std;
int F[100][100];//F[i][j]���������ʽ��
                //f(i,j)��Ӧ

int f(int n,int k)
{
	if(F[n][k])          return F[n][k];
	if(k>4*n || k<0)     return 0;
	else if(k==4*n||k==0)return F[n][k]=1;
	else return F[n][k]=f(n-1,k)+
		                f(n-1,k-1)+
						f(n-1,k-2)+
						f(n-1,k-3)+
						f(n-1,k-4);
}

int main()
{	
	int k=13;
	cout<<endl<<k<<":"<<f(13,13)<<endl;//��13��������13���ж����ַ���
    //��������ֵ
	for(k=0;k<=52;k++)
		cout<<endl<<k<<":"<<f(13,k);//��13��������k���ж����ַ���
	return 0;
}