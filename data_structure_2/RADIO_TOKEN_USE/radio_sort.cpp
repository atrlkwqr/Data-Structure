#include <iostream>
#include <time.h>
#include <math.h>
#include "count_sort.h"
#include <cstring>
#include <fstream>
using namespace std;

#define TOKENS 100000
#define LENGTH 20
char arr[100000][50];
int brr[TOKENS] = { 0 };

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
		cout << "������ ���� �� �����߽��ϴ�." << endl;
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
	cout << "�� ���� �ܾ� ������ �Ͻðڽ��ϱ�? ";
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
	RadioSort(arr, size, 0);

	for (int i = 0; i < size; i++) {
		printf("%s\n", arr[i]);
		os << arr[i] << endl;
	}

	return 0;
}