#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int nums;
    cin >> nums;
    cout.precision(5);
    cout.setf(ios::fixed); // 设置为小数位始终有 6 位，没有这个的话就会像上面那个代码那样固定的不是小数点后面的数字了。
    for (int i = 0;i < nums;i++)
    {
        int nums1[1010];
        int nums2[1010];
        int result[2020];
        int n, m;
        cin >> n >> m;
        for (int j = 0;j < n;j++)
        {
            cin >> nums1[j];
        }
        for (int j = 0;j < m;j++)
        {
            cin >> nums2[j];
        }
        if (n == 0)
        {
            if (m % 2)
            {
                cout << double(nums2[m / 2]) << endl;
            }
            else
            {
                cout << (double(nums2[m / 2]) + double(nums2[m / 2 - 1])) / 2.0 << endl;
            }
            continue;
        }
        if (m == 0)
        {
            if (n % 2)
            {
                cout << double(nums1[n / 2]) << endl;
            }
            else
            {
                cout << (double(nums1[n / 2]) + double(nums1[n / 2 - 1])) / 2.0 << endl;
            }
            continue;
        }
        int ptr1 = 0, ptr2 = 0;
        int resultptr = 0;
        while (ptr1 < n && ptr2 < m)
        {
            if (nums1[ptr1] < nums2[ptr2])
            {
                result[resultptr++] = nums1[ptr1++];
            }
            else
            {
                result[resultptr++] = nums2[ptr2++];
            }
        }
        while (ptr1 < m)
        {
            result[resultptr++] = nums1[ptr1++];
        }
        while (ptr2 < n)
        {
            result[resultptr++] = nums2[ptr2++];
        }
        if ((m + n) % 2)
        {
            cout << setprecision(5) << double(result[(m + n) / 2]) << endl;
        }
        else
        {
            cout << (double(result[(m + n) / 2]) + double(result[(m + n) / 2 - 1])) / 2.0 << endl;
        }
    }
}