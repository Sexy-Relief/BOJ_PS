//set�̳� map�� ������ ���Ҹ� iterator�� �����ؾ� �ɶ� --set.end()�� ������ �� �ִ�!!!!!!!!
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T,n_input;
	char command; int commandnum;
	multiset<int> pq;
	multiset<int>::iterator iter;
	multiset<int>::iterator iter2;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n_input;
		for (int j = 0; j < n_input; j++) {
			cin >> command >> commandnum;
			if (command == 'I') {
				pq.insert(commandnum);
			}
			else {
				if (pq.empty())
					continue;
				else {
					if (commandnum == -1) {
						pq.erase(pq.begin());
					}
					else {
						pq.erase(--pq.end());
					}
				}
			}
		}
		if (pq.empty())
			cout << "EMPTY\n";
		else {
			iter = pq.begin();
			iter2 = --pq.end();
			cout << *iter2 << " " << *iter << '\n';
		}
		pq.clear();
	}
	return 0;
}