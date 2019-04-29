#define _CRT_SECURE_NO_WARNINGS
// matrix
/*
�䱸����
1. 2���� �迭 ����
2. 0���� �ʱ�ȭ
3. �����߻����Ѽ� ������ ������ ����
4. 0~3 �����߻����� �����¿� ������ �̵��� ���� ����
5. ������ ������ ���� 1����
6. �迭�� ��� ���� 0�� �������� ����
7. ������ ������� 2���� �迭�� ���� ����
8. �� �迭�� ������ �ִ밪�� ���� �迭�� �¸�

�ʿ��� �Լ�
1. �ʱ�ȭ �Լ�
2. �����̵��Լ�
3. ���� �ִ밪 ã�� �Լ�
4. �迭 ��� �Լ�
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
#define ROWS 10
#define COLS 10
enum { UP, RIGHT, DOWN, LEFT };

//�ʱ�ȭ�Լ�
void initializeMatrix(int(*a)[COLS], int rows);

// �����̵��Լ�
void randomWalk(int(*a)[COLS], int rows);

// ���� �ִ밪ã�� �Լ�
int findMAX(int(*a)[COLS], int rows);

//float getAverage(int(*a)[COLS][ROWS], int rows);
// �迭 ����Լ�
void showMatrix(int a[ROWS][COLS]);

// �����̵��� �������� Ȯ���ϴ� �Լ�
bool finish(int(*arr)[COLS], int rows);

int main(void)
{

	int A[ROWS][COLS];
	int B[ROWS][COLS];
	int select;
	int max_A, max_B;
	while (1)
	{
		srand((unsigned int)time(NULL));
		cout << "\nSelect command  [1:��� �ʱ�ȭ]  [2:random walk]  [3:find MAX]  [4:Display]  [5:Quit] => ";
		scanf("%d", &select);
		switch (select) {
		case 1:
			initializeMatrix(A, ROWS);
			initializeMatrix(B, ROWS);
			break;

		case 2:
			randomWalk(A, ROWS);
			randomWalk(B, ROWS);
			break;

		case 3:
			max_A = findMAX(A, ROWS);
			max_B = findMAX(B, ROWS);
			if (max_A > max_B)
				cout << "A�迭�� �ִ밪 : " << max_A << " B�迭�� �ִ밪 : " << max_B << "�̹Ƿ� B�� �¸��Դϴ�." << endl;
			else if (max_A < max_B)
				cout << "A�迭�� �ִ밪 : " << max_A << " B�迭�� �ִ밪 : " << max_B << "�̹Ƿ� A�� �¸��Դϴ�." << endl;
			else
				cout << "A�迭�� B�迭 ��� �ִ밪�� " << max_A << "�̹Ƿ� ���º��Դϴ�." << endl;
			break;
		case 4:
			showMatrix(A);
			showMatrix(B);
			break;
		default:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}
void initializeMatrix(int(*arr)[COLS], int rows)
//��� ���Ҹ� 0���� �ʱ�ȭ
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			arr[i][j] = 0;
		}
	}
}
bool finish(int(*arr)[COLS], int rows) {
	bool finish = false;
	int count = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			if (arr[i][j] == 0) {
				break;
			}
			else {
				count++;
			}
		}
	}
	if (count == rows * COLS) {
		finish = true;
	}
	return finish;
}

void randomWalk(int(*arr)[COLS], int rows)
{
	//��� cell�� 0 �̻��� �� ����
	//������ ���� ��� a[i][j][k] ������ I, j, k�� ������ ����� ����
	// �迭 a[][][] ��� ��� ����, ��ſ� *�� ���
	int x = rand() % ROWS, y = rand() % COLS;
	arr[x][y] += 1;

	while (finish(arr, rows) == false) {

		int direction = rand() % 4;
		switch (direction) {
		case UP:
			if (x == 0)
				break;
			x -= 1;
			break;
		case RIGHT:
			if (y = COLS - 1)
				break;
			y += 1;
			break;
		case DOWN:
			if (x == rows - 1)
				break;
			x += 1;
			break;
		case LEFT:
			if (y == 0)
				break;
			y -= 1;
			break;
		default:
			break;
		}

		arr[x][y] += 1;

	}
}

int findMAX(int(*arr)[COLS], int rows)
{
	//�ִ밪�� return
	// �迭 a[][][] ��� ��� ����, ��ſ� *�� ���
	int max = arr[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	return max;

}

void showMatrix(int arr[ROWS][COLS])
{
	// high[0]�� ���Ͽ� 2���� �迭 �� ���, high[1]�� ���Ͽ� 2���� �迭 �� ��� ������ ó��
	// �迭 a[][][] ��� ��� ����, ��ſ� *�� ���

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("[%5d] ", arr[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
