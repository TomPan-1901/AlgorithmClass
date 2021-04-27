#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        int n;
        cin >> n;
        int data[20000] = {};
        int tag[20000] = {};
        for (int j = 0;j < 2 * n;j++)
        {
            cin >> data[j];
        }
        int k = 1;
        int result = 0;
        int total = 2 * n;
        while (k < 2 * n)
        {
            if (total == 0)
                break;
            for (int j = 0;j < 2 * n - k;j++)
            {
                if (!tag[j] && !tag[j + k] && (data[j] ^ data[j + k]))
                {
                    tag[j] = 1;
                    tag[j + k] = 1;
                    result += k;
                    total -= 2;
                }
            }
            k++;
        }
        cout << result << endl;
    }
}