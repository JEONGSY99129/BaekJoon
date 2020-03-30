#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int visited[1001] = { 0 }; //���� �� �湮���� ���·� �ʱ�ȭ
vector <int> v[1001];
queue <int> q[1001];


void DFS(int start) {
	while (visited[start] != 1) {
		visited[start] = 1;
		cout << start << " ";
		for (int i = 0; i < v[start].size(); i++) {
			int index = v[start][i];
			if (visited[index] != 1) {
				DFS(index);
			}
		}
	}
}
//visited 0����� �ȉ�. ��ġ������

void BFS(int start) {
	visited[start] = 1;
	q->push(start);

	while (!q->empty()) {
		int currentnum = q->front();
		q->pop();
		cout << currentnum << " ";
		for (int i = 0; i < v[currentnum].size(); i++) {
			int index = v[currentnum][i];
			if (visited[index] != 1) {
				q->push(index);
				visited[index] = 1;

			}
		}
	}

}


int main() {
	int N, M, V;
	int ver1, ver2;
	cin >> N >> M >> V; //vertex, edge, start �Է¹ޱ�

	if (1 <= N && N <= 1000 && 1 <= M && M <= 10000 && 1 <= V && V <= N) { //input ���� Ȯ��
		for (int i = 0; i < M; i++) { //edge ������ŭ �Է� �ޱ�
			cin >> ver1 >> ver2;
			v[ver2].push_back(ver1);
			v[ver1].push_back(ver2);
		}
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end()); //vector �迭 �������� ����
	}

	DFS(V); //DFS����
	cout << endl;
	memset(visited, 0, sizeof(visited)); //0���� �ʱ�ȭ
	BFS(V); //����� �� �ȿ��� �ϴ°ɷ�, void
}