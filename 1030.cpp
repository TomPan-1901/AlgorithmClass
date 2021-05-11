#include <iostream>
using namespace std;
// 本质是贪心，即每次选择两个距离最近的点相连，直到没有点可以相连
// 为止。用O(n^2)的算法会超时，这题需要用栈，按次序把某一种颜色的
// 点压入栈中，这时候新进来的不同颜色的点就会自然的和栈顶离这个点
// 最近的点配对。
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