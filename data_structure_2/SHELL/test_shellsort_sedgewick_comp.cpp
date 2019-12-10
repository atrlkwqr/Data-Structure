//----------------- Linux --------------------

/*
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include "shellsort.h"
#include "shellsort_sedgewick.h"

using namespace std;

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

void shellsortsed(int *A, int size) {

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
	cout << "N=" << size << ", Pratt, K=3, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000; i++) {
		arr1[i] = rand() % 1000;
		size++;
	}
	oldtime = getdtime();
	shellsortsed(arr1, size);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000; i++) {
		arr2[i] = rand() % 10000;
		size++;
	}
	oldtime = getdtime();
	shellsort(arr2, size, 3);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Pratt, K=3, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 10000; i++) {
		arr2[i] = rand() % 10000;
		size++;
	}
	oldtime = getdtime();
	shellsortsed(arr2, size);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 100000; i++) {
		arr3[i] = rand() % 100000;
		size++;
	}
	oldtime = getdtime();
	shellsort(arr3, size, 3);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Pratt, K=3, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 100000; i++) {
		arr3[i] = rand() % 100000;
		size++;
	}
	oldtime = getdtime();
	shellsortsed(arr3, size);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000000; i++) {
		arr4[i] = rand() % 1000000;
		size++;
	}
	oldtime = getdtime();
	shellsort(arr4, size, 3);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Pratt, K=3, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	size = 0;

	for (int i = 0; i < 1000000; i++) {
		arr4[i] = rand() % 1000000;
		size++;
	}
	oldtime = getdtime();
	shellsortsed(arr4, size);
	elapsed_time = getdtime() - oldtime;
	cout << "N=" << size << ", Sedgewick, ";
	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;

	return 1;
}*/
