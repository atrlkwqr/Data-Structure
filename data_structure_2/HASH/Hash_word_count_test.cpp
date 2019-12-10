#include "Hash.h"
#include <fstream>

int main() {
	ifstream is;
	ofstream os;
	Hash h;
	Nptr node;
	h.Create(1000);

	string fileName;
	string key;

	cout << "input file name > ";
	cin >> fileName;
	is.open(fileName);
	if (is.is_open()) {
		MakeHash(&h, is);
		os.open(fileName + ".hash");
		Print(h, os);
		os.close();

		while (true)
		{
			cout << "input > ";
			cin >> key;
			node = h.Search(key.c_str());
			if (node != nullptr) {
				cout << node->Data.Key << "," << node->Data.count << endl;
			}
			else {
				cout << "Not found" << endl;
			}
		}
	}
}