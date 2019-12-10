#include "Heap.h"
#include <iostream>
#include <time.h>

using namespace std;

#define MAX_SIZE 1000

int main() {
	int m;
	int size = 0;

	cout << "랜덤으로 입력할 M를 입력해주세요. 0부터 M사이에 있는 난수를 생성해 배열합니다." << endl;
	cout << "M의 값 : ";
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