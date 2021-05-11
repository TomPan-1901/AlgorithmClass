#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<long long> q;
// 先按收益排序，倒序考虑，每次选出能在ddl前完成的任务，然后挑一个
// 收益最大的
typedef struct work
{
    long long time;
    long long value;
} work;
bool cmp(work A, work B)
{
    return A.time > B.time;
}

int main()
{
    long long t, i, j, n, m, k, l;
    cin >> t;
    for (int p = 0;p < t;p++)
    {
        work jobs[50005];
        q = priority_queue<long long>();
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> jobs[i].time >> jobs[i].value;
        }
        sort(jobs + 1, jobs + 1 + n, cmp);
        long long time_index = jobs[1].time;
        long long result = 0, work_index = 1;
        while (time_index)
        {
            while (jobs[work_index].time >= time_index && work_index <= n)
                q.push(jobs[work_index++].value);
            if (!q.empty())
            {
                result += q.top();
                q.pop();
            }
            time_index--;
        }
        cout << result << endl;
    }

    return 0;
}