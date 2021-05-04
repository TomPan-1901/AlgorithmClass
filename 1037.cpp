#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for (int i = 0;i < T;i++)
    {
        int male[60][20];
        int mark[60] = {};
        int n, m;
        unsigned int result = 0;
        cin >> n >> m;
        for (int j = 1;j <= n;j++)
        {
            int k;
            cin >> k;
            for (int l = 1;l <= k;l++)
            {
                cin >> male[j][l];
            }
            for (int l = 1;l <= k;l++)
            {
                if (!mark[male[j][l]])
                {
                    mark[male[j][l]] = 1;
                    result += 1;
                    break;
                }
            }
        }
        cout << result << endl;
    }
}