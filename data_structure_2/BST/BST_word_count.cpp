#include "BST.h"
#include <fstream>


void PrintInorder(const Nptr ptr, ofstream &os) {
	if (ptr == nullptr) {
		return;
	}
	PrintInorder(ptr->LChild, os);
	os << ptr->Data.Key << " " << ptr->Data.count << endl;
	PrintInorder(ptr->RChild, os);
}

Nptr MakeTree(ifstream &is) {
	Nptr root = nullptr;
	string key;
	while (!is.eof()) {
		is >> key;
		if (Search(root, key.c_str()) == nullptr) {
			root = Insert(root, key.c_str());
		}
		else {
			Update(root, key.c_str());
		}
	}
	return root;
}