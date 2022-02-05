#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v, ss;
bool p[500001];
int pp[100000];
int bin_search(int start, int end, int val)
{
    if (start > end)
        return start;
    else if (start == end)
    {
        //�� �κп��� �ε����� ��Ȧ�� �ٷ���. LIS�� �ε��� ���� ���� ã�� ���� �� �ε��������� ������ ũ�ٸ� �� ���� �ε����� �����ؾ߸� �Ѵ�.(�׷��� ������ ������ �߻��Ѵ�)
        if (v[start].second < val)
            return start + 1;
        else
            return start;
    }
    int mid = (start + end) / 2;
    if (v[mid].second < val)
        return bin_search(mid + 1, end, val);
    else
        return bin_search(start, mid - 1, val);
}
int main()
{
    FAST;
    int n;
    cin >> n;
    ss.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ss[i].first >> ss[i].second;
        p[ss[i].first] = true;
    }
    sort(ss.begin(), ss.end());
    v.push_back(ss[0]);
    pp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int pos;
        if (v[v.size() - 1].second < ss[i].second)
        {
            v.push_back(ss[i]);
            pp[i] = v.size() - 1;
        }
        else
        {
            pos = bin_search(0, v.size() - 1, ss[i].second);
            v[pos] = ss[i];
            pp[i] = pos;
        }
    }
    int cnt = v.size() - 1;
    for (int i = n - 1; i >= 0 && cnt >= 0; i--)
    {
        if (pp[i] == cnt)
        {
            p[ss[i].first] = false;
            cnt--;
        }
    }
    cout << n - v.size() << '\n';
    for (int i = 0; i <= 500000; i++)
        if (p[i])
            cout << i << '\n';
    return 0;
}