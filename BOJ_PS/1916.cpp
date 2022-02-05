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
    int src, accum_cost;
    //�� operator�� const �Լ��μ� �����, ���ڵ� const �����ڷ� ����
    bool operator<(const struct _info &next) const
    {
        return accum_cost > next.accum_cost;
    }
} info;
int n, m, start, destination;
int dist[1001];
vector<vector<edge>> graph;

void dijkstra()
{
    //��Һ񱳸� ������������ �̱� ���� ���� �����ڸ� �����ε����� �ʰ�
    //�񱳵Ǵ� �ڷᱸ����(pair������) ������ �Ѱܼ� ������ ������ �̿��� ���� �ִ�.
    priority_queue<info> pq;
    dist[start] = 0;
    pq.push({start, 0});
    info cur;
    while (!pq.empty())
    {
        cur = pq.top();
        pq.pop();
        if (dist[cur.src] < cur.accum_cost)
            continue;
        for (const auto &iter : graph[cur.src])
        {
            if (dist[iter.dest] > dist[cur.src] + iter.weight)
            {
                dist[iter.dest] = dist[cur.src] + iter.weight;
                pq.push({iter.dest, dist[iter.dest]});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    graph.assign(n + 1, vector<edge>());
    int src, dest, weight;
    forn(i, m)
    {
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
    }
    cin >> start >> destination;
    fornn(i, n)
        dist[i] = INF;
    dijkstra();
    cout << dist[destination] << '\n';
}

bool multi = false;
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
