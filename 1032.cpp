#include <iostream>
#include <cstdio>
using namespace std;
// 把概率加起来然后再加一，nt题目
int main()
{
    int T;
    cin >> T;
    for (int t = 0;t < T;t++)
    {
        int N;
        cin >> N;
        double result = 1.0;
        for (int i = 1;i <= N - 1;i++)
        {
            int temp;
            cin >> temp;
            result += double(temp) / 100.0;
        }
        printf("%.6f\n", result);
    }
}
