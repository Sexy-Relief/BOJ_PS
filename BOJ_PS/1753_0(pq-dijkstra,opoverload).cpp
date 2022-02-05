//struct ���� �ε�ȣ ������ �����ε�, pq �̿��� dijkstra(! �� �ڵ�� ��°�� �ܿ��� �׳�)
//dijkstra���� ������ ���õ� ������ dist�� Ȯ���ϴ� �� O(V^2+E),
//Priority Queue�� ���ؼ� ��� ������ �˻��ϴµ�, �־��� ��� ��� ������ ���� PQ�� ������ push�ϹǷ�
//O(ElogE)=O(ElogV)�� �ȴ�. ���� complete graph�� �������� �� �� ���⵵�� ������������,
//�Ϲ����� ��� E�� V(V+1)/2�� ���� ����ġ�Ƿ� Priority queue�� �̿��� ����� �ξ� �����ٰ� �� ���̴�.
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>
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
    int node;
    int accum_cost;
    bool operator<(const struct _info &next) const //typedef struct������ �� struct ��Ī�� struct _info ó�� strcut�� �ٿ��ִ°� �����ϴ�.(���� �׸��� �׷��� �ؾߵȴ�.)
    {
        return this->accum_cost > next.accum_cost;
    }
} info;

int v, e;
int start;
int *dist;
vector<vector<edge>> graph;
void dijkstra()
{
    //�����غ��� priority queue�� Ÿ�� �ϳ��� �ָ� �� �ڷ����� ��� �񱳸� �˾Ƽ� �ؼ�
    //������ ���ش�. ���� �� Ÿ�Կ� ���� ������ struct�� ������ �ε�ȣ �����ε��� �ڿ�������
    //����� �Ѵٴ� ������ ���.
    priority_queue<info> pq;
    pq.push({start, 0}); //operator overloading�� class�� �̷� ������ ���ڸ� �ѱ� �� ����. struct�� �����Ѱ���
    info now;
    dist[start] = 0;
    while (!pq.empty())
    {
        now = pq.top();
        pq.pop();
        if (dist[now.node] < now.accum_cost)
            continue;
        for (const auto &iter : graph[now.node])
        {
            if (dist[iter.dest] > dist[now.node] + iter.weight)
            {
                dist[iter.dest] = dist[now.node] + iter.weight;
                pq.push({iter.dest, dist[iter.dest]});
            }
        }
    }
}

void solve()
{
    cin >> v >> e;
    cin >> start;
    graph.assign(v + 1, vector<edge>());
    dist = new int[v + 1];
    fornn(i, v)
        dist[i] = INF;
    int src, dest, weight;
    forn(i, e)
    {
        cin >> src >> dest >> weight;
        graph[src].push_back({dest, weight});
    }
    dijkstra();
    fornn(i, v)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
    delete[] dist;
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