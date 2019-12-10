/*
#include "quick_sort.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

char arr[100000][50];

double getdtime()
{
	struct timeval tv = { 0 };
	double dtime;
	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}

int main() {
	int size;
	memset(arr, 0, sizeof(arr));
	ifstream is("tokens.txt");
	ofstream os("tokens.sorted.txt");
	if (is.fail()) {
		return 0;
	}
	if (os.fail()) {
		return 0;
	}
	for (size = 0; !is.eof(); size++) {
		is >> arr[size];
	}
	is.close();

	double oldtime = getdtime();

	RadioExchangeSort(arr, 0, size - 1, 0);

	double elapsed_time = getdtime() - oldtime;

	for (int i = 0; i < size; i++) {
		os << arr[i] << endl;
	}

	cerr << "elapsed_time: " << elapsed_time << " sec" << endl;
	return 1;
}*/