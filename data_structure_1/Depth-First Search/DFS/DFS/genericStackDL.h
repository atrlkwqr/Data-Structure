#define genericStackDL
#define MAX 100
#define size_templog 10

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
	void Pop();
	T GetTop();
	bool IsEmpty();
	bool IsFull();
	void PrintList();
	void Linking(char a, int temp);
private:
	node<T> *Top;
	node<T> *Head ;
	node<T> *Temp;
	int Count;
};