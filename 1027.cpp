#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
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