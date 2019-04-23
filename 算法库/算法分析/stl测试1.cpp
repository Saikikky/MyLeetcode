#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
	int x,y;
	bool operator <(const node&a)const
	{
		return x+y>a.x+a.y;
	}
};

int main()
{
	int i,a[10]={1,-2,5,4,3,6,-8,7,9,0};
	vector<int> v1(a,a+9),v2(5,1);
	vector<int>::iterator it;
	cout<<"\nv1:";
	for(it=v1.begin();it!=v1.end();it++)
	   {   cout<<*it<<" ";    }	   
	cout<<"\nv2:";
	for(i=0;i<v2.size();i++)
	   {   cout<<v2[i]<<" ";    }
    
    queue<char>Q;//先进先出队列     
    for(i=0;i<5;i++)Q.push('a'+i);
    cout<<endl<<"Q:";
    for(i=0;i<5;i++)
    {
    	cout<<Q.front()<<" "; 
    	Q.pop();
	}
    
    priority_queue<int>Q1;//大优先的队列Q1（默认） 
    priority_queue<int,vector<int>,greater<int> >Q2;//小优先队列Q2 
    for(i=0;i<10;i++)
    { 
	   Q1.push(a[i]); 
	   Q2.push(a[i]); 
    }
    cout<<"\nQ1:";
    while(!Q1.empty())
    {
    	cout<<Q1.top() <<" ";
    	Q1.pop() ;
    }
    cout<<"\nQ2:";
    while(!Q2.empty())
    {
    	cout<<Q2.top() <<" ";
    	Q2.pop() ;
    }
    
    priority_queue<node>myQ;//自定义数据类型的优先级队列 
    node t[3]={{1,2},{1,4,},{2,-1}};
	myQ.push(t[0]);    
	myQ.push(t[1]);
	myQ.push(t[2]);
	cout<<"\nmyQ:";
	while(!myQ.empty()) 
	{
		cout<<"{"<<myQ.top().x<<" "<<myQ.top().y<<"}";
		myQ.pop() ;
	}
	return 0;
}


