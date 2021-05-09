#include <iostream>
#include <algorithm>
using namespace std;
void mysort(int*, int, int, int);
int main()
{
    int data[100][1000];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> data[i][j];
        }
        mysort(data[i], 0, n - 1, 1);
        cout << endl;
    }
}
void mysort(int* data, int head, int tail, int level)
{
    if (head >= tail)
        return;
    // 先对分开的两段排序
    int middle = (head + tail) / 2;
    mysort(data, head, middle, level + 1);
    mysort(data, middle + 1, tail, level + 1);
    // 归并
    int leftptr = head;
    int rightptr = middle + 1;
    int tempptr = head;
    int temp[1000] = {};
    while (leftptr <= middle && rightptr <= tail)
    {
        if (data[leftptr] <= data[rightptr])
        {
            temp[tempptr++] = data[leftptr++];
        }
        else
        {
            temp[tempptr++] = data[rightptr++];
        }
    }
    // 跳出上面的while循环至少要left>mid或者right>tail，
    // 所以下面的两段代码至多只有一段执行
    while (leftptr <= middle)
    {
        temp[tempptr++] = data[leftptr++];
    }
    while (rightptr <= tail)
    {
        temp[tempptr++] = data[rightptr++];
    }
    // 只要是第三层的就输出自己，因为递归是按从左到右的顺序进行，
    // 所以打印出来恰好就是需要的结果
    for (int i = head;i <= tail;i++)
    {
        data[i] = temp[i];
        if (level == 3)
        {
            cout << data[i] << " ";
        }
    }
}