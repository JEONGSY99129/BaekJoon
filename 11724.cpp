#include<iostream>
#include<vector>
using namespace std;

int visited[1001] = { 0 }; //아직 다 방문안한 상태로 초기화
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
		for (int i = 0; i < M; i++) { //Vertex와 Edge개수 맞으면 input 받을 준비
			cin >> num1 >> num2; 
			if (1 <= num1 && num1 <= N && 1 <= num2 && num2 <= N) { //양쪽 정점에 대해 조건이 맞으면
				v[num1].push_back(num2); //때려박음
				v[num2].push_back(num1);
			}
		}
	}

	int connected_compo=0;

	for (int i = 1; i <= N; i++) { //
		if (!visited[i]) //visited가 1이 아니면
		{
			DFS(i); //DFS 돌리기 , 한 연결요소 다 돌고 나오면 아직 방문한 노드가 발견될 때까지 확인
			connected_compo++;
		}
	}

	cout << connected_compo << endl;
}