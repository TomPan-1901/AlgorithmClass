#include <iostream>
using namespace std;
int solve(int graph[501][501], int n, int s, int t);
int main()
{
    int m;
    cin >> m;
    int graph[501][501];
    for (int i = 0;i < m;i++)
    {
        int n, E, s, t;
        cin >> n >> E >> s >> t;
        for (int j = 1;j <= n;j++)
        {
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
        cout << solve(graph, n, s, t) << endl;
    }
}
int solve(int graph[501][501], int n, int s, int t)
{
}