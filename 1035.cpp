#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int t = 0;t < T;t++)
    {
        int N;
        cin >> N;
        vector<unsigned long long> c(N);
        vector<unsigned long long> y(N);
        for (int i = 0;i < N;i++)
        {
            cin >> c[i];
        }
        for (int i = 0;i < N;i++)
        {
            cin >> y[i];
        }
        unsigned long long result = 0;
        for (int i = 0;i < N;i++)
        {
            if (i)
            {
                c[i] = min(c[i], c[i - 1] + 1);
            }
            result += c[i] * y[i];
        }
        cout << result << endl;
    }
}