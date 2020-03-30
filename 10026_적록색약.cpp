#include<iostream>
#include<cstring>
using namespace std;
#define MAX 101
int N;
char matrix[MAX][MAX];
int visited[MAX][MAX] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int normal = 0;
int patient = 0;

void DFS(int current_y, int current_x) { //Á¤»óÀÎ DFS
	visited[current_y][current_x] = 1;

	for (int i = 0; i < 4; i++) {
		int ny = current_y + dy[i];
		int nx = current_x + dx[i];
		if ((matrix[current_y][current_x] == matrix[ny][nx]) && !visited[ny][nx]) {
			DFS(ny, nx);
		}
	}
}

void Change_Matrix() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 'G')
				matrix[i][j] = 'R';
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
	} //ÀÔ·Â

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS(i, j);
				++normal;
			}
		}
	}

	Change_Matrix();

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				DFS(i, j);
				++patient;
			}
		}
	}
	cout << normal << " " << patient << endl;

}

