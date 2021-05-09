#include <iostream>
#include <algorithm>
using namespace std;
// 这题的本质就是找一个最长不增子序列，用动态规划解决
int main()
{
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int n;
        cin >> n;
        int temp[100];
        int dp[100] = {};
        // dp[i]表示以第i个数结尾的最大不增子序列的长度
        for (int j = 0;j < n;j++)
        {
            cin >> temp[j];
        }
        dp[0] = 1;
        for (int j = 1;j < n;j++)
        {
            dp[j] = 1;
            for (int k = j - 1;k >= 0;k--)
            {
                // 尝试把第j个数接在前面的不增子序列上，找到这个最大值
                if (temp[j] <= temp[k])
                {
                    dp[j] = max(dp[k] + 1, dp[j]);
                }
            }
        }
        int max = 0;
        for (int i = 0;i < n;i++)
        {
            if (dp[i] >= max)
            {
                max = dp[i];
            }
        }
        cout << max << endl;
    }
}