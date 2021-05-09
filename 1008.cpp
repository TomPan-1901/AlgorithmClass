#include <iostream>
#include <algorithm>
using namespace std;
// �����Ҫ������ϵͳ����ʹ��̰���㷨��������������
// һ��������
// 6 1 7 3 2
// ��⣺ 6 3 2/1/7 ʵ����ֻ��Ҫ6 1/7 3 2
// ʵ��������Dilworth�ָ���Ӧ�ã�����С����ת��Ϊ�������������
// �ĳ��ȡ�
// һ�����صĿ��ǣ�ÿһ��ϵͳһ���ܻ���ȵ�һ������Ҫ�͵����е�����
// ��������б����ߵĵ�������Ҫ�µ�ϵͳ�����Ծ��൱������֪���������
// �������С�
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