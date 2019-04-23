#include<iostream>
#include<iomanip>
#include<queue>
#include<vector> 
#include<conio.h> 
using namespace std;
#define N 6 
struct node
{
	int step;//��ǰ״̬�Ǿ������ٲ������� 
	int from,to;//����from->to���ƲŲ�����ǰ�Ʊ�״̬S[0~n-1] 
	int S[N];//��ǰN������װ����,�Ʊ����0~n-1(n<=N)
	struct node *parent;//ָ�򸸽ڵ㣬�����ĸ�״̬��ɵ�ǰ״̬ 
};
//��������Q������v��Ԫ�����;�Ϊ node*�������нڵ�ĵ�ַ 
queue<node*>Q;//������е�����Ҷ�ӽڵ� 
vector<node*>v;//������е����нڵ�

//nΪ�Ʊ�������A[]Ϊ�Ʊ�������, D[]Ϊ�Ʊ�Ŀ��װ����    
int n=4,A[N]={12,7,5,4},D[N]={6,6,0,0};   
int cnt=0,Min;//cnt��¼���Ž������Min��¼���Ž�Ĳ��� 

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
	if(p->parent) 
	{   cout<<endl<<setw(3)<<p->step<<"����";
	    cout<<p->from<<"->"<<p->to<<"  ";
	}	
	else
	{   //���ڵ���������ӵ����� 
	    cout<<"\n     ������  ";
		for(i=0;i<n;i++) cout<<setw(2)<<A[i]<<" ";
		cout<<"\n     ����ʼ  ";
	}          
	for(i=0;i<n;i++) cout<<setw(2)<<p->S[i]<<" ";
}
 
node* xianjie(node *p,int i,int j,int status)
{//status=0ʱ��q�ڵ㲻�����������нڵ���ͬ����һ����ļ�֦�߼� 
 //status=1ʱ��q�ڵ㲻����q�����Ƚڵ�(��p������)��ͬ�������н�ļ�֦�߼� 
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
	if(status==0)
	{//��һ����ļ�֦�߼�����q���������нڵ�Ƚ�	
		for(t=0;t<v.size();t++)
		{
			for(k=0;k<n;k++)
			    if(q->S[k]!=v[t]->S[k]) break;
			if(k==n) break;//˵��q�ڵ���v[t]�ڵ�״̬һ�� 
		}
	    if(t<v.size()){delete q; return 0; } 
    }
    else
    {//�����н�ļ�֦�߼�������q�������Ƚڵ�Ƚ� 
    	node*p1;
	    for(p1=p;p1;p1=p1->parent)
	    {
	    	for(k=0;k<n;k++)
			    if(q->S[k]!=p1->S[k]) break;
			if(k==n) break;//˵��q�ڵ���p1�ڵ�״̬һ�� 
	    }
	    if(p1){ delete q; return 0; }
    }	
	q->from = i; q->to = j; 
	q->step =p->step +1;
	q->parent = p;
	return q;	
}

void init( )
{
	node *root=new node;//�������ڵ� 
    root->from =root->to =root->step =0;
    root->parent =0;
    root->S[0]=12;//�������ӳ�ʼ״̬ 
	root->S[1]=0;
	root->S[2]=0;
	root->S[3]=0;
	Q.push(root);
	v.push_back(root);
}

void BFS( )//��һ����Ĺ���������� 
{	int i,j;
    node *p,*q;
    init();//��ʼ�����ڵ� 
    cout<<"\nһ�����Ž��㷨�����";
	while(!Q.empty())   
	{
	    p=Q.front();
		Q.pop();
		if(isok(p)) 
		{   Min=p->step ;//���Ž�Ĳ��� 
		    output(p);	
			break;//�ҵ��⼴�˳�while
		}
		for(i=0;i<n;i++)
		   for(j=0;j<n;j++)
		      if(q=xianjie(p,i,j,0))
			  { 
			     Q.push(q); 
				 v.push_back(q);  
			  }	
	}	
	cout<<"\n���ʽڵ�����"<<v.size();
	getch();//�ͷŽڵ��ڴ�֮ǰ����ͣһ�£�
	        //����Դ�������в鿴�˽�����ռ�ڴ���� 
	for(int i=0;i<v.size();i++)
	    delete v[i];
	v.clear();  while(Q.size()) Q.pop() ;	
}

void BFS1()//���������Ž�Ĺ���������� 
{	
	int i,j;
    node *p,*q;     
    init();//��ʼ�����ڵ�
    cout<<"\n\n�������Ž��㷨�����";
	if(Min==0) return ;//����޽⣬ֱ�ӽ�����
	while(!Q.empty())   
	{
	    p=Q.front();
		Q.pop();
		if(isok(p)) 
		{  cout<<"\n��"<<++cnt;
		   output(p);	
		   //break; //�ҵ��ⲻ�˳�while
		}
		else if(p->step<Min)//��p���ǽ���p->step<Minʱ�����б�Ҫ��չ����ӽڵ� 
		  for(i=0;i<n;i++)
		    for(j=0;j<n;j++)
		      if(q=xianjie(p,i,j,1))
			  {//����һ������ȣ���֦�߼���ϸ΢�����xianjie����status==1���
			     Q.push(q); 
				 v.push_back(q);  
			  }	
	}	
	cout<<"\nһ�����ʽڵ�����"<<v.size(); 
	getch();//�ͷŽڵ��ڴ�֮ǰ����ͣһ�£�
	        //����Դ�������в鿴�˽�����ռ�ڴ���� 
	for(int i=0;i<v.size();i++)
	    delete v[i];
	v.clear();  while(Q.size()) Q.pop() ;	
}

int main()
{    
	BFS();
	BFS1();		
	return 0;
}
