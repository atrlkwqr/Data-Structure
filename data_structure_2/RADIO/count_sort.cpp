#include "count_sort.h"
#include <string.h>
#include <iostream>
using namespace std;
#define MAX_SIZE 100000

void countingsort(char A[][50], int size, int offset, int K) {

	int count[MAX_SIZE + 1] = { 0 };
	char result[MAX_SIZE][50] = { 0 };

	for (int i = 0; i < size; i++)
		count[A[i][offset]]++;

	for (int i = 1; i < K; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
		strcpy(result[--count[A[i][offset]]],  A[i]);


	for (int i = 0; i < size; i++) {
		strcpy(A[i], result[i]);
	}
}