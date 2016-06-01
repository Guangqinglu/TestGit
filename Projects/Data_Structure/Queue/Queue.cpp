// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"
#include <iostream>
using namespace std;

void Output(int &minH,int &minS,Queue<int> H[],int n,int k)
{
	int i=0;
	H[minS].Delete();
	cout<<"Move car "<<minH<<" from holding track "<<minS<<" to output"<<endl;
	minH=n+1;
	minS=-1;
	for(i=0;i<k;i++)
	{
		if(minH>H[i].First()&&!(H[i].IsEmpty()))
		{
			minH=H[i].First();
			minS=i;
		}
	}

}

bool Hold(int c,Queue<int>H[],int &minH, int &minS,int n,int k)
{
	int temp=0;
	int pos=-1;
	int i,j;
	int flag=0;
	for(j=0;j<k;j++)
	{
		if(H[j].IsEmpty())
		{
			flag=1;//At last one is empty
			break;
		}
	}
	for(i=0;i<k;i++)
	{
		if(!(H[i].IsEmpty())&&temp<H[i].Last())
		{
			if(c>H[i].Last())
			{
				temp=H[i].Last();
				pos=i;
			}
		}
	}
	if(pos==-1&&flag==0)
	{
		return false;
	}
	else if(pos==-1&&flag==1)
	{
		H[j].Add(c);
		cout<<"Move car "<<c<<" from input"<<" to holding track "<<j<<endl;
	}
	else
	{
		H[pos].Add(c);
		cout<<"Move car "<<c<<" from input"<<" to holding track "<<pos<<endl;
	}
	minH=n+1;
	minS=-1;
	for(i=0;i<k;i++)
	{
		//cout<<"H[i].isempty="<<H[i].IsEmpty()<<"H[i].First()="<<H[i].First()<<endl;
		if(!(H[i].IsEmpty())&&minH>H[i].First())
		{
			minH=H[i].First();
			minS=i;
		}
	}
	return true;
}

bool RailRoad(int p[],int n,int k)
{
	Queue<int> *H=new Queue<int>[k];
	int NowOut=1;
	int minH=n+1;
	int minS=-1;
	int i;
	for(i=0;i<n;i++)
	{
		if(p[i]==NowOut)
		{
			cout<<"Move car "<<p[i]<<" from input to output"<<endl;
			NowOut++;
			while(minH==NowOut&&NowOut<=n)
			{
				Output(minH,minS,H,n,k);
				NowOut++;
			}
		}
		else
		{
			if(!Hold(p[i],H,minH,minS,n,k))
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
	//int start[11]={5,8,4,2,6,7,8,9,1};
	int start[11]={11,5,8,1,7,4,2,9,6,3,10};
	//Queue<int> * H=new Queue<int>[5];
	//for(int i=0;i<5;i++)
	//{
	//	H[i].Add(i);
	//	cout<<H[i].First()<<"and"<<H[i].Last()<<endl;
	//}
	RailRoad(start,11,11);
	system("pause");
	return 0;
}

