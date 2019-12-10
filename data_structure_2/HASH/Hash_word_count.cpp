#include "Hash.h"
#include <fstream>

void Print(const Hash &h, ofstream &os) {
	for (int i = 0; i < h.size; i++) {
		Nptr ptr = h.table[i];
		while (ptr != nullptr) {
			os << i << " " << ptr->Data.Key << " " << ptr->Data.count << endl;
			ptr = ptr->next;
		}
	}
}

void MakeHash(Hash *h, ifstream &is) {
	Nptr node = nullptr;
	string key;
	while (!is.eof()) {
		is >> key;
		if (h->Search(key.c_str()) == nullptr) {
			h->Insert(key.c_str());
		}
		else {
			h->Update(key.c_str());
		}
	}
}