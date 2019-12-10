/*
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

void countingsort(int *A, int size, int K) {

	int *count = new int[K + 1];
	int *result = new int[K];

	for (int i = 0; i < K; i++) {
		count[i] = 0;
		result[i] = 0;
	}
	count[K + 1] = 0;

	for (int i = 0; i < size; i++) {
		count[A[i]]++;
	}

	for (int i = 1; i < K; i++) {
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) {
		result[--count[A[i]]] = A[i];
	}


	for (int i = 0; i < K - 1; i++) {
		A[i] = result[i];
	}
}

int main() {

	int k;
	cout << "랜덤으로 입력할 K를 입력해주세요. 0부터 K사이에 있는 난수를 생성해 배열합니다." << endl;
	cout << "K의 값 : ";
	cin >> k;

	int size = 0;
	int *arr = new int[k];


	srand(time(NULL));
	for (int i = 0; i < k; i++) {
		arr[i] = rand() % k;
		size++;
	}
	countingsort(arr, size, k + 1);

	for (int i = 0; i < k; i++) {
		cout << arr[i] << " ";
	}

	system("pause");

	return 0;
}
*/