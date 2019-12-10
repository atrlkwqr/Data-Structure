#include <iostream>
#include <time.h>
#include <math.h>
#include "count_sort.h"
#include <cstring>
#include <fstream>
using namespace std;

char arr[100000][50];

void RadioSort(char arr[][50], int size, int offset) {
	countingsort(arr, size, offset, 256);
	for (int i = 0; i < size - 1; i) {
		int endIdx = i;
		while (endIdx < (size - 1) && arr[endIdx][offset] != '\0' && arr[endIdx][offset] == arr[endIdx + 1][offset]) {
			endIdx++;
		}
		if (i != endIdx) {
			RadioSort(&arr[i], endIdx - i + 1, offset + 1);
		}
		i += (endIdx - i) + 1;
	}
}

int main() {
	int size;
	memset(arr, 0, sizeof(arr));
	ifstream is("tokens.txt");
	ofstream os("tokens.sorted.txt");
	if (!is.is_open()) {
		return 0;
	}
	if (!os.is_open()) {
		return 0;
	}
	for (size = 0; !is.eof(); size++) {
		is >> arr[size];
	}
	is.close();
	RadioSort(arr, size, 0);

	for (int i = 0; i < size; i++) {
		printf("%s\n", arr[i]);
		os << arr[i] << endl;
	}

	return 0;
}