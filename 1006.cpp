#include <iostream>
using namespace std;
void build(int*, int);
void siftdown(int*, int, int);
int main()
{
    int m;
    cin >> m;
    int data[100][1000] = {};
    for (int i = 0;i < m;i++)
    {
        cin >> data[i][0];
        for (int j = 1;j <= data[i][0];j++)
        {
            cin >> data[i][j];
        }
        build(data[i], data[i][0]);
        for (int j = 1;j <= data[i][0];j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}
void build(int* data, int tail)
{
    for (int i = tail / 2; i >= 1;i--)
    {
        siftdown(data, i, tail);
    }
}
void siftdown(int* data, int head, int tail)
{
    if (head >= tail)
    {
        return;
    }
    if (head * 2 + 1 <= tail)
    {
        if (data[head] > data[2 * head + 1] || data[head] > data[2 * head])
        {
            if (data[head * 2 + 1] < data[head * 2])
            {
                swap(data[head], data[head * 2 + 1]);
                siftdown(data, head * 2 + 1, tail);
            }
            else
            {
                swap(data[head], data[2 * head]);
                siftdown(data, head * 2, tail);
            }
        }
    }
    else if (head * 2 <= tail)
    {
        if (data[head] > data[head * 2])
        {
            swap(data[head], data[head * 2]);
            siftdown(data, head * 2, tail);
        }
    }
}