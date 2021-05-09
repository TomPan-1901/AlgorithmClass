#include <iostream>
#include <algorithm>
using namespace std;
// 最多需要的拦截系统不能使用贪心算法解决，下面给出了
// 一个反例。
// 6 1 7 3 2
// 错解： 6 3 2/1/7 实际上只需要6 1/7 3 2
// 实际上这是Dilworth分割定理的应用，将最小划分转化为求最长递增子序列
// 的长度。
// 一个朴素的考虑：每一套系统一定能击落比第一发导弹要低的所有导弹，
// 如果后面有比它高的导弹就需要新的系统，所以就相当于在已知序列里找最长
// 上升序列。
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
        int L[100] = {};
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
                if (temp[j] <= temp[k])
                {
                    dp[j] = max(dp[k] + 1, dp[j]);
                }
            }
        }
        int maxi = 0;
        for (int i = 0;i < n;i++)
        {
            if (dp[i] >= maxi)
            {
                maxi = dp[i];
            }
        }
        cout << maxi << " ";
        dp[0] = 1;
        for (int j = 1;j < n;j++)
        {
            dp[j] = 1;
            for (int k = j - 1;k >= 0;k--)
            {
                if (temp[j] > temp[k])
                {
                    dp[j] = max(dp[k] + 1, dp[j]);
                }
            }
        }
        int mini = 0;
        for (int i = 0;i < n;i++)
        {
            if (dp[i] >= mini)
            {
                mini = dp[i];
            }
        }
        cout << mini << endl;

    }
}