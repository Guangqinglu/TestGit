// stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <typename T>

class myStack
{
public:
	myStack(int MaxStackSize=10);
	int GetMaxSize(){return MaxSize;};
	bool IsEmpty(){return (0==Length);};
	bool IsFull(){return (MaxSize==Length);};
	T Top();
	Push(T a);
	T Pop();
	~myStack();
private:
	int MaxSize;
	int Length;
	T * dataTable;
};
template <class T>
myStack<T>::myStack(int MaxStackSize)
{
	MaxSize=MaxStackSize;
	Length = 0;
	dataTable = new T[MaxSize];
}
template <class T>
T myStack<T>::Top()
{
	return dataTable[Length-1];
}

template <class T>
myStack<T>::Push(T a)
{
	dataTable[Length++] = a;
}

template <class T>
T myStack<T>::Pop()
{
	return dataTable[--Length];
}

template <class T>
myStack<T>::~myStack()
{
	if(dataTable!=NULL)
		delete []dataTable;
}

int _tmain(int argc, _TCHAR* argv[])
{
	myStack<int> stackTest(10);
	int i;
	for(i=0;i<5;i++)
	{
		stackTest.Push(i*i);
	}
	for(i=0;i<5;i++)
	{
		cout<<stackTest.Pop()<<endl;
	}
	//int a = stackTest.GetMaxSize();
	//cout<<12<<endl;
	cout<<stackTest.GetMaxSize()<<endl;
	cout<<stackTest.IsEmpty()<<endl;
	system("pause");
	return 0;
}

