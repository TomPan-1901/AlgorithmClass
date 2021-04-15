#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int data[100][1000];
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        cin >> data[i][0];
        for (int j = 0;j < data[i][0];j++)
        {
            cin >> data[i][j + 1];
        }
        int mini = data[i][1];
        for (int j = 1;j <= data[i][0];j++)
        {
            if (data[i][j] < mini)
            {
                mini = data[i][j];
            }
        }
        int secmini = INT32_MAX;
        for (int j = 1;j <= data[i][0];j++)
        {
            if (data[i][j] > mini && data[i][j] < secmini)
            {
                secmini = data[i][j];
            }
        }
        cout << secmini << endl;
    }
}