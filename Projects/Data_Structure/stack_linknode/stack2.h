#include "linknode.h"

template <class T>
class myStack2
{
public:
	myStack2(){top=NULL;};
	T Top();
	Push(T a);
	T Pop();
	~myStack2();
	bool IsEmpty(){return(NULL==top);};
	linkNode<T> * top;
};

template <class T>
T myStack2<T>::Top() 
{
	if(top!=NULL)
		return (top->data);
}

template <class T>
myStack2<T>::Push(T a)
{
	linkNode<T> * temp = new linkNode<T>(a);
	temp->next=top;
	top=temp;
}

template <class T>
T myStack2<T>::Pop() 
{
	T k;
	if(top!=NULL)
	{
		linkNode<T> * temp = top;
		k = temp->data;
		top = temp->next;
		delete temp;
	}
	return k;
}

template <class T>
myStack2<T>::~myStack2()
{
	linkNode<T> * temp;
	while(top!=NULL)
	{
		temp=top;
		top=top->next;
		delete temp;
	}
}