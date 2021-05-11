#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// 如果每个活动的权重就是执行时间，那么只需要按照贪心算法按照
// 结束时间对活动进行排序，按次序选择结束时间最早的活动即可。
// 但是这题的活动有权重，所以要在前面的基础上用动态规划决定
// 选择哪些活动。
// 先对活动按照结束时间排序，设dp[i]是前i个活动的选择权重和最大的情况。
// 那么如果选择第i个活动，只有结束时间小于等于第i个活动开始时间的活动
// 可以执行，如果不选择，dp[i]=dp[i-1]
int main()
{
    int M;
    cin >> M;
    struct activity
    {
        activity()
        {

        }
        activity(int _start, int _end, int _weight)
            :start(_start), end(_end), weight(_weight)
        {}
        bool operator<(activity& right)
        {
            return end < right.end;
        }
        int start;
        int end;
        int weight;
    };
    for (int i = 0;i < M;i++)
    {
        vector<activity> temp(0);
        int N;
        cin >> N;
        vector<int> dp(N + 1);
        for (int j = 0;j < N;j++)
        {
            int s, f, v;
            cin >> s >> f >> v;
            temp.push_back(activity(s, f, v));
        }
        sort(temp.begin(), temp.end());
        dp[0] = temp[0].weight;
        for (int j = 1;j <= N;j++)
        {
            int choose = 0;
            for (int k = j - 1;k >= 0;k--)
            {
                if (temp[j].start < temp[0].end)
                {
                    choose = temp[j].weight;
                    break;
                }
                if (temp[j].start >= temp[k].end)
                {
                    choose = dp[k] + temp[j].weight;
                    break;
                }
            }
            dp[j] = max(dp[j - 1], choose);
        }
        cout << dp[N - 1] << endl;
    }
}