#include <iostream>
using namespace std;
void midsearch(int left, int right, int target, int father, int* data);
int main()
{
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int n, x;
        cin >> n >> x;
        int data[20010];
        for (int j = 0;j < n;j++)
        {
            cin >> data[j];
        }
        midsearch(0, n - 1, x, data[(n - 1) / 2], data);
    }
}
void midsearch(int left, int right, int target, int father, int* data)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (data[mid] == target)
        {
            cout << "success, father is " << father << endl;
            return;
        }
        else if (data[mid] > target)
        {
            midsearch(left, mid - 1, target, data[mid], data);
        }
        else
        {
            midsearch(mid + 1, right, target, data[mid], data);
        }
    }
    else
    {
        cout << "not found, father is " << father << endl;
    }
    return;
}