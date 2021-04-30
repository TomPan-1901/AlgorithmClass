#include <iostream>
using namespace std;
int solve(int curm, int curn, int m, int n, int data[500][500]);
int main()
{
    int x;
    cin >> x;
    for (int i = 0;i < x;i++)
    {
        int m, n, target;
        cin >> m >> n >> target;
        int data[1000][1000];
        for (int j = 0;j < m;j++)
        {
            for (int k = 0;k < n;k++)
            {
                cin >> data[j][k];
            }
        }
        int curm = m - 1, j = 0;
        int flag = 1;
        while (curm >= 0 && j < n)
        {
            if (data[curm][j] > target) curm--;
            else if (data[curm][j] < target) j++;
            else
            {
                cout << "true" << endl;
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "false" << endl;
    }
}