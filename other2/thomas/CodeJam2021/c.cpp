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
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n, m; cin >> n >> m;

            bool flg = false;
            vector<int> orgA(n, 0);
            for (int i = 0; i <= n - 1; ++i) orgA[i] = i + 1;

            //cout << "Case #" << tcc << ':';
            int maxAns=0;
            do
            {
                int ans = 0;
                vector<int> a = orgA;
                for (int i = 0; i <= n - 2; ++i)
                {
                    int minP = i;
                    for (int j = i + 1; j <= n - 1; ++j)
                        if (a[minP] > a[j])
                            minP = j;

                    ans += (minP - i + 1);
                    reverse(a.begin() + i, a.begin() + minP + 1);
                }


                flg = true;
                maxAns=max(ans,maxAns);
                cout << ans << " ";
                for (int i = 0; i <= n - 1; ++i)
                    cout << ' ' << orgA[i];
                cout << '\n';
                //break;
                
            }
            while (next_permutation(orgA.begin(), orgA.end()));

            cerr <<maxAns<< "\n";

            //if (flg == false) cout << " IMPOSSIBLE\n";
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
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