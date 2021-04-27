#include <iostream>
#include <algorithm>
using namespace std;
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