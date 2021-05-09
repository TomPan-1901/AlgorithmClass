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
    // �ȶԷֿ�����������
    int middle = (head + tail) / 2;
    mysort(data, head, middle, level + 1);
    mysort(data, middle + 1, tail, level + 1);
    // �鲢
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
    // ���������whileѭ������Ҫleft>mid����right>tail��
    // ������������δ�������ֻ��һ��ִ��
    while (leftptr <= middle)
    {
        temp[tempptr++] = data[leftptr++];
    }
    while (rightptr <= tail)
    {
        temp[tempptr++] = data[rightptr++];
    }
    // ֻҪ�ǵ�����ľ�����Լ�����Ϊ�ݹ��ǰ������ҵ�˳����У�
    // ���Դ�ӡ����ǡ�þ�����Ҫ�Ľ��
    for (int i = head;i <= tail;i++)
    {
        data[i] = temp[i];
        if (level == 3)
        {
            cout << data[i] << " ";
        }
    }
}