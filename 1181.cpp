#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <string> v;

bool compare(string a, string b)
{
	if (a.length() != b.length()) {
		return a.length()<b.length(); //길이가 다르면 길이 짧은대로 정렬
	}
	else {
		return a < b; //길이 같으면 문자 순대로 정렬
	}
}
int main() {
	int N;
	cin >> N;

	if (1 <= N && N <= 20000) {
		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
	}

	sort(v.begin(), v.end(), compare); //compare 함수라는 기준으로 정렬하기
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}