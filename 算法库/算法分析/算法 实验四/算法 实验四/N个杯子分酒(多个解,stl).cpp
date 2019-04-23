#include<iostream>
#include<iomanip>
#include<queue>
#include<vector> 
#include<conio.h> 
using namespace std;
#define N 6 
struct node
{
	int step;//当前状态是经过多少步产生的 
	int from,to;//经过from->to倒酒才产生当前酒杯状态S[0~n-1] 
	int S[N];//当前N个杯子装酒量,酒杯编号0~n-1(n<=N)
	struct node *parent;//指向父节点，即从哪个状态变成当前状态 
};
//创建队列Q，向量v，元素类型均为 node*，即树中节点的地址 
queue<node*>Q;//存放树中的所有叶子节点 
vector<node*>v;//存放树中的所有节点

//n为酒杯个数，A[]为酒杯的容量, D[]为酒杯目标装酒量    
int n=4,A[N]={12,7,5,4},D[N]={6,6,0,0};   
int cnt=0,Min;//cnt记录最优解个数，Min记录最优解的步数 

int isok(node *t)//判断t节点的酒杯状态S[]是否已达到目标
{
	int i;
	for(i=0;i<n;i++)//只要有一个杯子装酒量与目标不一致
		if(t->S[i]!=D[i]) return 0;		
	return 1;
}

void output(node *p)//输出从t到根节点的变化过程 
{
	int i,j;
	if(p->parent) output(p->parent);//先输出祖先节点中的状态
	if(p->parent) 
	{   cout<<endl<<setw(3)<<p->step<<"步：";
	    cout<<p->from<<"->"<<p->to<<"  ";
	}	
	else
	{   //根节点中输出杯子的容量 
	    cout<<"\n     杯容量  ";
		for(i=0;i<n;i++) cout<<setw(2)<<A[i]<<" ";
		cout<<"\n     杯初始  ";
	}          
	for(i=0;i<n;i++) cout<<setw(2)<<p->S[i]<<" ";
}
 
node* xianjie(node *p,int i,int j,int status)
{//status=0时，q节点不能与树中所有节点相同。找一个解的剪枝逻辑 
 //status=1时，q节点不能与q的祖先节点(即p到树根)相同。找所有解的剪枝逻辑 
	node *q;    int t,k;
	if(i==j)  return 0;//不能自己给自己倒
	if(p->S[i]==0)    return 0;//倒的杯子不能为空
	if(p->S[j]==A[j]) return 0;//接收的杯不能为满
	
	//倒出的状态，不能与前面的状态重复
	q=new node(*p);    
	if(p->S[i] < A[j]-p->S[j])//i杯酒 < j杯空间 
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
	{//找一个解的剪枝逻辑，将q与树中所有节点比较	
		for(t=0;t<v.size();t++)
		{
			for(k=0;k<n;k++)
			    if(q->S[k]!=v[t]->S[k]) break;
			if(k==n) break;//说明q节点与v[t]节点状态一样 
		}
	    if(t<v.size()){delete q; return 0; } 
    }
    else
    {//找所有解的剪枝逻辑，仅将q与其祖先节点比较 
    	node*p1;
	    for(p1=p;p1;p1=p1->parent)
	    {
	    	for(k=0;k<n;k++)
			    if(q->S[k]!=p1->S[k]) break;
			if(k==n) break;//说明q节点与p1节点状态一样 
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
	node *root=new node;//创建根节点 
    root->from =root->to =root->step =0;
    root->parent =0;
    root->S[0]=12;//三个杯子初始状态 
	root->S[1]=0;
	root->S[2]=0;
	root->S[3]=0;
	Q.push(root);
	v.push_back(root);
}

void BFS( )//找一个解的广度优先搜索 
{	int i,j;
    node *p,*q;
    init();//初始化根节点 
    cout<<"\n一个最优解算法结果：";
	while(!Q.empty())   
	{
	    p=Q.front();
		Q.pop();
		if(isok(p)) 
		{   Min=p->step ;//最优解的步数 
		    output(p);	
			break;//找到解即退出while
		}
		for(i=0;i<n;i++)
		   for(j=0;j<n;j++)
		      if(q=xianjie(p,i,j,0))
			  { 
			     Q.push(q); 
				 v.push_back(q);  
			  }	
	}	
	cout<<"\n访问节点数："<<v.size();
	getch();//释放节点内存之前，暂停一下，
	        //在资源管理器中查看此进程所占内存情况 
	for(int i=0;i<v.size();i++)
	    delete v[i];
	v.clear();  while(Q.size()) Q.pop() ;	
}

void BFS1()//找所有最优解的广度优先搜索 
{	
	int i,j;
    node *p,*q;     
    init();//初始化根节点
    cout<<"\n\n所有最优解算法结果：";
	if(Min==0) return ;//如果无解，直接结束。
	while(!Q.empty())   
	{
	    p=Q.front();
		Q.pop();
		if(isok(p)) 
		{  cout<<"\n解"<<++cnt;
		   output(p);	
		   //break; //找到解不退出while
		}
		else if(p->step<Min)//当p不是解且p->step<Min时，才有必要扩展其儿子节点 
		  for(i=0;i<n;i++)
		    for(j=0;j<n;j++)
		      if(q=xianjie(p,i,j,1))
			  {//与找一个解相比，剪枝逻辑的细微区别见xianjie函数status==1情况
			     Q.push(q); 
				 v.push_back(q);  
			  }	
	}	
	cout<<"\n一共访问节点数："<<v.size(); 
	getch();//释放节点内存之前，暂停一下，
	        //在资源管理器中查看此进程所占内存情况 
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
