#include <iostream>
#include <cstdio>
using namespace std;
void mysort(int*, int, int, int&);
int main()
{
    int m;
    scanf("%d", &m);
    for (int i = 0;i < m;i++)
    {
        int n;
        scanf("%d", &n);
        int temp[50000] = {};
        for (int j = 0;j < n;j++)
        {
            scanf("%d", &temp[j]);
        }
        int result = 0;
        mysort(temp, 0, n - 1, result);
        printf("%d", result);
    }
}
void mysort(int* data, int head, int tail, int& count)
{
    if (head >= tail)
        return;
    int middle = (head + tail) >> 1;
    mysort(data, head, middle, count);
    mysort(data, middle + 1, tail, count);
    int leftptr = head;
    int rightptr = middle + 1;
    int tempptr = head;
    int temp[50000] = {};
    while (leftptr <= middle && rightptr <= tail)
    {
        if (data[leftptr] <= data[rightptr])
        {
            temp[tempptr++] = data[leftptr++];
        }
        else
        {
            count += middle - leftptr + 1;
            temp[tempptr++] = data[rightptr++];
        }
    }
    while (leftptr <= middle)
    {
        temp[tempptr++] = data[leftptr++];
    }
    while (rightptr <= tail)
    {
        temp[tempptr++] = data[rightptr++];
    }
    for (int i = head;i <= tail;i++)
    {
        data[i] = temp[i];
    }
    return;
}