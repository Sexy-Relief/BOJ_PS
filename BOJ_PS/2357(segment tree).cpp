//���� ���� �ּҰ�, �ִ밪�� Ž���ϴ� �� ����� ���׸�Ʈ Ʈ��
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
vector<ll> seq, mintree, maxtree;
int n, m;
void make_tree(bool flag, int start, int end, int root)
{
	if (!flag)
	{
		if (start == end)
		{
			mintree[root] = seq[start];
			return;
		}
		int mid = (start + end) / 2;
		make_tree(0, start, mid, root * 2);
		make_tree(0, mid + 1, end, root * 2 + 1);
		mintree[root] = min(mintree[root * 2], mintree[root * 2 + 1]);
	}
	else
	{
		if (start == end)
		{
			maxtree[root] = seq[start];
			return;
		}
		int mid = (start + end) / 2;
		make_tree(1, start, mid, root * 2);
		make_tree(1, mid + 1, end, root * 2 + 1);
		maxtree[root] = max(maxtree[root * 2], maxtree[root * 2 + 1]);
	}
}
ll min_find(int start, int end, int root, int low, int high)
{
	if (high < start || end < low)
		return INF;
	if (low <= start && end <= high)
		return mintree[root];
	int mid = (start + end) / 2;
	return min(min_find(start, mid, root * 2, low, high), min_find(mid + 1, end, root * 2 + 1, low, high));
}
ll max_find(int start, int end, int root, int low, int high)
{
	if (high < start || end < low)
		return 0;
	if (low <= start && end <= high)
		return maxtree[root];
	int mid = (start + end) / 2;
	return max(max_find(start, mid, root * 2, low, high), max_find(mid + 1, end, root * 2 + 1, low, high));
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	int o1, o2;
	int t_size = (int)ceil(log2(n));
	t_size = pow(2, t_size + 1);
	seq.resize(n), mintree.resize(t_size), maxtree.resize(t_size);
	for (int i = 0; i < n; i++)
		cin >> seq[i];
	make_tree(0, 0, n - 1, 1);
	make_tree(1, 0, n - 1, 1);
	for (int i = 0; i < m; i++)
	{
		cin >> o1 >> o2;
		cout << min_find(0, n - 1, 1, o1 - 1, o2 - 1) << " " << max_find(0, n - 1, 1, o1 - 1, o2 - 1) << '\n';
	}
	return 0;
}