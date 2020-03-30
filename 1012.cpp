#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX 25
#define Triple_Max 30000
int field[Triple_Max][MAX][MAX] = { 0 };
int visited[MAX][MAX][MAX] = { 0 };
int earthworm = 0; //배추 집단 개수
int move_x[4] = { 0, 0, 1, -1 };
int move_y[4] = { 1, -1, 0, 0 };
int M[Triple_Max] = { 0 };
int N[Triple_Max] = { 0 }; //M:배추 밭 가로 길이, N:배추 밭 세로 길이 //얘도 고쳐야함!!!!!!!!!!!!!!!!!!!!!!!1

void DFS(int current_t, int current_x, int current_y) {
	visited[current_t][current_x][current_y] = 1; //visited 체크

	for (int i = 0; i < 4; i++) {
		int next_x = current_x + move_x[i];
		int next_y = current_y + move_y[i];

		if (0 <= next_x && next_x < N[current_t] && 0 <= next_y && next_y < M[current_t] && visited[current_t][next_x][next_y] != 1) { //움직인 범위가 유효한 범위라면 + 알파 조건이 필요할듯,,?
			if (field[current_t][next_x][next_y] == 1) {
				DFS(current_t, next_x, next_y);
			}
			else //0이면 체크만 하고 넘어감.
			{
				visited[current_t][next_x][next_y] = 1;
			}
		}
	}
}

int main() {
	int T; //T:테스트케이스
	cin >> T;
	int K; // K:배추 개수
	int X, Y; //배추 위치 좌표

	for (int t = 0; t < T; t++) {
		cin >> M[t] >> N[t] >> K;
		if (1 <= M[t] && M[t] <= 50 && 1 <= N[t] && N[t] <= 50 && 1 <= K && K <= 2500) {
			for (int i = 0; i < K; i++) {
				cin >> X >> Y;
				if (0 <= X && X <= M[t] - 1 && 0 <= Y && Y <= N[t] - 1) {
					field[t][Y][X] = 1; //배열에서는 x, y바꿔줘야 할 듯
				}

			}
		}
	}

	for (int t = 0; t < T; t++) { //테스트 케이스 개수
		earthworm = 0;
		for (int i = 0; i < N[t]; i++) { //세로
			for (int j = 0; j < M[t]; j++) { //가로
				if (visited[t][i][j] != 1 && field[t][i][j] == 1) {
					earthworm++;
					DFS(t, i, j);
				}
			}
		}
		cout << earthworm << endl;
	}
}