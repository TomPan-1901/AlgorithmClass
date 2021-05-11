#include <cstdio>
#include <iostream>
using namespace std;
// 这题使用了匈牙利算法，代码比较简洁，和直接使用网络流相比
bool match(int i, int N, int* p, bool* vis, int Map[51][51])
{
    for (int j = 1; j <= N; ++j)
        if (Map[i][j] && !vis[j])
        {
            vis[j] = true;
            if (p[j] == 0 || match(p[j], N, p, vis, Map))
            {
                p[j] = i;
                return true;
            }
        }
    return false;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 0;t < T;t++)
    {
        int n, m;
        cin >> n >> m;
        int Map[51][51] = {};
        for (int i = 1;i <= n;i++)
        {
            int k;
            cin >> k;
            for (int j = 0;j < k;j++)
            {
                int l;
                cin >> l;
                Map[i][l] = 1;
            }
        }
        int p[51] = {};
        int result = 0;
        for (int i = 1;i <= n;i++)
        {
            bool vis[51] = {};
            if (match(i, m, p, vis, Map))
            {
                result++;
            }
        }
        cout << result << endl;
    }
}
