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
class stackClass
{
public:
	stackClass();
	stackClass(const stackClass& S);
	~stackClass();
	void Push(T Item);
	int Pop();
	void GetTop(T& Item);
	bool IsEmpty();
	bool IsFull();
	void PrintList();
private:
	node<T> *Top;
	node<T> *Head = NULL;
	node<T> *Temp = NULL;
	int Count;
};