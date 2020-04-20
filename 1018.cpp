#include<iostream>
#include<cstring>
#include<algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#define MAX 50
char chess[MAX][MAX];
int error[MAX][MAX]; //error체크하는 matrix
int M, N; //M : 세로, N : 가로

int Count_Error() {
	int total_error = 0;
	int min_error;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (error[i][j]) {
				total_error++;
			}
		}
	}
	min_error = total_error; //일단 맨 첫 8*8케이스 error 수를 min_error로 설정해줌.

	total_error = 0;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) { // start 지점이 (0, 0)인 케이스를 제외하고
			
			if (i + 7 < M && j + 7 < N) { //start 지점으로부터 8*8한 matrix 범위가 original 배열을 넘지 않았을 떄
				for (int h = i; h <= i + 7; h++) { //현재 들어온 i(세로)로부터 8개의 배열
					for (int w = j; w <= j + 7; w++) { //현재 들어온 j(가로)로부터 8개의 배열
						if (error[h][w]) { //error가 있던 곳이면
							total_error++;
						}
					}
				}
				min_error = min(min_error, total_error); //min_error와 비교해줌.
			}
			total_error = 0; //total_error 0으로 초기화 해줌.

		}
	}

	return min_error;
}

int check_error(char compare_value) {

	memset(error, 0, sizeof(error));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (chess[i][j] != compare_value) {//올바른 값과 다르면
				error[i][j] = 1; //error체크하고
			}

			if (j != N - 1) { //가로줄의 마지막 인덱스가 아닐때만 바꿔주기(가로줄의 마지막 인덱스에서는 다음줄로 넘길때 변경하지말고 그대로 넘겨줘야하므로)
				if (compare_value == 'B') { //compare_value 반복적으로 바꿔주기
					compare_value = 'W';
				}
				else {
					compare_value = 'B';
				}
			}
			else {
				if (N % 2) {
					if (compare_value == 'B') { //compare_value 반복적으로 바꿔주기
						compare_value = 'W';
					}
					else {
						compare_value = 'B';
					}
				}
			}
		}
	} //여기까지 error 체크하고 올바르게 변경해줌.

	return Count_Error(); //error 배열로 최소 오류 찾기
}

int B_First() {
	
	return check_error('B'); //error 체크하기
}

int W_First() {
	
	return check_error('W'); //W가 스타트일때 error 체크하기
	
}

int main() {
	int result;
	cin >> M >> N;

	if (8 <= M && M <= 50 && 8 <= N && N <= 50) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> chess[i][j];
			}
		}
	}

	result = B_First(); //0, 0가 B일 때
	
	result = min(result, W_First());
	cout << result << endl;
}