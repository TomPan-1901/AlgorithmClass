#include <iostream>
#include <algorithm>
using namespace std;
// ����ı��ʾ�����һ������������У��ö�̬�滮���
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
        // dp[i]��ʾ�Ե�i������β������������еĳ���
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
                // ���԰ѵ�j��������ǰ��Ĳ����������ϣ��ҵ�������ֵ
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