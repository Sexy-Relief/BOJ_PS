//dfs���� ���� ��ͷ� © �� pruning�� �ſ� �߿��ϴ�.
//�� �������� �ܼ��� �� ���տ� ���� visited �迭�� ����� 20���� ���ҿ� ���� ���� �� ���� ��� ȣ����
//�����ϸ� 2^20�� �ݺ��� ���� visited �迭�� �˻��ϴ� ������ ��ġ����, �Ʒ��� ���� �ڵ��ϸ�
//20C10 ���� �������� to�� from �� ������ �� �Ҵ�Ǹ� �� ������ �������θ� ������ �� �ֱ� ������
//�ξ� ������ ����� �� �ִ�.
#define INF 100000000.0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct _point
{
    double x, y;
} point;
point pt[20];
int n;
double x, y;
double minlen;
void dfs(double x, double y, int idx, int to, int from)
{
    if (to == 0 & from == 0)
    {
        if (minlen > sqrt(x * x + y * y))
            minlen = sqrt(x * x + y * y);
        return;
    }
    if (to > 0)
    {
        dfs(x + pt[idx].x, y + pt[idx].y, idx + 1, to - 1, from);
    }
    if (from > 0)
    {
        dfs(x - pt[idx].x, y - pt[idx].y, idx + 1, to, from - 1);
    }
}
void solve()
{
    minlen = INF;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pt[i] = {x, y};
    }
    dfs(0, 0, 0, n / 2, n / 2);
    cout << minlen << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    cout << fixed;
    cout.precision(6);
    while (t--)
        solve();
    return 0;
}