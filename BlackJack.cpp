#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100

int main() {
    int N, M;
    cin >> N >> M; //N : ī���� ����, M : sum limit
    int maxnum = 0;
    int sum = 0;
    int cards[MAX] = { 0 };

    if (3 <= N && N <= 100 && 10 <= M && M <= 300000) {
        for (int i = 0; i < N; i++) {
            cin >> cards[i];
            if (cards[i] > 100000)
            {
                cards[i] = 0; //�Է� �޾����� 0���� �ٲٰ�, i--�� back.
                i--;
            }
        } //���� ī�� ������ŭ �Է� �ޱ�
    }

    for (int o = 0; o < N - 2; o++) {
        for (int t = o + 1; t < N - 1; t++) {
            for (int k = t + 1; k < N; k++) {
                sum = cards[o] + cards[t] + cards[k];

                if (sum <= M) {
                    maxnum = max(maxnum, sum);
                }
            }
        }
    }
    cout << maxnum << endl;

}