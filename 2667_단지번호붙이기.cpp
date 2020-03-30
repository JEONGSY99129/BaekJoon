#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;
#define _CRT_SERCURE_NO_WARNINGS
#define MAX 26
int matrix[MAX][MAX]; //최대 사이즈 지정
int visited[MAX][MAX] = { 0 };
int move_x[4] = { 0, 0, 1, -1 }; 
int move_y[4] = { 1, -1, 0, 0 }; 
int numOfHouses[500] = { 0 }; //각 단지의 가구 수
int apartment = 0; //단지 수
int N; //배열 사이즈

void DFS(int current_x, int current_y) {
	visited[current_x][current_y] = 1; //visited 체크

	for (int i = 0; i < 4; i++) {
		int next_x = current_x + move_x[i];
		int next_y = current_y + move_y[i];

		if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N && visited[next_x][next_y]!=1) { //움직인 범위가 유효한 범위라면 + 알파 조건이 필요할듯,,?
			if (matrix[next_x][next_y] == 1) {
				numOfHouses[apartment-1]++; //집 가구 수
				DFS(next_x, next_y);
			}
			else //0이면 체크만 하고 넘어감.
			{
				visited[next_x][next_y] = 1;
			}
		}
	}
		
}


int main() {
	cin >> N;
	
	if (5 <= N && N <= 25) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf_s("%1d", &matrix[i][j]);
			}
		}
	}


	for (int i = 0; i < N; i++) { //세로
		for (int j = 0; j < N; j++) { //가로
			if (visited[i][j] != 1 && matrix[i][j]==1) {
				apartment++;
				numOfHouses[apartment-1]++;
				DFS(i, j);
			}
		}
	}
	cout << apartment << endl;

	for (int i = 0; i < apartment - 1; i++) {
		for (int j = i + 1; j < apartment; j++) {
			if (numOfHouses[j] < numOfHouses[i]) {
				int tmp = numOfHouses[j];
				numOfHouses[j] = numOfHouses[i];
				numOfHouses[i] = tmp;
			}
		}
	}
	for (int i = 0; i < apartment; i++) {
		cout << numOfHouses[i] << endl;
	}
}
