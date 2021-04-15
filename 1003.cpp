#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int data[100][1000];
    for (int i = 0;i < m;i++)
    {
        cin >> data[i][0];
        for (int j = 1;j <= data[i][0];j++)
        {
            cin >> data[i][j];
        }
        for (int j = 1;j < data[i][0];j++)
        {
            if (data[i][j] > data[i][j + 1])
            {
                swap(data[i][j], data[i][j + 1]);
            }
        }
        for (int j = 1;j <= data[i][0];j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}