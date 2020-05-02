/*
===========================================================
* @Name:           1348E Phoenix and Berries
* @Author:         Shawn
* @create Time:    2020/5/1 22:35:42
* @url:            https://codeforces.com/contest/1348/problem/E
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

void solve()
{
    ill n, k; cin >> n >> k;

    ill tolF = 0;
    vector<pair<ill, ill>> bushes(n + 1);
    for (ill i = 1; i <= n; ++i)
    {
        cin >> bushes[i].first >> bushes[i].second;
        tolF += bushes[i].first; tolF += bushes[i].second;
    }

    vector<vector<ill>> f(n + 1, vector<ill>(k, 0));

    f[0][0] = 1;
    for (ill i = 1; i <= n; ++i)
    {
        for (ill j = 0; j <= k - 1; ++j)
        {
            f[i][j] = f[i - 1][(j - bushes[i].first % k + k) % k];

            for (ill p = 0; p <= bushes[i].first && p <= k - 1; ++p)
            {
                if ((bushes[i].first - p) % k >= k - bushes[i].second && f[i - 1][(j - p + k) % k])
                {
                    f[i][j] = 1;
                }
            }
        }
    }

    ill ans = 0;
    for (ill j = 0; j <= k - 1; ++j)
    {
        if (f[n][j] == 1) ans = max(ans, (tolF - j) / k);
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1348E_PhoenixandBerries.in", "r", stdin);
        freopen("CF_1348E_PhoenixandBerries.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}