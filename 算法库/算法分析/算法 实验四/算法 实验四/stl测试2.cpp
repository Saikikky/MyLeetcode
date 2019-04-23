#include<iostream>
#include<queue>
#include<vector>
using namespace std; 

struct node{
	int   step,len;//从根到当前节点状态走了step步，离目标至少len步 
	bool  operator < (const node &a)const
	{
		return step+len > a.len + a.step ;
	} 
};
struct cmp 
{
	bool operator()(node *a,node *b)
	{
		return a->step+a->len > b->step+b->len;//step+len小的优先排队头 
	}
};

int main()
{
   priority_queue<node>Q;
   priority_queue<node*, vector<node*>, cmp> pQ;
   node a[4]={{1,1},{-2,-2},{2,2},{-8,1}};	
   for(int i=0;i<4;i++) 
   {
   	  Q.push(a[i]); 
      pQ.push(a+i);
   }
   
   cout<<"\nQ:";
   while(!Q.empty())
   {
   	  cout<<"{"<<Q.top().step<<" "<<Q.top().len<<"}";
	  Q.pop() ;  
   } 
   
   cout<<"\npQ:";
   while(!pQ.empty())
   {
   	  cout<<"{"<<pQ.top()->step<<" "<<pQ.top()->len<<"}";
	  pQ.pop() ;  
   } 
}
