#include <iostream>
using namespace std;
// 常规的算法
void Dijkstra(int s, int G[501][501], int n, int* d);
int main()
{
    int m;
    cin >> m;
    int graph[501][501];
    for (int i = 0;i < m;i++)
    {
        int n, E, s, t;
        cin >> n >> E >> s >> t;
        int d[501] = {};
        for (int j = 1;j <= n;j++)
        {
            d[j] = INT16_MAX;
            for (int k = 1;k <= n;k++)
            {
                if (j == k)
                {
                    graph[j][k] = 0;
                }
                else
                {
                    graph[j][k] = INT16_MAX;
                }
            }
        }
        for (int j = 0;j < E;j++)
        {
            int u, v;
            cin >> u >> v;
            int temp;
            cin >> temp;
            if (graph[u][v] > temp)
            {
                graph[u][v] = temp;
                graph[v][u] = graph[u][v];
            }
        }
        Dijkstra(s, graph, n, d);
        if (d[t] == INT16_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << d[t] << endl;
        }
    }
}
void Dijkstra(int s, int G[501][501], int n, int* d)
{
    d[s] = 0;
    bool vis[501] = {};
    for (int i = 0;i < n;i++)
    {
        int u = -1;
        int MIN = INT16_MAX;
        for (int j = 1;j <= n;j++)
        {
            if (vis[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
        {
            return;
        }
        vis[u] = true;
        for (int v = 1;v <= n;v++)
        {
            if (vis[v] == false && G[u][v] != INT16_MAX && d[u] + G[u][v] < d[v])
            {
                d[v] = d[u] + G[u][v];
            }
        }
    }
}