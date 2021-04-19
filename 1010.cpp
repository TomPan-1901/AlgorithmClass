#include <iostream>
using namespace std;
void search(int*, int left, int right, int target, int father);
int main()
{
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int n, target;
        cin >> n >> target;
        int data[100000];
        for (int j = 0;j < n;j++)
        {
            cin >> data[j];
        }
        int middle = (0 + n - 1) / 2;
        search(data, 0, n - 1, target, data[middle]);
    }
}
void search(int* data, int left, int right, int target, int father)
{
    if (right - left < 0)
    {
        cout << "not found, father is " << father << endl;
        return;
    }
    if (right - left == 0)
    {
        if (target == data[left])
        {
            cout << "success, father is " << father << endl;
        }
        else
        {
            cout << "not found, father is " << father << endl;
        }
        return;
    }
    int middle = (left + right) / 2;
    if (data[middle] == target)
    {
        cout << "success, father is " << father << endl;
        return;
    }
    else if (data[middle] > target)
    {
        search(data, left, middle, target, data[middle]);
    }
    else
    {
        search(data, middle + 1, right, target, data[middle]);
    }
    return;
}