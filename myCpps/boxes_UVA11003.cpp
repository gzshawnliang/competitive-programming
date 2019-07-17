#include <bits/stdc++.h>

using namespace std;

ifstream fin("boxes_UVA11003.in");
ofstream fout("boxes_UVA11003.out");

const int inf = INT_MAX / 2;
const int N = 6005;

struct box
{
    int m;
    int l;
};
box _box(int m, int l)
{
    box temp{m, l}; return temp;
}

int main()
{   
    int o=1;
    while (true)
    {

        int n = 0; fin >> n;
        if (n == 0) break;

        if(o==135)
        {
            break;
        }
        ++o;
        vector<box> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i].m >> a[i].l;
        }
        
        int ans = 1;
        vector<vector<int>> dp(n, vector<int>(N + 1, -1 * inf)); dp[n - 1][a[n - 1].m] = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 0; j <= N; ++j)
            {
                dp[i][a[i].m] = 1;
                if (a[i].l >= j - a[i].m && j >= a[i].m)
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - a[i].m] + 1);
                }
                else
                {
                    dp[i][j] = dp[i + 1][j];
                }

                ans = max(ans, dp[i][j]);
            }
        }

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = a[i].m; j <= N; ++j)
            {
                if (dp[i][j] >= 0)
                {
                    fout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
                }
            }
        }

        fout << ans << '\n';
    }

    return 0;
}
