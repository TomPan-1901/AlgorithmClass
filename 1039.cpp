#include <iostream>
using namespace std;
void build(int* data, int* in, int tail);
void siftdown(int* data, int* in, int head, int tail);
int main()
{
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        // n Nodes, m Vertexes
        int n, m;
        cin >> n >> m;
        int graph[310][310] = {};
        int in[310] = {};
        int minheap[310] = {};
        int temp[310] = {};
        for (int j = 0;j <= n;j++)
        {
            minheap[j] = j;
        }
        for (int j = 1;j <= m;j++)
        {
            int u, v;
            cin >> u >> v;
            graph[u][v] = 1;
            in[v]++;
        }
        build(minheap, in, n);
        int count = 0;
        while (!in[minheap[1]])
        {
            temp[++count] = minheap[1];
            for (int j = 1;j <= n;j++)
            {
                if (graph[minheap[1]][j])
                {
                    in[j]--;
                    graph[minheap[1]][j] = 0;
                }
            }
            in[minheap[1]] = INT32_MAX;
            siftdown(minheap, in, 1, n);
        }
        if (count < n)
        {
            cout << 0 << endl;
        }
        else
        {
            for (int j = 1;j <= n;j++)
            {
                cout << temp[j] << " ";
            }
            cout << endl;
        }
    }
}
void build(int* data, int* in, int tail)
{
    for (int i = tail / 2; i >= 1;i--)
    {
        siftdown(data, in, i, tail);
    }
}
void siftdown(int* data, int* in, int head, int tail)
{
    if (head >= tail)
    {
        return;
    }
    if (head * 2 + 1 <= tail)
    {
        if (in[data[head]] > in[data[2 * head + 1]] || in[data[head]] > in[data[2 * head]])
        {
            if (in[data[head * 2 + 1]] < in[data[head * 2]])
            {
                swap(data[head], data[head * 2 + 1]);
                siftdown(data, in, head * 2 + 1, tail);
            }
            else
            {
                swap(data[head], data[2 * head]);
                siftdown(data, in, head * 2, tail);
            }
        }
    }
    else if (head * 2 <= tail)
    {
        if (in[data[head]] > in[data[head * 2]])
        {
            swap(data[head], data[head * 2]);
            siftdown(data, in, head * 2, tail);
        }
    }
}