#include <cstring>
#include <iostream>
using namespace std;
// KMP水题
int main()
{
    int T;
    cin >> T;
    for (int i = 0;i < T;i++)
    {
        int n, m;
        cin >> n >> m;
        char str1[1000000] = {};
        char str2[1000000] = {};
        for (int j = 0;j < n;j++)
        {
            cin >> str1[j];
        }
        for (int j = 0;j < m;j++)
        {
            cin >> str2[j];
        }
        int count = 0;
        char* haystack = str1;
        char* needle = str2;
        while (haystack = strstr(haystack, needle))
        {
            haystack += 1;
            count++;
        }
        cout << count << endl;
    }
}