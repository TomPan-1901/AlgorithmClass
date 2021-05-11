#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// ���ÿ�����Ȩ�ؾ���ִ��ʱ�䣬��ôֻ��Ҫ����̰���㷨����
// ����ʱ��Ի�������򣬰�����ѡ�����ʱ������Ļ���ɡ�
// ��������Ļ��Ȩ�أ�����Ҫ��ǰ��Ļ������ö�̬�滮����
// ѡ����Щ���
// �ȶԻ���ս���ʱ��������dp[i]��ǰi�����ѡ��Ȩ�غ����������
// ��ô���ѡ���i�����ֻ�н���ʱ��С�ڵ��ڵ�i�����ʼʱ��Ļ
// ����ִ�У������ѡ��dp[i]=dp[i-1]
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