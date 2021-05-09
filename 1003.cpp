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
        // 从前往后扫描，碰到比自己大的数就交换
        for (int j = 1;j < data[i][0];j++)
        {
            if (data[i][j] > data[i][j + 1])
            {
                swap(data[i][j], data[i][j + 1]);
            }
        }
        // 输出第一遍扫描的结果
        for (int j = 1;j <= data[i][0];j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}