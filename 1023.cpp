#include <iostream>
#include <queue>
using namespace std;
const int INF = 100000000;
void solve(int s, int M, int n,
    int dp[501][101], int graph[501][501], int* fee);
int main()
{
    int T;
    cin >> T;
    for (int b = 0;b < T;b++)
    {
        int n, E, s, t, M;
        cin >> n >> E >> s >> t >> M;
        int fee[501] = {};
        for (int i = 1;i <= n;i++)
        {
            int temp;
            cin >> temp;
            if (i != s)
            {
                fee[i] = temp;
            }
        }
        int graph[501][501] = {};
        for (int i = 0;i < E;i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (!graph[u][v] || w < graph[u][v])
            {
                graph[u][v] = w;
                graph[v][u] = w;
            }
        }
        int dp[501][101] = {};
        solve(s, M, n, dp, graph, fee);
        int res = INF;
        for (int i = 0;i <= M;i++)
        {
            res = min(dp[t][i], res);
        }
        if (res != INF)
        {
            cout << res << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}
void solve(int s, int M, int n,
    int dp[501][101], int graph[501][501], int* fee)
{
    bool vis[501] = {};
    for (int i = 1;i <= n;i++)
    {
        for (int j = 0;j <= M;j++)
        {
            if (i != s)
                dp[i][j] = INF;
            else
                dp[i][j] = 0;
        }
    }
    int j = s;
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        j = q.front();
        q.pop();
        vis[j] = 0;
        for (int k = 1;k <= n;k++)
        {
            if (graph[j][k])
            {
                for (int l = fee[k];l <= M;l++)
                {
                    if (dp[j][l - fee[k]] + graph[j][k] < dp[k][l])
                    {
                        dp[k][l] = dp[j][l - fee[k]] + graph[j][k];
                        if (!vis[k])
                        {
                            vis[k] = 1;
                            q.push(k);
                        }
                    }
                }
            }
        }
    }
}