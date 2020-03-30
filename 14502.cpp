#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 8
#define SPACEMAX 100
int matrix[MAX][MAX];
int copymatrix[MAX][MAX]; //���� ��Ʈ���� ����
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector <int> available_space[SPACEMAX]; //���� ����� �ִ� ��ǥ���� ����
int num = 0; //available_space�� ũ��
int N, M; // N : ���� ũ��, M : ���� ũ��
int visited[MAX][MAX];
int maxnum = 0; //���� ��� ��
int safety_z; //�� ���̽��鿡 ���� safety zone ī��Ʈ ����

void DFS(int current_y, int current_x) {
	visited[current_y][current_x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = current_x + dx[i];
		int ny = current_y + dy[i];

		if (0 <= nx && nx < M && 0 <= ny && ny < N && visited[ny][nx] == 0) //���� �ȿ� �� ���� �ŵ鶰 ������ ����.
		{
			if (copymatrix[ny][nx] == 0) { //������ ������ ��ȿ�� ������� + ���� ������ �ʿ��ҵ�,,?
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

		matrix[point_y1][point_x1] = 1; //ù��° �� �����
		for (int j = i+1; j < num - 1; j++) {
			int point_x2 = available_space[j][1];
			int point_y2 = available_space[j][0];

			matrix[point_y2][point_x2] = 1; //�ι�° �� �����
			for (int k = j + 1; k < num; k++)
			{
				int point_x3 = available_space[k][1];
				int point_y3 = available_space[k][0];

				matrix[point_y3][point_x3] = 1; //������� �� 3�� �� �����

				memset(visited, 0, sizeof(visited));
				memcpy(copymatrix, matrix, sizeof(matrix)); //���ϴ� matrix copy

				for (int n = 0; n < N; n++) {
					for (int m = 0; m < M; m++) {
						if (!visited[n][m] && copymatrix[n][m] == 2) //���� �湮���� ���� ���� ���̷��� �߰�������
						{
							DFS(n, m); //DFS���� ���̷��� ��Ʈ����
						}
					}
				}
				maxnum = max(maxnum, Check_SafetyZone()); //�ٲ� matrix�� ���� safety zone Ȯ�� �� ���� ū ��츸 ����
				matrix[point_y3][point_x3] = 0; //�� ����� ����
				
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
				cin >> matrix[i][j]; //�Է� �ް�
				if (matrix[i][j] == 0) //�� ����� �ִ� ���̸� available_space�� ����
				{
					available_space[num].push_back(i);
					available_space[num].push_back(j);
					num++;
				}
			}
		}
	} //matrix �Է¹ޱ�

	Making_wall(); //�� ���� ����� ���̷��� ��Ʈ���� safety zone ī��Ʈ �Ϸ� ��

	cout << maxnum << endl;
}