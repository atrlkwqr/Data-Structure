#define GenericDoublyListP

template<typename T>
class node
{
public:
	T Data;
	node<T> *Prev, *Next;
};

template<typename T>
class listClass
{
private:
	int Count;
	node<T> *Head = NULL;
	node<T> *Temp = NULL;

public:
	listClass();
	listClass(const listClass &L);
	~listClass();
	void Insert(int Position, T Item);
	void Delete(int Position);
	void Retrieve(int Position, T & item);
	void PrintList();
	bool IsEmpty();
	int Length();
};