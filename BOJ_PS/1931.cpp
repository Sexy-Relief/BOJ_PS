//key�� ���� �� value �������ε� ������ �ؾ� �Ѵٸ� multimap������ ���⺸�� pair�� ��� vector�� ����� �����ϴ°� ����
//pair�� �⺻������ first�� ������ second�� �����ϵ��� �Ǿ��ִ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int start, end;
	int nowend;
	int count = 0;
	vector<pair<int, int>> vecsche;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		vecsche.push_back(make_pair(end, start));
	}
	sort(vecsche.begin(), vecsche.end());
	nowend = -1;
	for (const auto& iter : vecsche) {
		if (iter.second >= nowend) {
			count++;
			nowend = iter.first;
		}
	}
	cout << count << '\n';
	return 0;
}