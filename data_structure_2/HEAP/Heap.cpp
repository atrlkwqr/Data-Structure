#include "Heap.h"

void down_heap(int *heap, int size, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int minist = i;

	if (left < size && heap[left] < heap[minist])
		minist = left;

	if (right < size && heap[right] < heap[minist])
		minist = right;

	if (minist != i) {
		int tmp = heap[i];
		heap[i] = heap[minist];
		heap[minist] = tmp;
		down_heap(heap, size, minist);
	}
}

void build_heap(int *heap, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		down_heap(heap, size, i);
}

int remove_heap(int * A, int size)
{
	int tmp = A[0];
	A[0] = A[size - 1];
	down_heap(A, size, 0);
	return tmp;
}
