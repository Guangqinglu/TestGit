// BiTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "BiTreeNode2.h"
#define SHARP '#'
using namespace std;

void PreOrder(BiTreeNode<char> * root)
{
	if(NULL==root)
	{
		return;
	}
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BiTreeNode<char> * root)
{	
	if(NULL==root)
	{
		return;
	}
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

void PostOrder(BiTreeNode<char> * root)
{
	if(NULL==root)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

BiTreeNode<char>* CreateTree(BiTreeNode<char> * p, char *data)
{
	static int i=0;
	if(data[i]!=SHARP)
	{
		if(i!=0)
		{
			p=new BiTreeNode<char>();
		}
		p->data=data[i];
		i++;
		cout<<"Create a node, data="<<p->data<<endl;
		p->left=CreateTree(p->left,data);
		p->right=CreateTree(p->right,data);
		return p;
	}
	else if(data[i]==SHARP)
	{
		i++;
		return NULL;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	char *str="ABD#G###CE##FH###";
	BiTreeNode<char> * root=new BiTreeNode<char>();
	CreateTree(root,str);
	PreOrder(root);
	cout<<endl;
	InOrder(root);
	cout<<endl;
	PostOrder(root);
	cout<<endl;
	system("pause");
	return 0;
}

