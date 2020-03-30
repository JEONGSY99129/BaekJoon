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
	}//A의 이진수 자릿수 세기
	
	long long msb = A - (long long)pow(2, length-1)+1; //A와 A의 이진수 자릿수와 같은 수 중에서 제일 작은 수 사이의 숫자 개수(최상위 비트 1의 개수)

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
