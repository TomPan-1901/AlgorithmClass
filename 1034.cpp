#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(int root, vector<vector<int>>& graph, vector<int>& mark);
int main()
{
    int T;
    cin >> T;
    for (int i = 0;i < T;i++)
    {
        int N;
        cin >> N;
        vector<vector<int>> graph(N + 1);
        vector<int> mark(N + 1);
        for (int j = 0;j < N - 1;j++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
}