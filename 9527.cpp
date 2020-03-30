#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

long long f(long long A) {

	if (A <= 0) {
		return 0;
	}
	long long tmp = A;
	int length;
	for (length = 0; tmp != 0; ) {
		tmp = tmp >> 1;
		length++;
	}//A�� ������ �ڸ��� ����
	
	long long msb = A - (long long)pow(2, length-1)+1; //A�� A�� ������ �ڸ����� ���� �� �߿��� ���� ���� �� ������ ���� ����(�ֻ��� ��Ʈ 1�� ����)

	long long countnum = ((long long)length - 1) * (long long)pow(2, length - 2);

	long long NextHighestnum = f(B- (long long)pow(2, length - 1));

	

	return msb + countnum +NextHighestnum;
}

int main() {
	long long A, B;
	cin >> A >> B;

	if ((A < 1) || (A > 10000000000000000) || (B < A) || (B > 10000000000000000)) {
		cout << "input error" << endl;
		return 0;
	}
	cout << f(B)-f(A-1) << endl;
}
