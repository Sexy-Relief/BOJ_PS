//int �迭�� memset �����ϸ� ������� �ʵ��� �Ѵ�
//multiple source-one destination shortest path�� �� edge�� ������ �ݴ�� �����ؼ�
//dijkstra �ѹ����� ���� �� �ִ�.
#define INF 2000000
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
typedef struct _edge
{
    int dest;
    int weight;
} edge;
vector<vector<edge>> a, b;
int n, m, x;

void dijkstra(int *dist, vector<vector<edge>> &vec)
{
    bool found[1001];
    memset(found, false, n + 1);
    for (const auto &iter : vec[x])
    {
        dist[iter.dest] = iter.weight;
    }
    found[x] = true;
    int min, minpos;
    for (int i = 0; i < n - 2; i++)
    {
        min = INF, minpos = -1;
        for (int t = 1; t <= n; t++)
        {
            if (dist[t] < min && !found[t])
            {
                min = dist[t];
                minpos = t;
            }
        }
        found[minpos] = true;
        for (const auto &iter : vec[minpos])
        {
            if (!found[iter.dest])
            {
                if (dist[iter.dest] > dist[minpos] + iter.weight)
                    dist[iter.dest] = dist[minpos] + iter.weight;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dist_go[1001];
    int dist_come[1001];
    cin >> n >> m >> x;
    a.assign(n + 1, vector<edge>()); //2d vector assign
    b.assign(n + 1, vector<edge>());
    for (int i = 0; i < m; i++)
    {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        a[src].push_back({dest, weight}); //���ο� ��� �ȸ��� �̷��� Ǫ���� �� �ִ�.
        b[dest].push_back({src, weight});
    }
    for (int i = 1; i <= n; i++)
    {
        dist_go[i] = INF;
        dist_come[i] = INF;
    }

    dist_go[x] = dist_come[x] = 0;
    dijkstra(dist_go, b);
    dijkstra(dist_come, a);
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (max < dist_go[i] + dist_come[i])
            max = dist_go[i] + dist_come[i];
    }
    cout << max << '\n';
    return 0;
}