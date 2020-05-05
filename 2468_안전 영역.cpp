#include<iostream>
#include<algorithm>
#include<cstring> //vs에서는 필요ㄴㄴ
using namespace std;
#define MAX 100
int N; //배열 사이즈

int village[MAX][MAX];
int visited[MAX][MAX] = { 0 };
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };

void DFS(int current_x, int current_y, int limit) {
	visited[current_y][current_x] = 1;

	for (int i = 0; i < 4; i++) {
		int next_x = current_x + move_x[i];
		int next_y = current_y + move_y[i];

		if ((0 <= next_x) && (next_x < N) && (0 <= next_y) && (next_y < N) && (visited[next_y][next_x] != 1)) { //움직인 범위가 유효한 범위라면
			if (village[next_y][next_x] > limit) {
				DFS(next_x, next_y, limit);
			}
			else //0이면 체크만 하고 넘어감.
			{
				visited[next_y][next_x] = 1;
			}
		}

	}
}


int main() {
	int highest = 0;
	int safety_zone;
	int maximum = 0;
	cin >> N;

	if (2 <= N && N <= 10) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> village[i][j];
				highest = max(highest, village[i][j]);
			}
		}
	}

	for (int i = 0; i <= highest; i++) {
		memset(visited, 0, sizeof(visited));
		safety_zone = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if ((visited[y][x] == 0) && (village[y][x] > i)) {
					safety_zone++;
					DFS(x, y, i);
				}
			}
		}
		maximum = max(maximum, safety_zone);
	}
	cout << maximum << endl;
}
