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
    const int mod = 1e7 + 1;

    void solve()
    {
        int n, tolP, m; cin >> n >> tolP >> m;

        vector<pair<int, int>> prs(tolP);
        for (int i = 0; i <= tolP - 1; ++i)
        {
            cin >> prs[i].first >> prs[i].second;
        }
        
        vector<int> stg(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            stg[i] = i;
            //pth[i].push_back(i);
        }

        //int fin = 0;
        map<string, int> mp;
        for (int i = 0; i <= 100; ++i)
        {
            string tmp = "";
            for (int id = 1; id <= n; ++id)
            {
                if (id > 0) cout << ' ';
                cout << stg[id];

                tmp = tmp + "|" + to_string(stg[id]);
            }
            cout << '\n';

            if (mp.count(tmp) > 0)
            {
                break;
            }
            mp[tmp] = 1;

            pair<int, int> p = prs[i % tolP];
            swap(stg[p.first], stg[p.second]);
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