#include <iostream>
#include <time.h>

#define MAX_SIZE 1000

using namespace std;

int sorted[MAX_SIZE];


void mergesort(int *A, int first, int last) {
	int mid;
	int i, j, k, l;

	if (first < last) {
		mid = (first + last) / 2;
		mergesort(A, first, mid);
		mergesort(A, mid + 1, last);

		i = first;
		j = mid + 1;
		k = first;

		while (i <= mid && j <= last) {
			if (A[i] <= A[j])
				sorted[k++] = A[i++];
			else
				sorted[k++] = A[j++];
		}

		if (i > mid) {
			for (l = j; l <= last; l++)
				sorted[k++] = A[l];
		}
		else {
			for (l = i; l <= mid; l++)
				sorted[k++] = A[l];
		}

		for (l = first; l <= last; l++) {
			A[l] = sorted[l];
		}
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

	mergesort(arr, 0, MAX_SIZE - 1);


	for (int i = 0; i < MAX_SIZE; i++) {
		cout << arr[i] << " ";
	}
	system("pause");

	return 0;
}