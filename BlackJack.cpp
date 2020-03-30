#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100

int main() {
    int N, M;
    cin >> N >> M; //N : 카드의 개수, M : sum limit
    int maxnum = 0;
    int sum = 0;
    int cards[MAX] = { 0 };

    if (3 <= N && N <= 100 && 10 <= M && M <= 300000) {
        for (int i = 0; i < N; i++) {
            cin >> cards[i];
            if (cards[i] > 100000)
            {
                cards[i] = 0; //입력 받았으면 0으로 바꾸고, i--로 back.
                i--;
            }
        } //받은 카드 갯수만큼 입력 받기
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