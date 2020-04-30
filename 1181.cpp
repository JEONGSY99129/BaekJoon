#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <string> v;

bool compare(string a, string b)
{
	if (a.length() != b.length()) {
		return a.length()<b.length(); //���̰� �ٸ��� ���� ª����� ����
	}
	else {
		return a < b; //���� ������ ���� ����� ����
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

	sort(v.begin(), v.end(), compare); //compare �Լ���� �������� �����ϱ�
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
}