#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int n;
        cin >> n;
        int matrix[1000][2] = {};
        for (int j = 0;j < n;j++)
        {
            cin >> matrix[j][0] >> matrix[j][1];
        }
        int dp[1000][1000] = {};
        int k = 1;
        while (k < n)
        {
            for (int j = 0;j < n - k;j++)
            {
                if (k == 1)
                {
                    dp[j][j + k] = matrix[j][0] * matrix[j][1] * matrix[j + k][1];
                }
                else
                {
                    int min = INT32_MAX;
                    for (int split = j;split < j + k;split++)
                    {
                        if (min > (dp[j][split] + dp[split + 1][j + k] + matrix[j][0] * matrix[split + 1][1] * matrix[j + k][1]))
                        {
                            min = dp[j][split] + dp[split + 1][j + k] + matrix[j][0] * matrix[split + 1][0] * matrix[j + k][1];
                        }
                    }
                    dp[j][j + k] = min;
                }
            }
            k++;
        }
        cout << dp[0][n - 1] << endl;
    }
}