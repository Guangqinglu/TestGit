#define SHARP '#'
template <class T>
class BiTreeNode
{
private:
	T data;
	BiTreeNode<T> * left;
	BiTreeNode<T> * right;
public:
	void PreOrder(BiTreeNode<T> * root );
	void InOrder(BiTreeNode<T> *);
	void PostOrder(BiTreeNode<T> *);
	//void LevelOrder(BiTreeNode<T> *);
	//BiTreeNode(T a)
	//{
	//	//left=right=NULL;
	//	data=a;
	//};
	//BiTreeNode<T> * CreateTree(BiTreeNode<T> * p, T * data);
	void CreateTree(BiTreeNode<T> * p, T * data);
};

template<class T>
void BiTreeNode<T>::PreOrder(BiTreeNode<T> * root)
{
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

template<class T>
void BiTreeNode<T>::InOrder(BiTreeNode<T> * root)
{	
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

template<class T>
void BiTreeNode<T>::PostOrder(BiTreeNode<T> * root)
{
	PreOrder(root->left);
	PreOrder(root->right);
	cout<<root->data<<" ";
}

template<class T>
void BiTreeNode<T>::CreateTree(BiTreeNode<T> * p, T * data)
{
	static int i=0;
	//if(p==NULL)
	//	cout<<"return NULL"<<endl;
	if(data[i]!=SHARP)
	{
		BiTreeNode<T> * p=new BiTreeNode<T>();
		p->data=data[i];
		i++;
		cout<<"Create a node, data="<<p->data<<endl;
		CreateTree(p->left,data);
		CreateTree(p->right,data);
		//return p;
	}
	else if(data[i]==SHARP)
	{
		i++;
		p=NULL;
		//return NULL;
	}
}