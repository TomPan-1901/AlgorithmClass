#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
    int M;
    cin >> M;
    for (int z = 0;z < M;z++)
    {
        int N;
        cin >> N;
        double p[550] = {};
        double q[550] = {};
        double e[550][550] = {};
        double w[550][550] = {};
        for (int i = 0;i < N;i++)
        {
            int temp;
            cin >> temp;
        }
        for (int i = 1;i <= N;i++)
        {
            cin >> p[i];
        }
        double sum = 0.0;
        for (int i = 0;i <= N;i++)
        {
            cin >> q[i];
            sum += q[i];
        }
        for (int i = 1;i <= N + 1;i++)
        {
            e[i][i - 1] = q[i - 1];
            w[i][i - 1] = q[i - 1];
        }
        for (int l = 1;l <= N;l++)
        {
            for (int i = 1;i <= N - l + 1;i++)
            {
                int j = i + l - 1;
                e[i][j] = 999999.0;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                for (int r = i;r <= j;r++)
                {
                    double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                    if (t < e[i][j])
                    {
                        e[i][j] = t;
                    }
                }
            }
        }
        printf("%.6f\n", e[1][N] - sum);
    }
}