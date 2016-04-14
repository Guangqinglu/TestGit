template <class T>
class Queue
{
public:
	Queue(int MaxQueueSize=20);
	~Queue(){delete [] queue;};
	bool IsEmpty(){return rear==front;};
	bool IsFull(){return full;};
	T First();
	T Last();
	bool Add(T x);
	T Delete();
private:
	int front;
	int rear;
	int MaxSize;
	//bool empty;
	//bool full;
	T * queue;
};

template <class T>
Queue<T>::Queue(int MaxQueueSize)
{
	MaxSize=MaxQueueSize;
	queue=new T[MaxSize];
	front=rear=0;
//	empty=true;
	//full=false;
}

template <class T>
T Queue<T>::First()
{
	return queue[front];
}

template <class T>
T Queue<T>::Last()
{
	return queue[rear-1];
}

template <class T>
bool Queue<T>::Add(T x)
{
	if((rear+1)%MaxSize==front)
	{
		cout<<"Queue is full"<<endl;
		return false;
	}
	queue[rear]=x;
	rear=(rear+1)%MaxSize;
	return true;
}

template <class T>
T Queue<T>::Delete()
{
	T temp=queue[front];
	front=(front+1)%MaxSize;
	return temp;
}