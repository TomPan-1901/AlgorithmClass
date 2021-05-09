#include <iostream>
#include <cstdio>
using namespace std;
void mysort(int*, int*, int, int, int&);
int main()
{
    int m;
    scanf("%d", &m);
    int buf[50000];
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
        mysort(temp, buf, 0, n - 1, result);
        printf("%d", result);
    }
}
// 用暴力方法做会超时，需要使用归并排序，在排序的过程中求出逆序数
// 有两个考虑角度，以下面的归并过程为例，假设有两个已经排序的序列等待
// 合并，分别是L={8, 12, 16, 22, 100}和R={9, 26, 55, 64, 91}，在
// 归并的过程中如果碰到左指针的数比右指针的数大，假设现在左指针指向12，
// 右指针指向9，我们既可以认为是12排在9后面贡献了一个逆序，也可以认为是
// 9排在12, 16, 22, 100后面贡献了4个逆序，不难验证这两种思路最后得到的
// 结果是一样的。
void mysort(int* data, int* temp, int head, int tail, int& count)
{
    if (head >= tail)
        return;
    int middle = (head + tail) >> 1;
    mysort(data, temp, head, middle, count);
    mysort(data, temp, middle + 1, tail, count);
    int leftptr = head;
    int rightptr = middle + 1;
    int tempptr = head;
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