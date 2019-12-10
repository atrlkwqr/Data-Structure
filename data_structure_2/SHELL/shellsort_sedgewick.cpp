#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "shellsort_sedgewick.h"

#define MAX_SIZE 1000
using namespace std;


/*void insertionsortsed(int *A, int size, int start, int h) {
	int i, j, key;

	for (i = start + h; i <= size; i = i + h) {
		key = A[i];
		for (j = i - h; j >= start && A[j] > key; j = j - h) {
			A[j + h] = A[j];
		}

		A[j + h] = key;
	}
}

void shellsort(int *A, int size) {

	int i = 1, gap = 0;

	while (gap <= size) {
		gap = pow(4, i) + 3 * pow(2, i - 1) + 1;
		i++;
	}

	i = i - 2;
	gap = pow(4, i) + 3 * pow(2, i - 1) + 1;


	while (size) {
		if (i == 0) gap = 1;
		for (int m = 0; m < gap; m++) {
			insertionsortsed(A, size - 1, m, gap);
		}
		if (i == 0) break;
		i--;
		gap = (int)(pow(4, i) + 3 * pow(2, i - 1) + 1);
	}
}


int main(int argc, char **argv) {

	int k = 0;
	int size = 0;
	int arr1[MAX_SIZE] = { 0 };

	srand(time(NULL));

	size = 0;
	srand(time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {
		arr1[i] = rand() % MAX_SIZE;
		size++;
	}
	shellsort(arr1, size);

	for (int i = 0; i < MAX_SIZE; i++) {
		cout << arr1[i] << " ";
	}

	system("pause");

	return 0;

}*/

