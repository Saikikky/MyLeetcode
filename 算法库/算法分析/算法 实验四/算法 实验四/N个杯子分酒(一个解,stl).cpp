#include<iostream>
#include<queue>
#include<vector> 
#include<conio.h> 
using namespace std;
#define N 6 
struct node
{
	int from,to;//����from->to���ƲŲ�����ǰ�Ʊ�״̬S[0~n-1] 
	int S[N];//��ǰN������װ����,�Ʊ����0~n-1(n<=N)
	struct node *parent;//ָ�򸸽ڵ㣬�����ĸ�״̬��ɵ�ǰ״̬ 
};
//��������Q������v��Ԫ�����;�Ϊ node*�������нڵ�ĵ�ַ 
queue<node*>Q;//������е�����Ҷ�ӽڵ� 
vector<node*>v;//������е����нڵ�
    
int n=3,A[N]={12,8,5},D[N]={6,6,0};
   //A[]Ϊ�Ʊ�������, D[]Ϊ�Ʊ�Ŀ��װ����
int isok(node *t)//�ж�t�ڵ�ľƱ�״̬S[]�Ƿ��ѴﵽĿ��
{
	int i;
	for(i=0;i<n;i++)//ֻҪ��һ������װ������Ŀ�겻һ��
		if(t->S[i]!=D[i]) return 0;		
	return 1;
}

void output(node *p)//�����t�����ڵ�ı仯���� 
{
	int i,j;
	if(p->parent) output(p->parent);//��������Ƚڵ��е�״̬
	cout<<endl<<p->from<<"->"<<p->to<<"  ";
	for(i=0;i<n;i++) cout<<p->S[i]<<" ";
}
 
node* xianjie(node *p,int i,int j)
{
	node *q;    int t,k;
	if(i==j)  return 0;//�����Լ����Լ���
	if(p->S[i]==0)    return 0;//���ı��Ӳ���Ϊ��
	if(p->S[j]==A[j]) return 0;//���յı�����Ϊ��
	
	//������״̬��������ǰ���״̬�ظ�
	q=new node(*p);    
	if(p->S[i] < A[j]-p->S[j])//i���� < j���ռ� 
	{
		q->S[i]=0;  
		q->S[j]=p->S[j]+p->S[i];
	}
	else
	{
		q->S[i]=p->S[i]-(A[j]-p->S[j]);  
		q->S[j]=A[j];
	}
	for(t=0;t<v.size();t++)
	{
		for(k=0;k<n;k++)
		    if(q->S[k]!=v[t]->S[k]) break;
		if(k==n) break;//˵��q�ڵ���v[t]�ڵ�״̬һ�� 
	}
	if(t<v.size()){delete q; return 0; } 
	else
	{
		  q->from = i; q->to = j;
		  q->parent = p;
		  return q;
	}
}

void init( )
{
	node *root=new node;//�������ڵ� 
    root->from =root->to =0;
    root->parent =0;
    root->S[0]=12;//�������ӳ�ʼ״̬ 
	root->S[1]=0;
	root->S[2]=0;
	Q.push(root);
	v.push_back(root);
}

void BFS( )//����������� 
{	int i,j;
    node *p,*q;
    init();//��ʼ�����ڵ� 
	while(!Q.empty())   
	{
	    p=Q.front();
		Q.pop();
		if(isok(p)) {output(p);	break;}//�ҵ��⼴�˳�while
		for(i=0;i<n;i++)
		   for(j=0;j<n;j++)
		      if(q=xianjie(p,i,j))
			  { Q.push(q); v.push_back(q);  }	
	}
	getch();//�ͷŽڵ��ڴ�֮ǰ����ͣһ�£�
	        //����Դ�������в鿴�˽�����ռ�ڴ���� 
	for(int i=0;i<v.size();i++)
	    delete v[i];
}

int main()
{    
	BFS();	
	return 0;
}
