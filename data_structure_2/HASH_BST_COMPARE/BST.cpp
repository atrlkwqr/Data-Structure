#include "BST.h"

Nptr Search(Nptr T, const char * key)
{
	if (T == nullptr) {
		return nullptr;
	}
	if (T->Data.Key.compare(key) == 0) {
		return T;

	}
	else if (T->Data.Key.compare(key) < 0) {
		return Search(T->RChild, key);
	}
	else if (T->Data.Key.compare(key) > 0) {
		return Search(T->LChild, key);
	}
	return nullptr;
}

Nptr Insert(Nptr T, const char * key)
{
	if (T == nullptr) {
		Nptr newNode = new node;
		newNode->LChild = newNode->RChild = nullptr;
		newNode->Data.count = 1;
		newNode->Data.Key = key;
		return newNode;
	}
	else if (T->Data.Key.compare(key) > 0) {
		T->LChild = Insert(T->LChild, key);
	}
	else if (T->Data.Key.compare(key) < 0) {
		T->RChild = Insert(T->RChild, key);
	}
	return T;
}

Nptr Delete(Nptr & T, const char * key)
{
	if (T->Data.Key.compare(key) > 0) {
		T->LChild = Delete(T->LChild, key);
	}
	if (T->Data.Key.compare(key) < 0) {
		T->RChild = Delete(T->RChild, key);
	}
	else
	{
		if (T->RChild == nullptr)
		{
			return T->RChild;
		}
		else if (T->LChild == nullptr)
		{
			return T->LChild;
		}

		Nptr minNode = T;
		while (T->LChild) {
			T = T->LChild;
		}
		T->Data.Key = minNode->Data.Key;
		T->Data.count = minNode->Data.count;
		T->RChild = Delete(T->RChild, minNode->Data.Key.c_str());
	}
	return T;
}

Nptr Update(Nptr & T, const char * key)
{
	Search(T, key)->Data.count++;
	return T;
}
