// OnelinkNode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OnelinkNode.h"
#include <iostream>
using namespace std;

class Onelink
{
	public:
		OnelinkNode<int> * head;
		Onelink(int * data,int n);
		~Onelink();
		bool IsEmpty(){return NULL==head;}
		int length();
		OnelinkNode<int> * index(int i);
		int get(int i);
		bool set(int i,int k);
		OnelinkNode<int> * insert(OnelinkNode<int> *p,int k);
		void reverse();
		bool remove(OnelinkNode<int> *p);
		void output();
};

Onelink::Onelink(int *data,int n)
{
	head=NULL;
	if(n>0)
	{
		OnelinkNode<int> *p,*q;
	    p = new OnelinkNode<int>();
		p->data=data[0];
		head=q=p;
		for(int i=1;i<n;i++)
		{
			p=new OnelinkNode<int>();
			p->data=data[i];
			q->next=p;
			q=p;
		}
		q->next=NULL;
	}
}

Onelink::~Onelink()
{
	OnelinkNode<int> *p;
	while(head!=NULL)
	{
		p=head;
		head=head->next;
		delete p;
	}
}

int Onelink::length()
{
	OnelinkNode<int> *p=head;
	int i=0;
	while(NULL!=p)
	{
		p=p->next;
		i++;
	}
	return i;
}

OnelinkNode<int> * Onelink::index(int i)
{
	if(i<=0)
		return NULL;
	int j=0;
	OnelinkNode<int> * p=head;
	while(NULL!=p)
	{
		if(++j==i)
			return p;
		p=p->next;
	}
	return NULL;
}

int Onelink::get(int i)
{
	OnelinkNode<int> * p=index(i);
	if(NULL==p)
	{
		return -1;
	}
	else
	{
		return(p->data);
	}
}

bool Onelink::set(int i,int k)
{
	OnelinkNode<int> * p=index(i);
	if(NULL==p)
		return false;
	p->data=k;
	return true;
}

OnelinkNode<int> *Onelink::insert(OnelinkNode<int> *p,int k)
{
	if(NULL==p)
	{
		return NULL;
	}
	else
	{
		OnelinkNode<int> * q=new OnelinkNode<int>();
		q->data=k;
		q->next=p->next;
		p->next=q;
		return p;
	}
}
bool Onelink::remove(OnelinkNode<int> *p)
{
	if(NULL!=p)
	{
		OnelinkNode<int> * q=p->next;
		if(NULL==q)
		{
			delete p;
			p=NULL;
			return true;
		}
		p->data=q->data;
		p->next=q->next;
		delete q;
		return true;
	}
	else
		return false;
}
void Onelink::output()
{
	for(int i=1;i<=length();i++)
		cout<<get(i)<<" ";
	cout<<endl;
}
void Onelink::reverse()
{
	if(NULL==head||NULL==head->next)
		return;
	else
	{
		OnelinkNode<int> * p=head->next;
		OnelinkNode<int> * q;
		head->next=NULL;
		while(NULL!=p)
		{
			q=p->next;
			p->next=head;
			head=p;
			p=q;
		}
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	int test[9]={1,2,3,4,5,6,7,8,9};
	Onelink mytest(test,9);
	mytest.output();
	mytest.reverse();
	mytest.output();
	system("pause");
	return 0;
}

