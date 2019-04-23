/*쳲���������
         1              i==1||i==2
  f(i)={ f(i-1)+f(i-2)  i>2
*/
#include<iostream>
using namespace std;
#define MAX 100000

int F[MAX]; //F[i]�洢f(i)��ֵ����ʼֵ0
int a[MAX]; //a[i]�洢f(i)���ظ��������

int f(int i)//���ݹ�д��
{
	if(i<1) return -1;
	a[i]++;
	if(i==1 || i==2) return 1;
	else return f(i-1)+f(i-2);
}

int dp1(int i)//�ݹ��͵Ķ�̬�滮д��
{
	if(F[i]) return F[i];//���F[i]�Ѿ����������־����0��������ֱ�ӷ���
	a[i]++;  //����if()������ʱ��a[i]++�Ż�ִ�С�
	if(i==1 || i==2) return F[i]=1;
	else             return F[i]=dp1(i-1)+dp1(i-2);
}

int main(void)
{ 
	int i,n;
	cout<<"Enter n(<100):";
	cin>>n;
	
	cout<<"f(n)="<<f(n)<<endl;
	for(i=n ;i>0 ;i--) 
		cout<<"a["<<i<<"]="<<a[i] <<endl;
	//�����Բ��� for(i=1;i<=n;i++) cout<<"f(n)="<<f(n)<<endl; 
	//���Է��֣���n�ﵽ43���ϣ�������Ҫʱ������Ըо�Խ��Խ����˵�����ݹ�д��Ч�ʵͣ�ԭ�����f(i)������ظ�����
	
	for(i=n ;i>0 ;i--) 	a[i]=0;//���㣬׼��ִ��dp1������
	cout<<"\nf(n)="<<dp1(n)<<endl;
	for(i=n ;i>0 ;i--) //�ٴβ鿴f(i)���������
		cout<<"a["<<i<<"]="<<a[i] <<endl;

	return 0;
}
