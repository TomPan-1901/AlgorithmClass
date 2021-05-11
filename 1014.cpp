#include <iostream>
#include <algorithm>
using namespace std;
// 本题可以用滑动窗口和动态规划两种方法，这里用动态规划实现。
// 思路：设dp[i]是以temp[i]结尾的，具有最大和的子数组。
// 如果dp[i-1]大于0，temp[i]+dp[i-1]是增大的，从而dp[i]=dp[i-1]
// +temp[i]，如果小于等于0，dp[i]=temp[i]
int solve(int*, int* dp, int n);
int main()
{
    int m;
    cin >> m;
    int dp[50000];
    int temp[50000];
    for (int i = 0;i < m;i++)
    {
        int n;
        cin >> n;
        for (int j = 0;j < n;j++)
        {
            cin >> temp[j];
        }
        cout << solve(temp, dp, n) << endl;
    }
}
int solve(int* temp, int* dp, int n)
{
    dp[0] = temp[0];
    for (int i = 1;i < n;i++)
    {
        if (dp[i - 1] > 0)
        {
            dp[i] = dp[i - 1] + temp[i];
        }
        else
        {
            dp[i] = temp[i];
        }
    }
    int max = INT32_MIN;
    for (int i = 0;i < n;i++)
    {
        if (dp[i] > max)
        {
            max = dp[i];
        }
    }
    return max;
}