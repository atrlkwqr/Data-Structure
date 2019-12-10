
#include "quick_sort.h"
#include <iostream>
#include <cstring>
#include <fstream>

#define TOKENS 100000
#define LENGTH 20
using namespace std;

char arr[TOKENS][50];
int brr[TOKENS] = { 0 };

void countingsorttoken(int *A, int size, int K) {

	int count[TOKENS + 1] = { 0 };
	int cc = 1;
	int start = 0;
	for (int i = 0; i < size; i++) {
		count[A[i] + start]++;
		start = A[i] + start;
	}

	for (int i = 0; i < K; i++) {
		if (count[i] == 1) {
			cc++;
		}
		count[i] = cc;
	}

	for (int i = 0; i < TOKENS; i++) {
		brr[i] = count[i];
	}
}


int main() {
	int size;
	memset(arr, 0, sizeof(arr));
	double length[46] = { 0 };
	double newlength[LENGTH] = { 0 };
	int new2length[LENGTH] = { 0 };
	ofstream is("tokens.txt");
	ofstream os("tokens.sorted.txt");
	ifstream word_length("word_length_stat.txt");

	if (!is.is_open()) {
		return 0;
	}
	if (!os.is_open()) {
		return 0;
	}
	if (!word_length.is_open()) {
		cout << "파일을 여는 데 실패했습니다." << endl;
		return 1;
	}

	int distrib = 1;
	int nk = 0;

	while (!word_length.eof()) {
		word_length >> length[distrib];
		distrib++;
	}

	word_length.close();

	for (int k = 1; k < distrib; k++) {
		if ((k % 2) == 0) {
			newlength[nk] = length[k];
			nk++;
		}
	}

	for (int k = 0; k < nk - 1; k++) {
		newlength[k] = newlength[k] * 1000;
	}

	for (int k = 0; k < nk - 1; k++) {
		new2length[k] = (int)newlength[k];
	}

	countingsorttoken(new2length, LENGTH, TOKENS + 1);

	int x;
	cout << "몇 개의 단어 생성을 하시겠습니까? ";
	cin >> x;
	srand(time(NULL));
	for (int m = 0; m < x; m++) {
		int i = (((long)rand() << 15) | rand()) % TOKENS;

		for (int j = 0; j < brr[i]; j++) {
			char i = (char)(rand() % 26 + 97);
			cout << i;
			is << i;
		}
		cout << endl;
		is << endl;
	}

	is.close();

	ifstream iso("tokens.txt");

	if (!iso.is_open()) {
		return 0;
	}

	for (size = 0; !iso.eof(); size++) {
		iso >> arr[size];
	}
	iso.close();
	RadioExchangeSort(arr, 0, size - 1, 0);

	for (int i = 0; i < size; i++) {
		printf("%s\n", arr[i]);
		os << arr[i] << endl;
	}

	return 0;
}