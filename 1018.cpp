#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int data[510][2] = {};
    int dp[510][200] = {};
    for (int i = 0;i < 510;i++)
    {
        for (int j = 0;j < 200;j++)
        {
            dp[i][j] = INT16_MIN;
        }
    }
    dp[0][0] = 0;
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
        if (dp[n][c] >= 0)
            cout << dp[n][c] << endl;
        else
        {
            cout << "0" << endl;
        }
    }
}