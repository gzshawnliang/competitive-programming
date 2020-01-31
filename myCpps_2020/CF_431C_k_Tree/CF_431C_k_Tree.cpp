/*
===========================================================
* @Name:           431C k-Tree
* @Author:         Shawn
* @create Time:    2020/1/31 23:48:00
* @url:            https://codeforces.com/contest/431/problem/C
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;
using ill = long long;

const ill mod = 1e9 + 7;

void solve()
{
    ill n, k, d; cin >> n >> k >> d;

    vector<vector<vector<ill>>> f(n + 1, vector<vector<ill>>(n + 1, vector<ill>(2, 0)));
    f[0][0][0] = 1;

    ill ans = 0;
    for (ill dep = 1; dep <= n; ++dep)
    {
        for (ill i = 0; i <= n; ++i)
        {
            if (f[dep - 1][i][0] > 0 || f[dep - 1][i][1] > 0)
            {
                for (ill w = 1; w <= k && i + w <= n; ++w)
                {
                    if (w >= d)
                    {
                        f[dep][i + w][1] += (f[dep - 1][i][0] + f[dep - 1][i][1]);
                    }
                    else
                    {
                        f[dep][i + w][0] += f[dep - 1][i][0];
                        f[dep][i + w][1] += f[dep - 1][i][1];
                    }

                    f[dep][i + w][0] %= mod;
                    f[dep][i + w][1] %= mod;
                }
            }
        }

        ans = (ans + f[dep][n][1]) % mod; 
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE    //Submit to OJ in standard input/output,debug in local .in/.out file
        freopen("CF_431C_k_Tree.in", "r", stdin);
        freopen("CF_431C_k_Tree.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}