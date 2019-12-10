#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef struct dataRecord {
	string Key;
	int count;
}dataType;

typedef struct treeRecord
{
	dataType Data;
	struct treeRecord *LChild;
	struct treeRecord *RChild;
}node;

typedef node* Nptr;

Nptr Search(Nptr T, const char *key);
Nptr Insert(Nptr T, const char *key);
Nptr Delete(Nptr &T, const char *key);
Nptr Update(Nptr &T, const char *key);

void PrintInorder(const Nptr ptr, ofstream &os);
Nptr MakeTree(ifstream &is);