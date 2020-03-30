#include<iostream>
#include<vector>
using namespace std;

int visited[1001] = { 0 }; //���� �� �湮���� ���·� �ʱ�ȭ
vector <int> v[1001];

void DFS(int start) {
	while (visited[start] != 1) {
		visited[start] = 1;
		for (int i = 0; i < v[start].size(); i++) {
			int index = v[start][i];
			if (visited[index] != 1) {
				DFS(index);
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	int num1, num2;
	
	if (1 <= N && N <= 1000 && 0 <= M && M <= N * (N - 1) / 2) {
		for (int i = 0; i < M; i++) { //Vertex�� Edge���� ������ input ���� �غ�
			cin >> num1 >> num2; 
			if (1 <= num1 && num1 <= N && 1 <= num2 && num2 <= N) { //���� ������ ���� ������ ������
				v[num1].push_back(num2); //��������
				v[num2].push_back(num1);
			}
		}
	}

	int connected_compo=0;

	for (int i = 1; i <= N; i++) { //
		if (!visited[i]) //visited�� 1�� �ƴϸ�
		{
			DFS(i); //DFS ������ , �� ������ �� ���� ������ ���� �湮�� ��尡 �߰ߵ� ������ Ȯ��
			connected_compo++;
		}
	}

	cout << connected_compo << endl;
}