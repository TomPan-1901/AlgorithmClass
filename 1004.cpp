#include <iostream>
#include <algorithm>
using namespace std;
void sort(int*, int, int, int);
int main()
{
    int data[100][1000];
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        cin >> data[i][0];
        for (int j = 1;j <= data[i][0];j++)
        {
            cin >> data[i][j];
        }

    }
}
void sort(int* data, int head, int tail, int level)
{
    if (head >= tail)
        return;

}