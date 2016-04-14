template <class T>
class linkNode
{
	public:
		T data;
	linkNode<T> * next;
	linkNode(T &k, linkNode<T> * nextNode=NULL)
	{
		data=k;
		next=nextNode;
	}
};