#define genericStackDL

#define MAX 100

template<typename T>
class node
{
public:
	T Data;
	node<T> *Prev, *Next;
};

template<typename T>
class queueClass
{
public:
	queueClass();
	queueClass(const queueClass& Q);
	~queueClass();
	void Add(T Item);
	void Remove();
	bool IsEmpty();
	bool IsFull();
	void PrintList();
private:
	node<T> *Rear;
	node<T> *Head = NULL;
	node<T> *Temp = NULL;
	int Count;
};