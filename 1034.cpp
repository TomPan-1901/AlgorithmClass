#include <iostream>
#include <vector>
using namespace std;
void solve(int node, vector<vector<int>>& graph,
    vector<int>& vis, vector<vector<int>>& dp);
int main()
{
    int T;
    cin >> T;
    for (int i = 0;i < T;i++)
    {
        int N;
        cin >> N;
        vector<vector<int>> graph(N + 1);
        vector<int> vis(N + 1);
        vector<vector<int>> dp(N + 1);
        for (int j = 1;j <= N;j++)
        {
            dp[j].resize(2);
        }
        for (int j = 0;j < N - 1;j++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        solve(1, graph, vis, dp);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
}
void solve(int node, vector<vector<int>>& graph,
    vector<int>& vis, vector<vector<int>>& dp)
{
    // cout << node << endl;
    vis[node] = 1;
    int flag = 1;
    for (int i = 0;i < graph[node].size();i++)
    {
        if (!vis[graph[node][i]])
        {
            flag = 0;
            solve(graph[node][i], graph, vis, dp);
            //vis[graph[node][i]] = 0;
        }
    }
    // 0 for white, 1 for black
    if (flag)
    {
        dp[node][0] = 0;
        dp[node][1] = 1;
    }
    else
    {
        // node is black
        int black = 1;
        for (int i = 0;i < graph[node].size();i++)
        {
            black += dp[graph[node][i]][0];
        }
        dp[node][1] = black;
        // node is white
        int white = 0;
        for (int i = 0;i < graph[node].size();i++)
        {
            white += max(dp[graph[node][i]][0], dp[graph[node][i]][1]);
        }
        dp[node][0] = white;
        // cout << node << " " << black << " " << white << endl;
    }
    return;
}