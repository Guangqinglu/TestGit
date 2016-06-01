// recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int src,opb;
void inPart(int n,int m)
{
	if(n<=0||m<=0) return ;
	if(n==1) 
	{
		cout<<"+1";
		return;
		//return 1;
	}
	if(m==1)
	{
		if(n==src)
		{
			cout<<"q("<<src<<","<<opb<<")="<<"+1+...+1("<<n<<")"<<endl;
			return;
		}
		else
		{
			cout<<"+1+...+1("<<n<<")";
		}
	}
	if(n<m)
	{
		inPart(n,n);
	}
	if(n==m) 
	{
		if(n==src)
		{
			cout<<"q("<<src<<","<<opb<<")="<<n<<endl;
			inPart(n,m-1);
		}
		else
		{
			cout<<"+"<<n;
			inPart(n,m-1);
		}
	}
	else
	{
		inPart(n,m-1);
		if(n==src)
		{
			cout<<"q("<<src<<","<<opb<<")="<<m<<"+";
			inPart(n-m,m);
		}
		else
		{
			cout<<m<<"+";
			inPart(n-m,m);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	src=6;
	opb=6;
	inPart(6,6);
	system("pause");
	return 0;
}

