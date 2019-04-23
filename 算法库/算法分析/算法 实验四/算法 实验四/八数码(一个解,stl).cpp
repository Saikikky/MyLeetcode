#include<iostream>
#include<windows.h>
#include<math.h>
#include<conio.h>
#include<queue>
#include<vector>
using namespace std; 

struct node{
	int   step,len;//�Ӹ�����ǰ�ڵ�״̬����step������Ŀ������len�� 
	POINT d[9];//��ǰ״̬������0~9�����к� 
	int   chess[3][3];//��ǰ״̬��Ӧ�ľ��� 
	struct node *parent;//ָ��ǰ�ڵ�ĸ��ڵ�	
};
struct cmp{ //�Զ���Ƚ������ 
		bool operator()(node *a,node *b)
		{
			return a->step+a->len > b->step+b->len;//step+lenС�������Ŷ�ͷ 
		}
}; 

vector<node*>v;//v���������нڵ�ĵ�ַ 
priority_queue<node*,vector<node*>,cmp>Q;//Q����������Ҷ�ӽڵ� 
//Q��Ԫ��������ָ���ͣ�����ȷ�����ȼ��ıȽϺ���cmp�����Զ���ʵ�֡�
 
POINT obj[9]={{1,1},{0,0},{0,1},{0,2},{1,2},{2,2},{2,1},{2,0},{1,0}},//Ŀ��״̬ 
      offset[4]={{-1,0},{0,1},{1,0},{0,-1}};//4���ƶ�������ƫ��ֵ 
int  cnt=0;//����ƶ����� 

void output(node*t)
{	
	if(t->parent) output(t->parent);
	cout<<endl<<cnt++<<"��:"<<endl;
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

void Init()//��������ʼ�����ڵ� 
{
	node *t=new node;
	int i,j,num;
	cout<<"��ʼ���ݣ�\n";
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
	Q.push(t);//���ڵ�t�������Q 
	v.push_back(t);//���ڵ�t��������v 
}

int main()
{
	node *p,*q;	
	Init();//��ʼ��	
	while(!Q.empty())
	{
	    p=Q.top();//��ȡ��ͷ�ڵ�	
		Q.pop();//ɾ����ͷ�ڵ� 
		if(isok(p)) 
		{
		   output(p);//����Ӹ���p�ڵ�ı仯���� 
		   break;
		}
		for(int i=0;i<4;i++)//���p���������ж��ӽڵ� 
		   if(q=xianjie(p,i))//��Ч�Ľڵ����xianjie�м���������ֵh(q)  
		   {                 //�����q->len�� 
		      Q.push(q);//��q->step+q->lenС���Ȳ������ȼ�����Q 
			  v.push_back(q);  
		   } 	    
	}
	cout<<"\n���ʽڵ�����"<<v.size();
	getch();
	for(int i=0;i<v.size();i++)
	        delete v[i];
	return 0;
}
