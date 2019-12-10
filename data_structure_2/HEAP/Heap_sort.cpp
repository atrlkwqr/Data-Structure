#include "Heap.h"
#include <iostream>
#include <time.h>

using namespace std;

#define MAX_SIZE 1000

int main() {
	int m;
	int size = 0;

	cout << "�������� �Է��� M�� �Է����ּ���. 0���� M���̿� �ִ� ������ ������ �迭�մϴ�." << endl;
	cout << "M�� �� : ";
	cin >> m;

	int *arr = new int[m];

	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		arr[i] = rand() % m;
		size++;
	}


	build_heap(arr, size);

	for (int i = 0; i < size; i++) {
		cout << remove_heap(arr, size - i) << ' ';
	}
	system("pause");
	return 0;
}