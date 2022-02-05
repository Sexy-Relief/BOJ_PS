#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//qsort�� comp �Լ��� ����Ÿ���� int�μ� const void*�� ���ڸ� �޾� 1,0,-1�� �������ش�.
//1�� �����ϸ� swap�� �ʿ��ϴٰ� ��������
int qcomp(const void *a, const void *b)
{
	int aa = *(int *)a;
	int bb = *(int *)b;
	if (aa > bb)
		return 1;
	else if (aa == bb)
		return 0;
	else
		return -1;
}

//vector�� �׳� array�� sort �Լ��� ����° ���ڷμ� ���� �� ���Լ��� ����Ÿ���� bool�μ� false�� ��� swap�ϵ�����(true ����� �����ϰ� ����)
bool sortcomp(const int &a, const int &b)
{
	if (a > b)
		return false;
	else
		return true;
}
//class�� struct�� ���� �����ؼ� �ű⼭ �����ڸ� �����ε����Ѿ� �ϴ� ���.
//�� ��Ŀ������ sortcomp�� �ݴ�� true�� swap�ϵ��� ��(false �������� ����)
class classcomp
{
public:
	bool operator()(const int &a, const int &b)
	{
		if (a > b)
			return false;
		else
			return true;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, command;
	int a[10] = {8, 1, 4, 9, 2, 3, 6, 5, 7, 0};
	vector<int> b;
	b.push_back(8);
	b.push_back(1);
	b.push_back(4);
	b.push_back(9);
	b.push_back(2);
	b.push_back(3);
	b.push_back(6);
	b.push_back(5);
	b.push_back(7);
	b.push_back(0);
	priority_queue<int, vector<int>, classcomp> pq;
	pq.push(8);
	pq.push(1);
	pq.push(4);
	pq.push(9);
	pq.push(2);
	pq.push(3);
	pq.push(6);
	pq.push(5);
	pq.push(7);
	pq.push(0);
	qsort(a, 10, sizeof(int), qcomp);
	sort(b.begin(), b.end(), sortcomp);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " " << b[i] << " " << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}