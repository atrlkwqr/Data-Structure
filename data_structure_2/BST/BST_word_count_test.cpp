#include "BST.h"
#include <fstream>



int main() {
	ifstream is;
	ofstream os;
	Nptr root = nullptr, result = nullptr;

	string fileName;
	string key;

	cout << "> BST_word_count_test ";
	cin >> fileName;
	is.open(fileName);
	if (is.is_open()) {
		root = MakeTree(is);
		is.close();
		os.open(fileName + ".wordcount");
		PrintInorder(root, os);
		os.close();

		cout << "Loading is complete" << endl;
		while (true) {
			cout << "input> ";
			cin >> key;
			result = Search(root, key.c_str());
			if (result == nullptr) {
				cout << "Not found" << endl;
			}
			else {
				cout << result->Data.count << endl;
			}
		}
	}
	else {
		cerr << fileName<< " not found" << endl;
	}

	/*
	is.open("The-Road-Not-Taken.tokens.txt");
	if (is.is_open()) {
		head = MakeTree(is);
		is.close();
		os.open("The-Road-Not-Taken.wordcount");
		PrintInorder(head, os);
		os.close();
	}
	else {
		cerr << "The-Road-Not-Taken.tokens.txt not found" << endl;
	}

	is.open("Dickens_Oliver_1839.tokens.txt");
	if (is.is_open()) {
		head = MakeTree(is);
		is.close();
		os.open("Dickens_Oliver_1839.wordcount", ios::trunc);
		PrintInorder(head, os);
		os.close();
	}
	else {
		cerr << "Dickens_Oliver_1839.tokens.txt not found" << endl;
	}*/



	return 0;
}