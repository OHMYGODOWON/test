#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	int(*a)[4];
	int arr[5][4];
	int num = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = num++;
		}
	}
	a = arr;
	cout << "arr : " << arr << endl;
	cout << "*(a + i)" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << *(a + i) << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "*(a + i) + j" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << *(a + i) + j << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "*(*(a + i) + j)" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			*(*(a + i) + j) = rand() % 10;
		}
	}
	cout << endl;

	cout << "*(*(a + i) + j)" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "a[i][j]" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "*(p+j) + i" << endl;
	int *p;
	p = *arr;
	num = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
		printf("%d ", *(p + num++));
		}
		printf("\n");
	}

	num = 0;
	cout << endl;
	cout << "0으로 초기화" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			*(*(a + i) + j) = 0;
			printf("%d ", *(p + num++));
		}
		printf("\n");
	}
	system("pause");
}