#include "Hash.h"
#include <fstream>

int strhashfunc(const char *key, int size) {
	char *str = (char*)key;
	unsigned int hashval = 0;
	for (hashval = 0; *str; str++) {
		hashval = *str + (hashval << 5) - hashval;
	}
	return hashval % size;
}

void Hash::Create(int tableSize)
{
	size = tableSize;
	table = new Nptr[tableSize];
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
}

int Hash::Insert(const char * key)
{
	int hashval = strhashfunc(key, size);
	Nptr newNode = new node();
	Nptr ptr = table[hashval];
	newNode->next = nullptr;
	newNode->Data.Key = key;
	newNode->Data.count = 1;
	if (ptr == nullptr) {

		table[hashval] = newNode;
	}
	else {
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}

	return 1;
}

Nptr Hash::Search(const char * key)
{
	int hashval = strhashfunc(key, size);
	Nptr ptr = table[hashval];
	while (ptr != nullptr) {
		if (ptr->Data.Key == key) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return nullptr;
}

void Hash::Update(const char * key)
{
	int hashval = strhashfunc(key, size);
	Nptr ptr = table[hashval];
	while (ptr != nullptr) {
		if (ptr->Data.Key == key) {
			ptr->Data.count++;
			return;
		}
		ptr = ptr->next;
	}

	Nptr newNode = new node();
	ptr = table[hashval];
	newNode->next = nullptr;
	newNode->Data.Key = key;
	newNode->Data.count = 1;
	if (ptr == nullptr) {

		table[hashval] = newNode;
	}
	else {
		while (ptr->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}

	return;
}


void Hash::Delete(const char * key)
{
	int hashval = strhashfunc(key, size);
	Nptr ptr = table[hashval], prevPtr;
	if (ptr == nullptr) {
		return;
	}
	if (ptr->Data.Key == key) {
		table[hashval] = ptr->next;
		free(ptr);
		return;
	}
	prevPtr = ptr;
	ptr = ptr->next;
	while (ptr != nullptr) {
		if (ptr->Data.Key == key) {
			prevPtr->next = ptr->next;
			free(ptr);
			return;
		}
		ptr = ptr->next;
	}
}

void Hash::Save(const char * filename)
{
	ofstream out = ofstream(filename);
	out << size;
	for (int i = 0; i < size; i++) {
		Nptr ptr = table[i];
		while (ptr != nullptr) {
			out << ptr->Data.Key << endl;
			ptr = ptr->next;
		}
	}
	out.close();
}

void Hash::Open(const char * filename)
{
	ifstream is = ifstream(filename);
	string str;
	is >> size;
	while (!is.eof()) {
		is >> str;
		Insert(str.c_str());
	}
	is.close();
}

void Hash::Rehash(int newtablesize)
{
	Nptr *oldPtr = table;
	int oldSize = size;
	size = newtablesize;
	table = new node*[newtablesize];
	for (int i = 0; i < size; i++) {
		Nptr ptr = oldPtr[i];
		while (ptr != nullptr) {
			Insert(ptr->Data.Key.c_str());
			Nptr tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
		free(oldPtr[oldSize]);
	}
}