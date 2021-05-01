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
        cout << fixed << setprecision(8);

        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, rg; cin >> n >> rg;
            set<ill> a;
            for (int c = 1; c <= n; ++c)
            {
                ill tmp; cin >> tmp;
                a.insert(tmp);
            }
            a.insert(0); a.insert(rg + 1);

            vector<ill> allP, allD;
            for (auto x:a) allP.push_back(x);

            ill larV = 0LL;
            for (int i = 1, siz = allP.size(); i <= siz - 1; ++i)
            {
                ill dif = allP[i] - allP[i - 1] - 1;
                if (i == 1 || i == siz - 1)
                {
                    allD.push_back(dif);
                }
                else
                {
                    larV = max(larV, dif);

                    ill res = 0;
                    if (dif > 0) res = 1LL + (dif - 1LL) / 2LL;
                    allD.push_back(res);
                }
            }

            sort(allD.begin(), allD.end());

            int sizD = allD.size();
            ill ans = allD[sizD - 1] + allD[sizD - 2];
            ans = max(ans, larV);
            
            cout << "Case #" << tcc << ": " << (double)((double)ans / (double)rg) << '\n';
        }
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