#include <iostream>
#include <vector>
using namespace std;
/*

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
下面使用的是方法三。

*/
int superEggDrop(int k, int n) {
    if (n == 1) {
        return 1;
    }
    vector<vector<int>> f(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= k; ++i) {
        f[1][i] = 1;
    }
    int ans = -1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            f[i][j] = 1 + f[i - 1][j - 1] + f[i - 1][j];
        }
        if (f[i][k] >= n) {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    int T;
    cin >> T;
    for (int t = 0;t < T;t++)
    {
        int k, n;
        cin >> k >> n;
        cout << superEggDrop(k, n)<<endl;
    }
}