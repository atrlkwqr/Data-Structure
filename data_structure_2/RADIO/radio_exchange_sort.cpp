/*
#include "quick_sort.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
	char arr[100000][50];
	int size;
	memset(arr, 0, sizeof(arr));
	ifstream is("tokens.txt");
	ofstream os("tokens.sorted.txt");
	if (is.fail()) {
		return 0;
	}
	if (os.fail()) {
		return 0;
	}
	for (size = 0; !is.eof(); size++) {
		is >> arr[size];
	}
	is.close();
	RadioExchangeSort(arr, 0, size - 1, 0);

	for (int i = 0; i < size; i++) {
		printf("%s\n", arr[i]);
		os << arr[i] << endl;
	}

	system("pause");
	return 0;
}*/