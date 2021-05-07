#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int i = 0;i < T;i++)
    {
        int n, E;
        int mark[501] = {};
        int graph[501][501] = {};
        vector<int> nodes(0);
        int result = 0;
        cin >> n >> E;
        for (int j = 1;j <= n;j++)
        {
            for (int k = 1;k <= n;k++)
            {
                if (j == k);
                else
                {
                    graph[j][k] = INT32_MAX;
                }
            }
        }
        for (int j = 0;j < E;j++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (graph[u][v] > w)
            {
                graph[u][v] = w;
                graph[v][u] = graph[u][v];
            }
        }
        nodes.push_back(1);
        mark[1] = 1;
        while (1)
        {
            int minedge = INT32_MAX;
            int minvertex = 0;
            for (int j = 0;j < nodes.size();j++)
            {
                for (int k = 1;k <= n;k++)
                {
                    if (!mark[k] && graph[nodes[j]][k] < minedge)
                    {
                        minvertex = k;
                        minedge = graph[nodes[j]][k];
                    }
                }
            }
            if (minvertex)
            {
                nodes.push_back(minvertex);
                result += minedge;
                mark[minvertex] = 1;
            }
            else
            {
                break;
            }
        }
        if (nodes.size() == n)
        {
            cout << result << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
}