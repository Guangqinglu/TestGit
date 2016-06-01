// sortRailRoad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack2.h"
#include <iostream>
using namespace std;

void Output(int &minH,int &minS,myStack2<int> H[],int k)
{
	int i=0;
	H[minS].Pop();
	cout<<"Move car "<<minH<<" from holding track "<<minS<<" to output"<<endl;
	minH=H[0].Top();
	minS=0;
	for(i=1;i<k;i++)
	{
		if(minH>H[i].Top())
		{
			minH=H[i].Top();
			minS=i;
		}
	}

}

bool Hold(int c, int &minH, int &minS,myStack2<int>H[],int n,int k)
{
	int temp=n+2;
	int pos=-1;
	int i;
	for(i=0;i<k;i++)
	{
		if(temp>H[i].Top()&&c<H[i].Top())
		{
			temp=H[i].Top();
			pos=i;
		}
	}
	if(pos==-1)
	{
		return false;
	}
	else
	{
		H[pos].Push(c);
		cout<<"Move car "<<c<<" from input"<<" to holding track "<<pos<<endl;
	}
	minH=H[0].Top();
	minS=0;
	for(i=1;i<k;i++)
	{
		if(minH>H[i].Top())
		{
			minH=H[i].Top();
			minS=i;
		}
	}
	return true;
}

bool RailRoad(int p[],int n,int k)
{
	myStack2<int> *H=new myStack2<int>[k];
	int NowOut=1;
	int minH=n+1;
	int minS;
	int i;
	for(i=0;i<k;i++)
		H[i].Push(n+1);
	for(i=0;i<n;i++)
	{
		if(p[i]==NowOut)
		{
			cout<<"Move car "<<p[i]<<" from input to output"<<endl;
			NowOut++;
			while(minH==NowOut&&NowOut<=n)
			{
				Output(minH,minS,H,k);
				NowOut++;
			}
		}
		else
		{
			if(!Hold(p[i],minH,minS,H,n,k))
			{
				cout<<"No suitable car position for"<<p[i]<<endl;
				return false;
			}
		}
	}
	return true;
}


int _tmain(int argc, _TCHAR* argv[])
{
	//int start[11]={11,5,8,1,7,4,2,9,6,3,10};
	int start[11]={2,3,4,5,6,7,8,9,10,11,1};
	RailRoad(start,11,11);
	system("pause");
	return 0;
}

