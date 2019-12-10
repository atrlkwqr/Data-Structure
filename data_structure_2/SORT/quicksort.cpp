#include <iostream>
#include <time.h>

#define MAX_SIZE 1000

using namespace std;


void quicksort(int *A, int first, int last) {

	if (first < last) {
		int q;

		int pivot, temp;
		int low, high;

		low = first;
		high = last + 1;
		pivot = A[first];

		while (low < high) {

			low++;
			while (low <= last && A[low] < pivot) {
				low++;
			}

			high--;
			while (high >= first && A[high] > pivot) {
				high--;
			}

			if (low < high) {
				temp = A[low];
				A[low] = A[high];
				A[high] = temp;
			}
		}

		temp = A[first];
		A[first] = A[high];
		A[high] = temp;

		q = high;

		quicksort(A, first, q - 1);
		quicksort(A, q + 1, last);
	}

}

/*
int main() {

	int size = 0;
	int arr[MAX_SIZE] = { 0 };


	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {
		arr[i] = rand() % MAX_SIZE;
		size++;
	}

	quicksort(arr, 0, MAX_SIZE - 1);


	for (int i = 0; i < MAX_SIZE; i++) {
		cout << arr[i] << " ";
	}
	system("pause");

	return 0;
}
*/
