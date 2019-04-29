#define _CRT_SECURE_NO_WARNINGS
// matrix
/*
요구사항
1. 2차원 배열 생성
2. 0으로 초기화
3. 난수발생시켜서 벌레의 시작점 선택
4. 0~3 난수발생시켜 상하좌우 벌레가 이동할 방향 선택
5. 벌레가 지나간 곳은 1증가
6. 배열의 모든 곳에 0이 없어지면 종료
7. 동일한 방식으로 2개의 배열에 대해 적용
8. 각 배열의 성분의 최대값이 작은 배열이 승리

필요한 함수
1. 초기화 함수
2. 벌레이동함수
3. 성분 최대값 찾는 함수
4. 배열 출력 함수
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
#define ROWS 10
#define COLS 10
enum { UP, RIGHT, DOWN, LEFT };

//초기화함수
void initializeMatrix(int(*a)[COLS], int rows);

// 벌레이동함수
void randomWalk(int(*a)[COLS], int rows);

// 성분 최대값찾는 함수
int findMAX(int(*a)[COLS], int rows);

//float getAverage(int(*a)[COLS][ROWS], int rows);
// 배열 출력함수
void showMatrix(int a[ROWS][COLS]);

// 벌레이동이 끝났는지 확인하는 함수
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
		cout << "\nSelect command  [1:행렬 초기화]  [2:random walk]  [3:find MAX]  [4:Display]  [5:Quit] => ";
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
				cout << "A배열의 최대값 : " << max_A << " B배열의 최대값 : " << max_B << "이므로 B의 승리입니다." << endl;
			else if (max_A < max_B)
				cout << "A배열의 최대값 : " << max_A << " B배열의 최대값 : " << max_B << "이므로 A의 승리입니다." << endl;
			else
				cout << "A배열과 B배열 모두 최대값이 " << max_A << "이므로 무승부입니다." << endl;
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
//모든 원소를 0으로 초기화
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
	//모든 cell이 0 이상일 때 종료
	//나방이 임의 장소 a[i][j][k] 선택은 I, j, k는 난수를 만들어 결정
	// 배열 a[][][] 방식 사용 금지, 대신에 *만 사용
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
	//최대값을 return
	// 배열 a[][][] 방식 사용 금지, 대신에 *만 사용
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
	// high[0]에 대하여 2차원 배열 값 출력, high[1]에 대하여 2차원 배열 값 출력 등으로 처리
	// 배열 a[][][] 방식 사용 금지, 대신에 *만 사용

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("[%5d] ", arr[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}
