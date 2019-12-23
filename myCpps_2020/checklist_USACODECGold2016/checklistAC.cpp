#include <bits/stdc++.h>

using namespace std;

ifstream fin("checklist.in");
ofstream fout("checklist.out");

using ll = long long;

const ll inf = LLONG_MAX / 4;

//vector<ll> dp[1005][1005];

ll disp2(pair<ll, ll> & a, pair<ll, ll> & b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
    ll n, m; fin >> n >> m;

    pair<ll, ll> pinf = make_pair(inf, inf);
    vector<pair<ll, ll>> H(n + 1, pinf), G(m + 1, pinf);
    
    for (ll i = 1; i <= n; ++i)
    {
        fin >> H[i].first >> H[i].second;
    }
    if (n == 1)
    {
        H.push_back(H[0]);
        ++n;
    }

    for (ll i = 1; i <= m; ++i)
    {
        fin >> G[i].first >> G[i].second;
    }
    
    vector<vector<vector<ll>>> dp(n + 5, vector<vector<ll>>(m + 5, vector<ll>(2, inf)));
    dp[1][0][0] = 0;

    for (ll i = 0; i <= n; ++i)
    {
        for (ll j = 0; j <= m; ++j)
        {
            for (ll k = 0; k <= 1; ++k)
            {
                if (dp[i][j][k] == inf) continue;

                if (i == 1 && j == 2 && k == 1)
                {
                    for (ll __s = 0; __s == 0; ++__s);
                }

                pair<ll, ll> last;
                if (k == 0)
                {
                    last = H[i];
                }
                else
                {
                    last = G[j];
                }

                if (i <= n - 1) dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + disp2(last, H[i + 1]));
                if (j <= m - 1) dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + disp2(last, G[j + 1]));
            }
        }
    }

    // for (ll i = 0; i <= n; ++i)
    // {
    //     for (ll j = 0; j <= m; ++j)
    //     {
    //         for (ll k = 0; k <= 1; ++k)
    //         {
    //             if (dp[i][j][k] < inf)
    //             {
    //                 fout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << '\n';
    //             }
    //         }
    //     }
    // }

    fout << dp[n][m][0] << '\n';

    return 0;
}
