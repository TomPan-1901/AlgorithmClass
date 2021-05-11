#include <iostream>
#include <algorithm>
using namespace std;
// 0/1背包问题可以用动态规划在伪多项式时间内解决。
int main()
{
    int m;
    cin >> m;
    int dp[500][200] = {};
    int data[500][2] = {};
    for (int i = 0;i < m;i++)
    {
        int n, c;
        cin >> n >> c;
        for (int j = 1;j <= n;j++)
        {
            cin >> data[j][0] >> data[j][1];
        }
        for (int k = 1;k <= n;k++)
        {
            for (int l = 0;l <= c;l++)
            {
                if (l >= data[k][0])
                    dp[k][l] = max(dp[k - 1][l], dp[k - 1][l - data[k][0]] + data[k][1]);
                else
                    dp[k][l] = dp[k - 1][l];
            }
        }
        cout << dp[n][c] << endl;
    }
}