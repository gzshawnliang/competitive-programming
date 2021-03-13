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
            int n; cin >> n;
            vector<tuple<int, int, int, int>> prs(n);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> get<0>(prs[i]) >> get<1>(prs[i]);
                get<2>(prs[i]) = i;
                get<3>(prs[i]) = -1;
            }

            sort(prs.begin(), prs.end());

            get<3>(prs[0]) = 1;
            for (int i = 1; i <= n - 1; ++i)
            {
                if (max(get<0>(prs[i - 1]), get<0>(prs[i])) < min(get<1>(prs[i - 1]), get<1>(prs[i])))
                {
                    get<3>(prs[i]) = 1 - get<3>(prs[i - 1]);
                }
                else
                {
                    get<3>(prs[i]) = get<3>(prs[i - 1]);
                }
            }

            bool flg = true;
            for (int i = 0; i <= n - 1 && flg == true; ++i)
            {
                for (int j = i + 1; j <= n - 1 && flg == true; ++j)
                {
                    if (max(get<0>(prs[i]), get<0>(prs[j])) < min(get<1>(prs[i]), get<1>(prs[j])) && get<3>(prs[i]) == get<3>(prs[j]))
                    {
                        flg = false;
                    }
                }
            }

            cout << "Case #" << tcc << ": ";
            if (flg == false) cout << "IMPOSSIBLE\n";
            else
            {
                string ans;
                for (int c = 1; c <= n; ++c) ans += '_';
                for (auto tp:prs)
                    ans[get<2>(tp)] = ((get<3>(tp) == 1) ? 'J':'C');
                
                cout << ans << '\n';
            }
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("ParentingPartneringReturns.in", "r", stdin);
    freopen("ParentingPartneringReturns.out", "w", stdout);
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