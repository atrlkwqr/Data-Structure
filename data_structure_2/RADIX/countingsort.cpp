#include <iostream>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000

using namespace std;
/*
void countingsort(int *A, int size, int K) {

	int count[MAX_SIZE + 1] = { 0 };
	int result[MAX_SIZE] = { 0 };

	for (int i = 0; i < size; i++)
		count[A[i]]++;

	for (int i = 1; i < K; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
		result[--count[A[i]]] = A[i];


	for (int i = 0; i < MAX_SIZE; i++) {
		A[i] = result[i];
	}
}

int main() {

	int size = 0;
	int arr[MAX_SIZE] = { 0 };


	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = rand() % MAX_SIZE;
		size++;
	}
	countingsort(arr, size, MAX_SIZE + 1);

	for (int i = 0; i < MAX_SIZE; i++) {
		cout << arr[i] << " ";
	}

	system("pause");

	return 0;
}*/