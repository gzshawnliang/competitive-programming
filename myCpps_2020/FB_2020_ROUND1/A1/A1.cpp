#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long;

class solution
{
    const ill mod = 1e9 + 7;

  public:
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, k, w; cin >> n >> k >> w;

            vector<ill> tl(n, 0), th(n, 0);
            for (ill i = 0; i <= k - 1; ++i) cin >> tl[i];

            ill al, bl, cl, dl; cin >> al >> bl >> cl >> dl;

            for (ill i = 0; i <= k - 1; ++i) cin >> th[i];

            ill ah, bh, ch, dh; cin >> ah >> bh >> ch >> dh;

            for (ill i = max(k, 2LL); i <= n - 1; ++i)
                tl[i] = (tl[i - 2] * al + tl[i - 1] * bl + cl) % dl + 1LL;

            for (ill i = max(k, 2LL); i <= n - 1; ++i)
                th[i] = (th[i - 2] * ah + th[i - 1] * bh + ch) % dh + 1LL;

            vector<tuple<ill, ill, ill>> tvl;
            for (ill i = 0; i <= n - 1; ++i)
            {
                tvl.push_back({tl[i], th[i], 1});
                tvl.push_back({tl[i] + w, th[i], -1});
            }

            sort(tvl.begin(), tvl.end());

            ill base = 0, lft = tl[0], maxL = tl[0], maxH = 0, pos = 0;
            set<ill> getH;
            vector<ill> p(n, 0);
            for (ill i = 0; i <= n - 1; ++i)
            {
                while (get<0>(tvl[pos]) < tl[i])
                {
                    if (get<2>(tvl[pos]) == 1)
                    {
                        getH.insert(get<1>(tvl[pos]));
                    }
                    else
                    {
                        getH.erase(get<1>(tvl[pos]));
                    }
                    ++pos;
                }

                if (tl[i] > maxL)
                {
                    base = p[i - 1];
                    lft = tl[i];

                    p[i] = base + 2 * (w + th[i]);

                    maxL = tl[i] + w; maxH = th[i];
                }
                else
                {
                    if (i > 0)
                    {
                        ill deh = th[i] - *getH.rbegin();

                        if (deh > 0)
                        {
                            if (th[i] <= maxH)
                            {
                                base += 2 * (deh);
                            }
                            else
                            {
                                base += 2 * (deh - (th[i] - maxH));
                            }
                        }
                        // if (i > 1)
                        // {
                        //     // if (deh[i - 1] < 0 && deh[i] > 0 && tl[i - 2] + w < tl[i])
                        //     // {
                        //     //     base += min(deh[i], -1 * deh[i - 1]) * 2;
                        //     // }
                        // }
                    }

                    maxL = max(maxL, tl[i] + w); maxH = max(maxH, th[i]);
                    p[i] = base + 2 * ((maxL - lft) + maxH);
                }
            }

            ill ans = 1;
            for (ill i = 0; i <= n - 1; ++i)
            {
                ans = (ans * (p[i] % mod)) % mod;
            }

            cout << "Case #" << tcc << ": " << ans << '\n';

            // for (ill i = 0; i <= n - 1; ++i)
            // {
            //     cout << '(' << tl[i] << ", 0) ";
            //     cout << '(' << tl[i] + w << ", " << th[i] << ")\n";
            // }
            // cout << '\n';

            // for (auto x : p)
            // {
            //     cout << x << ' ';
            // }
            // cout << '\n';
        }
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("A1.in", "r", stdin);
    freopen("A1.out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms\n";
#endif

    return 0;
}