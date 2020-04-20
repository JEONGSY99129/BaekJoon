#include<iostream>
#include<cstring>
#include<algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

#define MAX 50
char chess[MAX][MAX];
int error[MAX][MAX]; //errorüũ�ϴ� matrix
int M, N; //M : ����, N : ����

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
	min_error = total_error; //�ϴ� �� ù 8*8���̽� error ���� min_error�� ��������.

	total_error = 0;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) { // start ������ (0, 0)�� ���̽��� �����ϰ�
			
			if (i + 7 < M && j + 7 < N) { //start �������κ��� 8*8�� matrix ������ original �迭�� ���� �ʾ��� ��
				for (int h = i; h <= i + 7; h++) { //���� ���� i(����)�κ��� 8���� �迭
					for (int w = j; w <= j + 7; w++) { //���� ���� j(����)�κ��� 8���� �迭
						if (error[h][w]) { //error�� �ִ� ���̸�
							total_error++;
						}
					}
				}
				min_error = min(min_error, total_error); //min_error�� ������.
			}
			total_error = 0; //total_error 0���� �ʱ�ȭ ����.

		}
	}

	return min_error;
}

int check_error(char compare_value) {

	memset(error, 0, sizeof(error));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (chess[i][j] != compare_value) {//�ùٸ� ���� �ٸ���
				error[i][j] = 1; //errorüũ�ϰ�
			}

			if (j != N - 1) { //�������� ������ �ε����� �ƴҶ��� �ٲ��ֱ�(�������� ������ �ε��������� �����ٷ� �ѱ涧 ������������ �״�� �Ѱ�����ϹǷ�)
				if (compare_value == 'B') { //compare_value �ݺ������� �ٲ��ֱ�
					compare_value = 'W';
				}
				else {
					compare_value = 'B';
				}
			}
			else {
				if (N % 2) {
					if (compare_value == 'B') { //compare_value �ݺ������� �ٲ��ֱ�
						compare_value = 'W';
					}
					else {
						compare_value = 'B';
					}
				}
			}
		}
	} //������� error üũ�ϰ� �ùٸ��� ��������.

	return Count_Error(); //error �迭�� �ּ� ���� ã��
}

int B_First() {
	
	return check_error('B'); //error üũ�ϱ�
}

int W_First() {
	
	return check_error('W'); //W�� ��ŸƮ�϶� error üũ�ϱ�
	
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

	result = B_First(); //0, 0�� B�� ��
	
	result = min(result, W_First());
	cout << result << endl;
}