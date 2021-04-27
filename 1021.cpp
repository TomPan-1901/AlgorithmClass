#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int table[20000][2] = {};
    int dp[20000] = {};
    for (int i = 0;i < m;i++)
    {
        int n, k;
        cin >> n >> k;
        for (int j = 1;j <= k;j++)
        {
            cin >> table[j][0] >> table[j][1];
        }
        for (int j = 1;j <= n;j++)
        {
            int maxi = 0;
            for (int m = 1;m <= k;m++)
            {
                if (j >= table[m][0])
                {
                    if(maxi<dp[j-table[m][0]]+table[m][1])
                    {
                        maxi = dp[j - table[m][0]] + table[m][1];
                    }
                }
                dp[j] = maxi;
            }
        }
        cout << dp[n] << endl;
    }
}