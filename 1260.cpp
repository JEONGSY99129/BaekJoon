#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int visited[1001] = { 0 }; //아직 다 방문안한 상태로 초기화
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
//visited 0만들면 안됌. 골치아파짐

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
	cin >> N >> M >> V; //vertex, edge, start 입력받기

	if (1 <= N && N <= 1000 && 1 <= M && M <= 10000 && 1 <= V && V <= N) { //input 조건 확인
		for (int i = 0; i < M; i++) { //edge 개수만큼 입력 받기
			cin >> ver1 >> ver2;
			v[ver2].push_back(ver1);
			v[ver1].push_back(ver2);
		}
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end()); //vector 배열 오름차순 정렬
	}

	DFS(V); //DFS시작
	cout << endl;
	memset(visited, 0, sizeof(visited)); //0으로 초기화
	BFS(V); //출력은 이 안에서 하는걸로, void
}