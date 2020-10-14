#include<iostream>
#include<cstring>
using namespace std;
union u
{
	int i;
	char ch;
};
struct queue
{
	int tag;
	int f;
	int r;
	union u elements[50];
	int size;
};
void enqueue(queue &q,char x)
{
	int tag;
	if(q.f==(q.r+1)%q.size)
		cout<<"queue is full";
	else
	{
		if(q.r==-1)
			q.f=0;
		q.r=(q.r+1)%q.size;
		cout<<"enter tag char =0,int=1"<<endl;
		cin>>q.tag;
		if(q.tag==0)
			q.elements[q.r].ch=x;
		else
			q.elements[q.r].i=x-'0';		
		}	
}
u dequeue(queue &q)
{
	u t;
	if(q.f==-1)
		cout<<"queue is empty";
	else
	{
		t=q.elements[q.f];
		if(q.f==q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
			q.f=(q.f+1)%q.size;
		}	
		return t;
}
int eval(int b,int a,char c)
{
	switch(c)
		{
			case'+':
					return a+b;
					break;
				case'-':
					return a-b;
					break;
				case'*':
					return a*b;
					break;
				case'/':
					return a/b;
					break;
								
		}
}

int main()
{
	struct queue q;
	q.f=-1;
	q.r=-1;
	q.size=50;
	string s;
	u a,b,c;
	cout<<"enter prefix list"<<endl;
	getline(cin,s);
	a=dequeue(q);
	while(q.f!=q.r)
	{
		if(!isdigit(a))
			dequeue(q);
		else
		{
			enqueue(q,a);
			a=b;
			b=c;
				c=dequeue(q);
			}	
	}
	cout<<dequeue(q)<<endl;
}
