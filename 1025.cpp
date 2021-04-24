#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int n;
        cin >> n;
        int temp[10010] = {};
        int dp[10010] = {};
        for (int j = 0;j < n;j++)
        {
            cin >> temp[j];
            int maxi = 1;
            for (int k = 0;k < j;k++)
            {
                if (temp[j] >= temp[k])
                {
                    if (dp[k] + 1 > maxi)
                    {
                        maxi = dp[k] + 1;
                    }
                }
            }
            dp[j] = maxi;
        }
        int maxi = 1;
        for (int j = 0;j < n;j++)
        {
            if (dp[j] > maxi)
            {
                maxi = dp[j];
            }
        }
        cout << maxi << endl;
    }
}