//----------------- Linux --------------------

/*
#include "Hash.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>



#define TOKENS 100000
#define LENGTH 20

using namespace std;

int arr[TOKENS] = { 0 };

double getdtime()
{
	struct timeval tv = { 0 };
	double dtime;
	gettimeofday(&tv, NULL);
	dtime = tv.tv_sec + (tv.tv_usec / 1000000.0);
	return dtime;
}


void countingsorttoken(int *A, int size, int K) {

	int count[TOKENS + 1] = { 0 };
	int cc = 1;
	int start = 0;
	for (int i = 0; i < size; i++) {
		count[A[i] + start]++;
		start = A[i] + start;
	}

	for (int i = 0; i < K; i++) {
		if (count[i] == 1) {
			cc++;
		}
		count[i] = cc;
	}

	for (int i = 0; i < TOKENS; i++) {
		arr[i] = count[i];
	}
}

int main() {
	ifstream is;
	ofstream os;
	Hash h;
	Nptr node;
	ofstream tokens("tokens.txt");
	ifstream word_length("word_length_stat.txt");
	h.Create(1000);

	string fileName;
	string key;

	double length[46] = { 0 };
	double newlength[LENGTH] = { 0 };
	int new2length[LENGTH] = { 0 };

	if (tokens.fail()) {
		cout << "파일을 여는 데 실패했습니다." << endl;
		return 1;
	}
	if (word_length.fail()) {
		cout << "파일을 여는 데 실패했습니다." << endl;
		return 1;
	}

	int distrib = 1;
	int nk = 0;

	while (!word_length.eof()) {
		word_length >> length[distrib];
		distrib++;
	}

	word_length.close();

	for (int k = 1; k < distrib; k++) {
		if ((k % 2) == 0) {
			newlength[nk] = length[k];
			nk++;
		}
	}

	for (int k = 0; k < nk - 1; k++) {
		newlength[k] = newlength[k] * 1000;
	}

	for (int k = 0; k < nk - 1; k++) {
		new2length[k] = (int)newlength[k];
	}

	countingsorttoken(new2length, LENGTH, TOKENS + 1);


	srand(time(NULL));
	for (int m = 0; m < TOKENS; m++) {
		int i = (((long)rand() << 15) | rand()) % TOKENS;

		for (int j = 0; j < arr[i]; j++) {
			char i = (char)(rand() % 26 + 97);
			tokens << i;
		}
		tokens << endl;
	}

	tokens.close();


	cout << "input file name > ";
	cin >> fileName;
	is.open(fileName);
	if (is.is_open()) {
		MakeHash(&h, is);


		ifstream tokensi("tokens.txt");
		int num = 0;
		string keyvalue;
		double oldtime = getdtime();
		while (num < TOKENS)
		{
			int j = (((long)rand() << 15) | rand()) % TOKENS;

			for (int n = 0; n < j; n++) {
				tokensi >> keyvalue;
			}

			node = h.Search(keyvalue.c_str());

			if (node != nullptr) {
				cout << node->Data.Key << "," << node->Data.count << endl;
			}
			else {
			}
			num++;
		}
		double elapsed_time = getdtime() - oldtime;
		cerr << "elapsed_time: " << elapsed_time << " sec" << endl;
		tokensi.close();
		return 1;
	}
	return 0;
}*/