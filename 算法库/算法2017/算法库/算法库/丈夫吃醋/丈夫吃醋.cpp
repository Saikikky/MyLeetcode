/*�ɷ�Դ�����  ���޹������⣺��3�Է��޹��ӣ����������2�ˣ���������һŮ�Ӳ��������ɷ��ڵ������������������һ��
                ��ΰ������Է��޹��ӣ�  
*/
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
#define MAX 101
typedef struct ren
{
	int r1;
	int r2;	
} Ren;

int n; // ����n<=10,�˵ı��1~2n����i��n+i�Ƿ���
Ren X[MAX]; //����ʱ�����˵ı�� 
int S[MAX][21];//���������10000�Σ� ����k�ι��Ӻ�2n���˵�״̬�����S[k][0~2n-1] 
//0,1�ֱ��ʾ�󰶡��Ұ�				 
int bestS[MAX][21],Min=100;//���Ź��ӹ���,Min�����ڵĽ�

int xianjie(int k,int r1,int r2)//r1,r2�����ϴ���r1Ϊ0��ʾֻ��r2һ���� 
{
	int i,j,c[2]={0}; //c[0~1]�ֱ�����Ҳ�������
		
	if(r1 == 0) //ֻ��r2һ�˹���	
	{ 
		if(S[k-1][r2]==k%2)  return 0;//r2�봬����ͬһ��
	}
	else//���r1,r2���˹���
	{
		if(S[k-1][r1]!=S[k-1][r2]//��r1,r2����ͬһ��
		   ||(k%2 == S[k-1][r1])) return 0; //�����봬����ͬһ��
		if(r2-r1>=n && r2-r1!=n)  return 0; //�������Ե����Ƿ���
	}	
	
	for(i=1;i<=2*n;i++)//״̬k-1  ==>  ״̬k
		S[k][i]=S[k-1][i];
	S[k][r1]= !S[k-1][r1]; //r1��״̬�䷴ 
	S[k][r2]= !S[k-1][r2]; //r2��״̬�䷴	
	for(i=1;i<=n;i++) c[S[k][i]]++;//���Ҳ�������ͳ�ƣ�S[k][i]=0��ʾ����i�����
	for(i=n+1;i<=2*n;i++)//�������Ů�ˣ����Ƿ�����Ϲ��������ȴ������������ͬһ�����
		if(S[k][i]!=S[k][i-n] && c[S[k][i]]) return 0;//S[k][i]=1��ʾŮ��i���Ҳ�
	for(i=0;i<k;i++)
	{
		for(j=1;j<=2*n;j++)
			if(S[k][j]!=S[i][j]) break;
			if(j>2*n) return 0;//״̬k��ǰ��ĳ״̬�ظ���
	}
	return 1; 	
}				 

int isok(int k)
{
	int i;
	for(i=1;i<=2*n;i++) 
		if(!S[k][i])  return 0; //��i�������
		return 1; 
}

void output(int s[][21],int k)
{
	int i,j,c=0;  static int count=0;
	cout<<"\n\n��"<<++count<<"  ������"<<k;
	for(i=0;i<=k;i++)
	{
		cout<<endl;
		for(j=1;j<=2*n;j++)//������˱��
			if(!s[i][j]) cout<<j<<",";
		cout<<"<==>";
		for(j=1;j<=2*n;j++)//����Ұ��˱��
			if(s[i][j]) cout<<j<<",";
	}
	getch();//���һ�������ͣ
}

void save(int k)
{
	int i,j;
	Min=k;
	for(i=0;i<=k;i++)
		for(j=1;j<=2*n;j++) bestS[i][j]=S[i][j];
}

void f(int k)//����k�ι��� 
{
	int i,j;
	if(k-1>Min) return ;//ֻ��100�����ڵĽ�
	if(isok(k-1))//��������˶����Ұ�����������
	{
		if(k-1<Min)  save(k-1);//�����ҵ��ĸ��ý�
		if(k-1==Min) output(S,k-1);//Min�ڶ�̬�仯�����һ�������������ý�
	} 
	else	 
	{	
		for(i=0;i<=2*n;i++)//������ˣ�i,j�����ӵ��������
			for(j=i+1;j<=2*n;j++)//iΪ0ʱ��ʾֻ��jһ�˹��� 
				if(xianjie(k,i,j))
				{
					X[k].r1=i;
					X[k].r2=j;
					f(k+1);	
				}	
	}
} 

int main()
{
	cin>>n; //n�Է���
	f(1);
	output(bestS,Min);//������洢��һ�����Ž�	
	return 0;
}