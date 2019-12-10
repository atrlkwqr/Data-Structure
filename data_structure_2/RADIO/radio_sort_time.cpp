/*
#include <iostream>
#include <time.h>
#include <math.h>
#include "count_sort.h"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

double getdtime()
{
	struct timeval tv = { 0 };
	double dtime;
	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}

char arr[100000][50];

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

int main() {
	int size;
	memset(arr, 0, sizeof(arr));
	ifstream is("tokens.txt");
	ofstream os("tokens.sorted.txt");
	if (!is.is_open()) {
		return 0;
	}
	if (!os.is_open()) {
		return 0;
	}
	for (size = 0; !is.eof(); size++) {
		is >> arr[size];
	}
	is.close();

	double oldtime = getdtime();
	RadioSort(arr, size, 0);

	double elapsed_time = getdtime() - oldtime;
	for (int i = 0; i < size; i++) {
		os << arr[i] << endl;
	}

	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;
	return 1;

	return 0;
}
*/