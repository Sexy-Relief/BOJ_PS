//bellman ford�� ��� stage 0�� dist�� �������� 0, ������ INF�� �ְ�
//stage 1�� �������� ����� ������ dist�� �ֽ�ȭ �ϴ� stage�� �ϸ�
//stage n-1���� ������ �ڿ� ���̻� �����ص� dist ���� ������ �ʾƾ� �Ѵ�.
//���� � ������ bellman-ford�� �ߴµ� stage n���� �� ���ϸ� ���� ����Ŭ�� �����Ѵ� ��.
//(��� connected component�� 1���� �ƴ϶�� �̷������� INF�� ������ �����Ƿ� ������ ����� �˰���
//�ε�, ���⼱ ������� �ʾ� �־ INF�� ���� weight���� ��� ������ ���� ������δ� ��� dist�� �ֽ�ȭ�ȴ�)
//!!����� ���� ���� �ݺ������� �ٷ� ������ ���������� �����ϰ� ���� �ð��� �� �þ��.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;

#define MIN(x, y) ((x) = min((x), (y)))
#define MAX(x, y) ((x) = max((x), (y)))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fornn(i, l) for (int i = 1; i <= int(l); i++)
#define INF (1e9)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef struct _edge
{
    int dest, weight;
} edge;
typedef struct _info
{
    int src, dest, weight;
} info;
vector<vector<edge>> graph;
int n, m, w;

int bellmanford(int src, int dest, int *dist)
{
    dist[src] = 0;
    for (const auto &iter : graph[src])
        if (dist[iter.dest] > iter.weight)
            dist[iter.dest] = iter.weight;
    for (int i = 2; i <= n - 1; i++)
    {
        for (int t = 1; t <= n; t++)
        {
            for (const auto &iter : graph[t])
            {
                if (dist[iter.dest] > dist[t] + iter.weight)
                    dist[iter.dest] = dist[t] + iter.weight;
            }
        }
    }
    bool flag = false;
    for (int t = 1; t <= n; t++)
    {
        for (const auto &iter : graph[t])
        {
            if (dist[iter.dest] > dist[t] + iter.weight)
            {
                cout << "YES\n";
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (flag)
        return 0;
    return 1;
}

void solve()
{
    cin >> n >> m >> w;
    graph.assign(n + 1, vector<edge>());
    int src, dest, weight;
    int dist[501];
    forn(i, m)
    {
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
        graph[dest].push_back({src, weight});
    }
    forn(i, w)
    {
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, -weight});
    }
    fornn(i, 500)
        dist[i] = INF;
    if (bellmanford(1, n, dist) == 0)
        return;
    cout << "NO\n";
}

bool multi = true;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    if (multi)
        cin >> t;
    while (t--)
        solve();
    return 0;
}