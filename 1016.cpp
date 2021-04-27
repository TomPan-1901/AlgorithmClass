#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int n, x;
        cin >> n >> x;
        int hash[50000] = {};
        int data[50000];
        // data%49201
        for (int j = 0;j < n;j++)
        {
            cin >> data[j];
            if (!hash[data[j] % 49201])
                hash[data[j] % 49201] = data[j];
            else
            {
                int k = data[j] % 49201;
                while (hash[k++]);
                hash[k] = data[j];
            }
        }
        int flag = 1;
        for (int j = 0;j < n;j++)
        {
            int k = (x - data[j]) % 49201;
            while (hash[k] != x - data[j] && hash[k])
            {
                k++;
            }
            if (hash[k])
            {
                flag = 0;
                cout << "yes" << endl;
                break;
            }
        }
        if (flag)
            cout << "no" << endl;
    }
}