/*
#include "quick_sort.h"
#include <string.h>
#include <iostream>

using namespace std;

void swap(char a[][50], int i, int j) {
	char tmp[50];
	strcpy(tmp,  a[i]);
	strcpy(a[i], a[j]);
	strcpy(a[j], tmp);
}

void RadioExchangeSort(char a[][50], int low, int high, int offset)
{
	if (high - low <= 0) return;
	int i = low - 1, j = high;
	int p = low - 1, q = high;
	char v = a[high][offset];
	while (i < j)
	{
		while (a[++i][offset] < v)
			if (i == high)
				break;
		while (v < a[--j][offset])
			if (j == low)
				break;
		if (i > j)
			break;
		swap(a, i, j);
		if (a[i][offset] == v)
			swap(a, ++p, i);
		if (a[j][offset] == v)
			swap(a, j, --q);
	}
	if (p == q)
	{
		if (v != '\0')
			RadioExchangeSort(a, low, high, offset + 1);
		return;
	}
	if (a[i][offset] < v)
		i++;
	for (int k = low; k <= p; k++)
		swap(a, k, j--);
	for (int k = high; k >= q; k--)
		swap(a, k, i++);
	RadioExchangeSort(a, low, j, offset);
	if ((i == high) && (a[i][offset] == v))
		i++;
	if (v != '\0')
		RadioExchangeSort(a, j + 1, i - 1, offset + 1);
	RadioExchangeSort(a, i, high, offset);
}
/*
void RadioExchangeSort(char A[][50], int first, int last, int offset)
{
	printf("RadioExchangeSort(A, %d, %d, %d)\n", first, last, offset);
	if (first < last) {
		char pivot = partition(A, first, last, offset);
		cout << "====================" << endl;
		for (int i = first; i <= last; i++) {
			cout << i << " : " << A[i] << endl;
		}
		int startIdx = first;
		while (A[startIdx][offset] != pivot && A[startIdx][offset] != '\0') startIdx++;
		int endIdx = startIdx;
		while (A[endIdx][offset] == pivot && A[startIdx][offset] != '\0') endIdx++;
		endIdx--;
		if (((startIdx - 1) - first) != (last - first)) {
			RadioExchangeSort(A, first, startIdx - 1, offset);
		}
		if ((endIdx - startIdx) != (last - first)) {
			RadioExchangeSort(A, startIdx, endIdx, offset + 1);
		}
		if ((last - (endIdx + 1)) != (last - first)) {
			RadioExchangeSort(A, endIdx + 1, last, offset);
		}
	}
}*/

