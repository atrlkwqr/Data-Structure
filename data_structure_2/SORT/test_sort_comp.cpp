//----------------- Linux --------------------

/*
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>

using namespace std;

int sorted[10000000];


double getdtime()
{
	struct timeval tv = { 0 };
	double dtime;
	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}

void insertionsort(int *A, int size, int start, int h) {
	int i, j, key;

	for (i = start + h; i <= size; i = i + h) {
		key = A[i];
		for (j = i - h; j >= start && A[j] > key; j = j - h) {
			A[j + h] = A[j];
		}

		A[j + h] = key;
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
		cout << "k가 조건 범위를 벗어났습니다." << endl;
	}
}

void insertionsortsed(int *A, int size, int start, int h) {
	int i, j, key;

	for (i = start + h; i <= size; i = i + h) {
		key = A[i];
		for (j = i - h; j >= start && A[j] > key; j = j - h) {
			A[j + h] = A[j];
		}

		A[j + h] = key;
	}
}

void shellsort_sedgewick(int *A, int size) {

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

int arr5[10000000] = { 0 };

int main(int argc, char **argv) {

	int k = 0;
	int size = 0;
	int arr1[1000] = { 0 };
	int arr2[10000] = { 0 };
	int arr3[100000] = { 0 };
	int arr4[1000000] = { 0 };

	srand(time(NULL));

	size = 0;

	for (int i = 0; i < 1000; i++) {
		arr1[i] = rand() % 1000;
		size++;
	}
	double oldtime = getdtime();
	shellsort(arr1, size, 3);
	double elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Pratt, K=3, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000; i++) {
		arr1[i] = rand() % 1000;
		size++;
	}
	oldtime = getdtime();
	shellsort_sedgewick(arr1, size);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000; i++) {
		arr1[i] = rand() % 1000;
		size++;
	}
	oldtime = getdtime();
	mergesort(arr1, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000; i++) {
		arr1[i] = rand() % 1000;
		size++;
	}
	oldtime = getdtime();
	quicksort(arr1, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000; i++) {
		arr2[i] = rand() % 10000;
		size++;
	}
	oldtime = getdtime();
	shellsort(arr2, size, 3);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Pratt, K=3, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000; i++) {
		arr2[i] = rand() % 10000;
		size++;
	}
	oldtime = getdtime();
	shellsort_sedgewick(arr2, size);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000; i++) {
		arr2[i] = rand() % 1000;
		size++;
	}
	oldtime = getdtime();
	mergesort(arr2, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000; i++) {
		arr2[i] = rand() % 10000;
		size++;
	}
	oldtime = getdtime();
	quicksort(arr2, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 100000; i++) {
		arr3[i] = rand() % 100000;
		size++;
	}
	oldtime = getdtime();
	shellsort(arr3, size, 3);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Pratt, K=3, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 100000; i++) {
		arr3[i] = rand() % 100000;
		size++;
	}
	oldtime = getdtime();
	shellsort_sedgewick(arr3, size);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 100000; i++) {
		arr3[i] = rand() % 100000;
		size++;
	}
	oldtime = getdtime();
	mergesort(arr3, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 100000; i++) {
		arr3[i] = rand() % 100000;
		size++;
	}
	oldtime = getdtime();
	quicksort(arr3, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000000; i++) {
		arr4[i] = rand() % 1000000;
		size++;
	}
	oldtime = getdtime();
	shellsort(arr4, size, 3);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Pratt, K=3, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000000; i++) {
		arr4[i] = rand() % 1000000;
		size++;
	}
	oldtime = getdtime();
	shellsort_sedgewick(arr4, size);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000000; i++) {
		arr4[i] = rand() % 1000000;
		size++;
	}
	oldtime = getdtime();
	mergesort(arr4, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000000; i++) {
		arr4[i] = rand() % 1000000;
		size++;
	}
	oldtime = getdtime();
	quicksort(arr4, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000000; i++) {
		arr5[i] = rand() % 10000000;
		size++;
	}
	oldtime = getdtime();
	shellsort(arr5, size, 3);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Pratt, K=3, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000000; i++) {
		arr5[i] = rand() % 10000000;
		size++;
	}
	oldtime = getdtime();
	shellsort_sedgewick(arr5, size);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000000; i++) {
		arr5[i] = rand() % 10000000;
		size++;
	}
	oldtime = getdtime();
	mergesort(arr5, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000000; i++) {
		arr5[i] = rand() % 10000000;
		size++;
	}
	oldtime = getdtime();
	quicksort(arr5, 0, size - 1);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Shellsort-Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	return 1;
}
*/