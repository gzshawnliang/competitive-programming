/*
-------------------------------------------------------------------
* @Name:           1490E Accidental Victory
* @Author:         Shawn
* @Create Time:    2021/2/16 22:35:16  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1490/problem/E
* @Description:    
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
*/

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
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;
            vector<pair<ill, ill>> a(n);
            for (ill i = 0; i <= n - 1; ++i)
            {
                cin >> a[i].first;
                a[i].second = i + 1;
            } 

            if (n == 1)
            {
                cout << "1\n1\n";
                continue;
            }

            sort(a.begin(), a.end());
            
            vector<ill> ans;
            ill sum = a[0].first, las = 0;
            for (ill i = 1; i <= n - 1; ++i)
            {
                if (sum < a[i].first)
                {
                    las = i;
                }

                sum += a[i].first;
            }

            set<ill> st;
            for (ill i = las; i <= n - 1; ++i) st.insert(a[i].second);

            cout << st.size() << '\n';
            for (auto x:st) cout << x << ' ';
            cout << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("CF_1490E_AccidentalVictory.in", "r", stdin);
    freopen("CF_1490E_AccidentalVictory.out", "w", stdout);
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