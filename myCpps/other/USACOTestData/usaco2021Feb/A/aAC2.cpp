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
        int n; cin >> n;
        
        int maxN = 0;
        vector<int> a(n, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];

            maxN = max(maxN, a[i]);
        }

        sort(a.begin(), a.end());

        int ans = 0;
        for (int x = 1; x <= maxN; ++x)
        {
            unordered_map<int, int> tMmp;
            
            int pos = upper_bound(a.begin(), a.end(), x - 1) - a.begin();
            for (int j = pos; j <= n - 1; ++j)
            {
                ++tMmp[a[j] / x];
            }

            vector<int> currOd;
            bool flg = true;
            for (auto pr:tMmp)
            {
                if (pr.first > 0)
                {
                    if (pr.second % 2 == 1)
                    {
                        if (currOd.size() == 2)
                        {
                            flg = false;
                            break;
                        }
                        currOd.push_back(pr.first);
                    }
                }
            }
            
            int add = 0;
            if (currOd.size() == 1)
            {
                if (currOd[0] != 1) flg = false;
                else add = tMmp[currOd[0]];
            }
            else if (currOd.size() == 2)
            {
                if (max(currOd[0], currOd[1]) == min(currOd[0], currOd[1]) + 1)
                {
                    flg = true;
                    add = tMmp[max(currOd[0], currOd[1])];
                }
                else  flg = false;
            }

            if (flg)
            {
                ans += add;
            }
        }

        cout << ans << '\n';
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
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