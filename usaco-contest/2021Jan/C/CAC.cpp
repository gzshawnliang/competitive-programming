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
    const int mod = 1e8 + 1;

    void solve()
    {
        int n, tolP, m; cin >> n >> tolP >> m;

        vector<pair<int, int>> prs(tolP);
        for (int i = 0; i <= tolP - 1; ++i)
        {
            cin >> prs[i].first >> prs[i].second;
        }

        vector<int> powN(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            powN[i] = (powN[i - 1] * n) % mod;
        }
        
        int stg = 0;
        vector<int> stgV(n + 1, 0);
        vector<set<int>> gone(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            stg = (stg + (i * powN[i])%mod) % mod;
            stgV[i] = i;

            gone[i].insert(i);
        }

        map<int, int> mp; mp[stg] = 1;
        for (int ip = 0; ip <= m - 1; ++ip)
        {
            //cout << stg << '\n';

            int pos1 = prs[ip % tolP].first, pos2 = prs[ip % tolP].second;

            stg = (stg - (stgV[pos1] * powN[pos1])%mod + mod)%mod;
            stg = (stg - (stgV[pos2] * powN[pos2])%mod + mod)%mod;
            stg = (stg + (stgV[pos2] * powN[pos1])%mod)%mod;
            stg = (stg + (stgV[pos1] * powN[pos2])%mod)%mod;

            swap(stgV[pos1], stgV[pos2]);

            for (int j = 1; j <= n; ++j)
            {
                gone[stgV[j]].insert(j);
            }

            if (mp.count(stg) > 0)
            {
                break;
            }
            mp[stg] = 1;
        }

        for (int i = 1; i <= n; ++i)
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