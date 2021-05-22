#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int t = 0;t < T;t++)
    {
        int m;
        int days[366] = {};
        int dp[366] = {};
        int costs[3] = {};
        cin >> m;
        for (int i = 0;i < m;i++)
        {
            int temp;
            cin >> temp;
            days[temp] = 1;
        }
        cin >> costs[0] >> costs[1] >> costs[2];
        for (int i = 1;i <= 365;i++)
        {
            if (!days[i])
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                if (i >= 30)
                {
                    dp[i] = min(min(dp[i - 1] + costs[0],
                        dp[i - 7] + costs[1]), dp[i - 30] + costs[2]);
                }
                else if (i >= 7)
                {
                    dp[i] = min(min(dp[i - 1] + costs[0],
                        dp[i - 7] + costs[1]), dp[0] + costs[2]);
                }
                else
                {
                    dp[i] = min(min(dp[i - 1] + costs[0],
                        dp[0] + costs[1]), dp[0] + costs[2]);
                }
            }
        }
        cout << dp[365] << endl;
    }
}