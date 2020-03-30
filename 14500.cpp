#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 501

int N, M; // N:세로, M:가로
int matrix[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 }; 

int visited[MAX][MAX] = { 0 };
int sum = 0;
int total_max = 0; //실제 출력 값

void DFS(int current_y, int current_x, int count) {

	visited[current_y][current_x] = 1; // visited 체크
	count++;
	sum += matrix[current_y][current_x];

	if (count == 4) {
		total_max = max(sum, total_max);
		sum -= matrix[current_y][current_x];
		visited[current_y][current_x] = 0;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int next_x = current_x + dx[i];
		int next_y = current_y + dy[i];

		if (0 <= next_x && next_x < M && 0 <= next_y && next_y < N && visited[next_y][next_x] == 0) {

			DFS(next_y, next_x, count);

		}
	}
	sum -= matrix[current_y][current_x];
	visited[current_y][current_x] = 0;
}

int main() {
	cin >> N >> M;

	if (4 <= N && N <= 500 && 4 <= M && M <= 500) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> matrix[i][j];
			}
		}
	} //입력 값

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			DFS(i, j, 0);

			//ㅏ
			if (0 <= j + 1 && j + 1 < M && 0 <= i + 1 && i + 1 < N && 0 <= i + 2 && i + 2 < N) {
				sum = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i + 1][j + 1];
				total_max = max(total_max, sum);
			}

			//ㅜ
			if (0 <= j + 2 && j + 2 < M && 0 <= j + 1 && j + 1 < M && 0 <= i + 1 && i + 1 < N) {
				sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 1];
				total_max = max(total_max, sum);
			}

			//ㅗ
			if (0 <= i + 1 && i + 1 < N && 0 <= j + 2 && j + 2 < M) {
				sum = matrix[i][j + 1] + matrix[i + 1][j] + matrix[i + 1][j + 1] + matrix[i + 1][j + 2];
				total_max = max(total_max, sum);
			}

			//ㅓ
			if (0 <= i + 2 && i + 2 < N && 0 <= j + 1 && j + 1 < M) {
				sum = matrix[i][j + 1] + matrix[i + 1][j + 1] + matrix[i + 1][j] + matrix[i + 2][j + 1];
				total_max = max(total_max, sum);
			}

			sum = 0;
		}
	}

	cout << total_max << endl;

}