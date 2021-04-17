#include <iostream>
using namespace std;
unsigned long long getnum(int*, int start, int stop);
unsigned long long solve(int*, int n, int k);
int main()
{
    int m;
    int nums[100][100];
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int n, k;
        cin >> n >> k;
        for (int j = 0;j < n;j++)
        {
            char temp;
            cin >> temp;
            nums[i][j] = (int)(temp - '0');
        }
        //cout << getnum(nums[i], 0, n - 1);
        solve(nums[i], n - 1, k);
    }
}
unsigned long long getnum(int* data, int start, int stop)
{
    if (start > stop)
        return 0;
    unsigned long long weight = 1;
    unsigned long long result = 0;
    for (int i = stop; i >= start;i--)
    {
        result += weight * data[i];
        weight *= 10;
    }
    return result;
}
unsigned long long solve(int* nums, int tail, int k)
{
    unsigned long long dp[40][6] = {};
    for (int i = 0;i <= tail;i++)
    {
        dp[i][0] = getnum(nums, 0, i);
    }
    for (int i = 1;i <= k;i++)
    {
        for (int j = i;j <= tail;j++)
        {
            for (int l = 0;l <= j - i;l++)
                dp[j][i] = max(dp[j][i], dp[j - l - 1][i - 1] * getnum(nums, j - l, j));
        }
    }
    cout << dp[tail][k] << endl;
    return dp[tail][k];
}