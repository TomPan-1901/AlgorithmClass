#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int m;
    cin >> m;
    for (int i = 0;i < m;i++)
    {
        char first[1000] = {};
        char second[1000] = {};
        int dp[1000][1000] = {};
        cin >> first >> second;
        int lfirst = strlen(first);
        int lsecond = strlen(second);
        int ptrf = 0, ptrs = 0;
        for (ptrf = 0;ptrf < lfirst;ptrf++)
        {
            for (ptrs = 0;ptrs < lsecond;ptrs++)
            {
                if (first[ptrf] == second[ptrs])
                {
                    if (ptrf != 0 && ptrs != 0)
                        dp[ptrf][ptrs] = dp[ptrf - 1][ptrs - 1] + 1;
                    else
                        dp[ptrf][ptrs] = 1;
                }
                else
                {
                    if (ptrf == 0 && ptrs == 0)
                        dp[ptrf][ptrs] = 0;
                    else if (ptrf == 0)
                        dp[ptrf][ptrs] = dp[ptrf][ptrs - 1];
                    else if (ptrs == 0)
                        dp[ptrf][ptrs] = dp[ptrf - 1][ptrs];
                    else
                        dp[ptrf][ptrs] = max(dp[ptrf - 1][ptrs], dp[ptrf][ptrs - 1]);
                }
                //cout << ptrf << " " << ptrs << " " << dp[ptrf][ptrs] << endl;
            }
        }
        cout << dp[lfirst - 1][lsecond - 1] << endl;
    }
}