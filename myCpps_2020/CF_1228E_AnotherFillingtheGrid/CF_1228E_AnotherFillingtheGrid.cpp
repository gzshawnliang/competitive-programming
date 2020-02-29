/*
===========================================================
* @Name:           1228E Another Filling the Grid
* @Author:         Shawn
* @create Time:    2020/3/1 0:20:24
* @url:            https://codeforces.com/contest/1228/problem/E
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
    ill n, k; cin >> n >> k;

    vector<vector<ill>> C(n + 1, vector<ill>(n + 1, 0)); C[0][0] = 1;
    for (ill i = 1; i <= n; ++i)
    {
        for (ill j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
        }
    }

    vector<ill> powK(n * n + 1, 1), powKm1(n * n + 1, 1);
    for (ill i = 1; i <= n * n; ++i)
    {
        powK[i] = (powK[i - 1] * k) % mod;
        powKm1[i] = (powKm1[i - 1] * (k - 1)) % mod;
    }

    ill ans = 0;
    vector<vector<ill>> f(n + 1, vector<ill>(n + 1, 1));
    for (ill cfy = 0; cfy <= n; ++cfy)
    {
        for (ill cfx = 0; cfx <= n; ++cfx)
        {
            ill totDelGrd = cfy * n + cfx * n - (cfy * cfx);

            f[cfy][cfx] = (f[cfy][cfx] * C[n][cfy]              ) % mod;
            f[cfy][cfx] = (f[cfy][cfx] * C[n][cfx]              ) % mod;
            f[cfy][cfx] = (f[cfy][cfx] * powKm1[totDelGrd]      ) % mod;
            f[cfy][cfx] = (f[cfy][cfx] * powK[n * n - totDelGrd]) % mod;

            if ((cfy + cfx) % 2 == 0) ans = (ans + f[cfy][cfx]      ) % mod;
            else                      ans = (ans + mod - f[cfy][cfx]) % mod;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1228E_AnotherFillingtheGrid.in", "r", stdin);
        freopen("CF_1228E_AnotherFillingtheGrid.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}