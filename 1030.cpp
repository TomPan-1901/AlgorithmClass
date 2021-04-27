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
        int stack[10000];
        int top = 0;
        int result = 0;
        int color_in_stack;
        int temp;
        cin >> temp;
        color_in_stack = temp;
        stack[top++] = 0;
        for (int j = 1;j < 2 * n;j++)
        {
            cin >> temp;
            if (temp == color_in_stack && top)
            {
                stack[top++] = j;
            }
            else
            {
                if (top)
                {
                    result += j - stack[--top];
                }
                else
                {
                    color_in_stack = temp;
                    stack[top++] = j;
                }
            }
        }
        cout << result << endl;
    }
}