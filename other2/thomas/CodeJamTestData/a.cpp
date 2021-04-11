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
            vector<string> a(n);
            for (auto &x:a) cin >> x;

            ill ans = 0;
            for (ill i = 1; i <= n - 1; ++i)
            {
                string las = a[i - 1], now = a[i];

                ill sizL = las.size(), sizN = now.size();
                if (sizL < sizN) continue;
                
                bool isGreater = false, isEqual = true;
                for (ill j = 0; j <= sizN - 1; ++j)
                {
                    if (now[j] != las[j])
                    {
                        isEqual = false;
                        isGreater = (now[j] > las[j]);
                        break;
                    }
                }

                if (isEqual)
                {
                    if ((las.back() - '0') % 10 == 9)
                    {
                        for (ill c = 1; c <= sizL - sizN + 1; ++c)
                        {
                            now += '0'; ++ans;
                        }
                    }
                    else
                    {
                        if (sizL - sizN > 0)
                        {
                            ans += (sizL - sizN);
                            now = las;

                            ++now[now.size() - 1];
                        }
                        else
                        {
                            now += '0'; ++ans;
                        }
                    }
                }
                else if (isGreater)
                {
                    if (sizL == sizN && las == now)
                    {
                        now = las;
                        ++now[now.size() - 1];
                    }
                    else
                    {
                        for (ill c = 1; c <= sizL - sizN; ++c)
                        {
                            now += '0'; ++ans;
                        }
                    }
                }
                else
                {
                    for (ill c = 1; c <= sizL - sizN + 1; ++c)
                    {
                        now += '0'; ++ans;
                    }
                }

                a[i] = now;
                cout << a[i] << '\n';
            }

            cout << "Case #" << tcc << ": " << ans << '\n';
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