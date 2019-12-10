#pragma once
#include <iostream>
#include <string>
using namespace std;

typedef struct dataRecord {
	string Key;
	int count;
}dataType;

typedef struct nodeRecord
{
	dataType Data;
	struct nodeRecord* next;
}node;

typedef node *Nptr;

class Hash
{
public:
	int size;
	Nptr *table;

public:
	void Create(int talbesize);
	int Insert(const char *key);
	Nptr Search(const char *key);
	void Update(const char *key);
	void Delete(const char *key);
	void Save(const char *filename);
	void Open(const char *filename);
	void Rehash(int newtablesize);
};

void MakeHash(Hash *h, ifstream &is);
void Print(const Hash &h, ofstream &os);