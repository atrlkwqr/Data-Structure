//----------------- Linux --------------------

/*
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include "shellsort.h"

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

int main(int argc, char **argv) {

	int k = 0;
	int size = 0;
	int arr1[1000] = { 0 };
	int arr2[10000] = { 0 };
	int arr3[100000] = { 0 };
	int arr4[1000000] = { 0 };

	srand(time(NULL));

	for (int k = 1; k < 4; k++) {
		size = 0;
		srand(time(NULL));
		for (int i = 0; i < 1000; i++) {
			arr1[i] = rand() % 1000;
			size++;
		}
		double oldtime = getdtime();
		shellsort(arr1, size, k);
		double elapsed_time = getdtime() - oldtime;
		cout << "N=" << size << ", K=" << k << ", ";
		cerr << "elapsed_time: " << elapsed_time << " sec" << endl;
	}

	for (int k = 1; k < 4; k++) {
		size = 0;
		srand(time(NULL));
		for (int i = 0; i < 10000; i++) {
			arr2[i] = rand() % 10000;
			size++;
		}
		double oldtime = getdtime();
		shellsort(arr2, size, k);
		double elapsed_time = getdtime() - oldtime;
		cout << "N=" << size << ", K=" << k << ", ";
		cerr << "elapsed_time: " << elapsed_time << " sec" << endl;
	}

	for (int k = 1; k < 4; k++) {
		size = 0;
		srand(time(NULL));
		for (int i = 0; i < 100000; i++) {
			arr3[i] = rand() % 100000;
			size++;
		}
		double oldtime = getdtime();
		shellsort(arr3, size, k);
		double elapsed_time = getdtime() - oldtime;
		cout << "N=" << size << ", K=" << k << ", ";
		cerr << "elapsed_time: " << elapsed_time << " sec" << endl;
	}

	for (int k = 1; k < 4; k++) {
		size = 0;
		srand(time(NULL));
		for (int i = 0; i < 1000000; i++) {
			arr4[i] = rand() % 1000000;
			size++;
		}
		double oldtime = getdtime();
		shellsort(arr4, size, k);
		double elapsed_time = getdtime() - oldtime;
		cout << "N=" << size << ", K=" << k << ", ";
		cerr << "elapsed_time: " << elapsed_time << " sec" << endl;
	}



	return 1;
}*/
