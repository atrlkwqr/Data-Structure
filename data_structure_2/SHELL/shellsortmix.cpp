//----------------- Linux --------------------

/*
#include <iostream>
#include <math.h>
#include <fstream> 
#include <time.h>
#include "shellsort.h"


using namespace std;


void insertionsort(int *A, int size, int start, int h) {
	int index, review, key;

	for (index = start + h; index <= size; index = index + h) {
		key = A[index];
		for (review = index - h; review >= start && A[review] > key; review = review - h) {
			A[review + h] = A[review];
		}
		A[review + h] = key;
	}
}


void shellsort(int *A, int size, int K) {
	int i = 0, gap = 0;
	if (K == 1) {
		insertionsort(A, size - 1, 0, 1);
	}
	else if (K == 2 || K == 3) {
		while (gap <= size) {
			gap = (int(pow(K, i++)) - 1) / (K - 1);
		}
		while (size) {
			if (gap == 0) gap = 1;
			for (i = 0; i < gap; i++) {
				insertionsort(A, size - 1, i, gap);
			}
			if (gap == 1) break;
			gap = gap / K;
		}
	}
	else {
		cout << "k�� ���� ������ ������ϴ�." << endl;
	}
}

int *fileInNum = new int[1000000];
int *arr = new int[1000000];

int main(int argc, char* argv[]) {

	if (argc != 1) {
		ifstream input(argv[1]);
		int size = 0;
		int k = 0;


		if (input.fail()) {
			cout << "������ ���� �� �����߽��ϴ�." << endl;
			return 1;
		}

		while (!input.eof()) {
			input >> fileInNum[size];
			arr[size] = fileInNum[size];
			size++;
		}

		cout << "������ �������� ���� : " << size << endl;
		cout << "���ݺ� : ";
		cin >> k;


		shellsort(arr, size, k);

		for (int x = 0; x < size; x++) {
			cout << arr[x] << " ";
		}

		system("pause");

		return 0;
	}
	else {

		int size = 0;
		int k = 0;

		int m;
		cout << "�������� �Է��� M�� �Է����ּ���. 0���� M���̿� �ִ� ������ ������ �迭�մϴ�." << endl;
		cout << "M�� �� : ";
		cin >> m;

		int *arr = new int[m];

		srand(time(NULL));
		for (int i = 0; i < m; i++) {
			arr[i] = rand() % m;
			size++;
		}

		cout << "���ݺ� : ";
		cin >> k;


		shellsort(arr, size, k);

		for (int x = 0; x < size; x++) {
			cout << arr[x] << " ";
		}

		system("pause");

		return 0;
	}
}*/