#include<iostream>
#include<windows.h>
#include<math.h>
#include<conio.h>
#include<queue>
#include<vector>
using namespace std; 

struct node{
	int   step,len;//从根到当前节点状态走了step步，离目标至少len步 
	POINT d[9];//当前状态下数字0~9的行列号 
	int   chess[3][3];//当前状态对应的矩阵 
	struct node *parent;//指向当前节点的父节点	
};
struct cmp{ //自定义比较运算符 
		bool operator()(node *a,node *b)
		{
			return a->step+a->len > b->step+b->len;//step+len小的优先排队头 
		}
}; 

vector<node*>v;//v存树中所有节点的地址 
priority_queue<node*,vector<node*>,cmp>Q;//Q存树中所有叶子节点 
//Q的元素类型是指针型，并且确定优先级的比较函数cmp必须自定义实现。
 
POINT obj[9]={{1,1},{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0}},//目标状态 
      offset[4]={{-1,0},{0,1},{1,0},{0,-1}};//4种移动的坐标偏移值 
int  cnt=0;//解的移动步骤 

void output(node*t)
{	
	if(t->parent) output(t->parent);
	cout<<endl<<cnt++<<"步:"<<endl;
	for(int i=0;i<3;i++)
	{		
	    for(int j=0;j<3;j++)	
	       cout<<t->chess[i][j]<<" ";
	    cout<<endl;
    }
}

node* xianjie(node *p,int k)
{	
    node *q;
	int i=p->d[0].x+offset[k].x,j=p->d[0].y+offset[k].y,m;	
	if(i<0||i>2||j<0||j>2) return 0;
	q=new node(*p);
	m=p->chess[i][j]; 
	q->d[0].x =i; 
	q->d[0].y =j;
	q->d[m].x =p->d[0].x; 
	q->d[m].y=p->d[0].y; 			
	q->chess[p->d[0].x][p->d[0].y] = m;
	q->chess[i][j] = 0;
	q->step ++;
	q->len +=abs(p->d[0].x-obj[m].x)+abs(p->d[0].y-obj[m].y)-
	         (abs(i-obj[m].x)+abs(j-obj[m].y)); 
	q->parent = p;
	for(m=0;m<v.size();m++)
	{
	  for(i=0;i<9;i++)
		if(q->d[i].x!=v[m]->d[i].x || q->d[i].y!=v[m]->d[i].y) break;
	  if(i==9) break;
	}
	if(m<v.size()){ delete q; return 0;	}
	else    return q;	
}

int isok(node* t)
{	
	for(int i=0;i<9;i++) 
	   if(t->d[i].x!=obj[i].x || t->d[i].y!=obj[i].y)  return 0;
	return 1;
}

void Init()//创建并初始化根节点 
{
	node *t=new node;
	int i,j,num;
	cout<<"初始数据：\n";
	t->len = 0;
	for(i=0;i<3;i++)
	  for(j=0;j<3;j++)
	  {	  	 
	     cin>>num;
		 t->chess[i][j]=num;
		 t->d[num].x =i;
		 t->d[num].y =j;
		 if(num)
		    t->len += abs(obj[num].x-i)+abs(obj[num].y-j);		 
	  }
	t->step = 0;
	t->parent =0;
	Q.push(t);//根节点t进入队列Q 
	v.push_back(t);//根节点t进入向量v 
}

int main()
{
	node *p,*q;	
	Init();//初始化	
	while(!Q.empty())
	{
	    p=Q.top();//获取队头节点	
		Q.pop();//删除队头节点 
		if(isok(p)) 
		{
		   output(p);//输出从根到p节点的变化过程 
		   break;
		}
		for(int i=0;i<4;i++)//穷举p产生的所有儿子节点 
		   if(q=xianjie(p,i))//有效的节点会在xianjie中计算其评估值h(q)  
		   {                 //存放在q->len中 
		      Q.push(q);//以q->step+q->len小优先插入优先级队列Q 
			  v.push_back(q);  
		   } 	    
	}
	cout<<"\n访问节点数："<<v.size();
	getch();
	for(int i=0;i<v.size();i++)
	        delete v[i];
	return 0;
}
