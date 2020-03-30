#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
int temp[MAX];
int matrix[MAX][MAX]; // 입력받은 matrix
int valid_path[MAX][MAX]; //결과물 출력을 위한 matrix
int visited[MAX] = { 0 };
int N; //N개의 줄

void DFS(int start) {
	visited[start]++;
	if (visited[start] == 2) {
		return;
	}
	for (int i = 0; i < N; i++) {
		if (matrix[start][i] == 1 && (visited[i]==0 || visited[i]==1)) {
			temp[i] = 1;
			DFS(i);
		}
	}
}

int main() {
	cin >> N;
	if (1 <= N && N <= 100) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> matrix[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		DFS(i);

		for (int j = 0; j < N; j++) {
			if (temp[j] != 0) {
				valid_path[i][j] = 1;
			}
		}
		memset(visited, 0, sizeof(visited));
		memset(temp, 0, sizeof(temp));
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << valid_path[i][j]<<" ";
		}
		cout << endl;
	}
}
