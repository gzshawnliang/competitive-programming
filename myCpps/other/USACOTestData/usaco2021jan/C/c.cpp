#ifndef LOCAL_DEBUG
#define NDEBUG //ban assert when submit to online judge
#endif

#ifdef LOCAL_DEBUG
#include <chrono>
#endif

#include <bits/stdc++.h>

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr)

using namespace std;

using ill = long long;

class solution
{
  public:
    const ill mod = 100000000743856857uLL;

    void solve()
    {
        ill n, tolP, m; cin >> n >> tolP >> m;

        vector<pair<ill, ill>> prs(tolP);
        for (ill i = 0; i <= tolP - 1; ++i)
        {
            cin >> prs[i].first >> prs[i].second;
        }

        vector<ill> powN(n + 1, 1);
        for (ill i = 1; i <= n; ++i)
        {
            powN[i] = (powN[i - 1] * n) % mod;
        }
        
        ill stg = 0;
        vector<ill> stgV(n + 1, 0);
        vector<unordered_set<ill>> gone(n + 1);
        for (ill i = 1; i <= n; ++i)
        {
            stg = (stg + (i * powN[i])%mod) % mod;
            stgV[i] = i;

            gone[i].insert(i);
        }

        unordered_map<ill, ill> mp; mp[stg] = 1;
        for (ill ip = 0; ip <= m - 1; ++ip)
        {
            //cout << stg << '\n';

            ill pos1 = prs[ip % tolP].first, pos2 = prs[ip % tolP].second;

            stg = (stg - (stgV[pos1] * powN[pos1])%mod + mod * mod)%mod;
            stg = (stg - (stgV[pos2] * powN[pos2])%mod + mod)%mod;
            stg = (stg + (stgV[pos2] * powN[pos1])%mod)%mod;
            stg = (stg + (stgV[pos1] * powN[pos2])%mod)%mod;

            gone[stgV[pos1]].insert(pos2);
            gone[stgV[pos2]].insert(pos1);

            swap(stgV[pos1], stgV[pos2]);

            if (mp.count(stg) > 0)
            {
                break;
            }
            mp[stg] = 1;
        }

        for (ill i = 1; i <= n; ++i)
        {
            cout << gone[i].size() << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    auto startTime = chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifdef LOCAL_DEBUG
    cerr << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - startTime).count()
         << " ms\n";
#endif

    return 0;
}