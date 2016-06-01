// stack_linknode.cpp : Defines the entry point for the console application.
//

 
#include "stdafx.h"
#include <iostream>
#include "stack2.h"
//#pragma once(#include "linknode.h")
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	myStack2<double> stackTest;
	int i;
	for(i=0;i<5;i++)
	{
		stackTest.Push((double(i))/566);
	}
	//stackTest.Push(5666);
	while(stackTest.top!=NULL)
	{
		cout<<stackTest.Pop()<<endl;
	}
	system("pause");
	return 0;
}

