#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 8
#define SPACEMAX 100
int matrix[MAX][MAX];
int copymatrix[MAX][MAX]; //원본 매트릭스 복사
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector <int> available_space[SPACEMAX]; //벽을 세울수 있는 좌표들을 저장
int num = 0; //available_space의 크기
int N, M; // N : 세로 크기, M : 가로 크기
int visited[MAX][MAX];
int maxnum = 0; //최종 출력 값
int safety_z; //각 케이스들에 대한 safety zone 카운트 변수

void DFS(int current_y, int current_x) {
	visited[current_y][current_x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = current_x + dx[i];
		int ny = current_y + dy[i];

		if (0 <= nx && nx < M && 0 <= ny && ny < N && visited[ny][nx] == 0) //범위 안에 안 들어가면 거들떠 보지도 않음.
		{
			if (copymatrix[ny][nx] == 0) { //움직인 범위가 유효한 범위라면 + 알파 조건이 필요할듯,,?
				copymatrix[ny][nx] = 2;
				DFS(ny, nx);
			}
			else if (visited[ny][nx]==1){
				visited[ny][nx] = 1;
			}
		}
	}
}

int Check_SafetyZone() {
	safety_z = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copymatrix[i][j] == 0) {
				safety_z++;
			}
		}
	}
	return safety_z;
}


void Making_wall() {

	for (int i = 0; i < num-2; i++) {
		int point_x1 = available_space[i][1];
		int point_y1 = available_space[i][0];

		matrix[point_y1][point_x1] = 1; //첫번째 벽 세우기
		for (int j = i+1; j < num - 1; j++) {
			int point_x2 = available_space[j][1];
			int point_y2 = available_space[j][0];

			matrix[point_y2][point_x2] = 1; //두번째 벽 세우기
			for (int k = j + 1; k < num; k++)
			{
				int point_x3 = available_space[k][1];
				int point_y3 = available_space[k][0];

				matrix[point_y3][point_x3] = 1; //여기까지 벽 3개 다 세우고

				memset(visited, 0, sizeof(visited));
				memcpy(copymatrix, matrix, sizeof(matrix)); //변하는 matrix copy

				for (int n = 0; n < N; n++) {
					for (int m = 0; m < M; m++) {
						if (!visited[n][m] && copymatrix[n][m] == 2) //아직 방문하지 않은 곳에 바이러스 발견했으면
						{
							DFS(n, m); //DFS들어가서 바이러스 퍼트리기
						}
					}
				}
				maxnum = max(maxnum, Check_SafetyZone()); //바뀐 matrix를 보고 safety zone 확인 후 제일 큰 경우만 저장
				matrix[point_y3][point_x3] = 0; //벽 세운거 해제
				
			}
			matrix[point_y2][point_x2] = 0;
		}
		matrix[point_y1][point_x1] = 0;
	}
}

int main() {
	cin >> N >> M;
	if (3 <= N && N <= 8 && 3 <= M && M <= 8) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> matrix[i][j]; //입력 받고
				if (matrix[i][j] == 0) //벽 세울수 있는 곳이면 available_space에 저장
				{
					available_space[num].push_back(i);
					available_space[num].push_back(j);
					num++;
				}
			}
		}
	} //matrix 입력받기

	Making_wall(); //벽 세개 세우고 바이러스 퍼트리고 safety zone 카운트 하러 감

	cout << maxnum << endl;
}
