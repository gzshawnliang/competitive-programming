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
    const ill inf = 1e10, mod = 1e9 + 7;

  public:
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n, k; cin >> n >> k;

            vector<ill> tl(n, 0), tw(n, 0), th(n, 0);
            for (ill i = 0; i <= k - 1; ++i) cin >> tl[i];
            ill al, bl, cl, dl; cin >> al >> bl >> cl >> dl;

            for (ill i = 0; i <= k - 1; ++i) cin >> tw[i];
            ill aw, bw, cw, dw; cin >> aw >> bw >> cw >> dw;

            for (ill i = 0; i <= k - 1; ++i) cin >> th[i];
            ill ah, bh, ch, dh; cin >> ah >> bh >> ch >> dh;

            for (ill i = max(k, 2LL); i <= n - 1; ++i)
                tl[i] = (tl[i - 2] * al + tl[i - 1] * bl + cl) % dl + 1LL;

            for (ill i = max(k, 2LL); i <= n - 1; ++i)
                tw[i] = (tw[i - 2] * aw + tw[i - 1] * bw + cw) % dw + 1LL;

            for (ill i = max(k, 2LL); i <= n - 1; ++i)
                th[i] = (th[i - 2] * ah + th[i - 1] * bh + ch) % dh + 1LL;

            vector<ill> p(n, 0);
            set<pair<ill, ill>> sln;
            for (ill i = 0; i <= n - 1; ++i)
            {
                if (i == 0)
                {
                    p[i] = 2 * (tw[i] + th[i]);

                    sln.insert({tl[i] - inf, tl[i]});
                    sln.insert({tl[i] + tw[i], tl[i] + tw[i] + inf});

                    continue;
                }
                else
                {
                    bool flg = false;
                    ill base = 0;

                    auto tmpIt = sln.lower_bound({tl[i], INT_MIN});
                    if (tmpIt != sln.begin())
                    {
                        if (tmpIt == sln.end())
                        {
                            --tmpIt;
                            if (tmpIt->first <= tl[i] && tl[i] + tw[i] <= tmpIt->second)
                            {
                                base += 2 * (tw[i] + th[i]);

                                sln.insert({tmpIt->first, tl[i]});
                                sln.insert({tl[i] + tw[i], tmpIt->second});

                                sln.erase(tmpIt);

                                flg = true;
                            }
                        }
                        else
                        {
                            --tmpIt;
                            if (tl[i] < tmpIt->second && tmpIt->second <= tl[i] + tw[i])
                            {
                                base += 2 * (tmpIt->second - tl[i]);

                                sln.insert({tmpIt->first, tl[i]});
                                sln.erase(tmpIt);
                            }
                            else if (tmpIt->first <= tl[i] && tl[i] + tw[i] <= tmpIt->second)
                            {
                                base += 2 * (tw[i] + th[i]);

                                sln.insert({tmpIt->first, tl[i]});
                                sln.insert({tl[i] + tw[i], tmpIt->second});

                                sln.erase(tmpIt);

                                flg = true;
                            }
                        }
                    }

                    if (flg == false)
                    {
                        while (true)
                        {
                            auto it = sln.lower_bound({tl[i], INT_MIN});

                            if (it == sln.end())
                            {
                                break;
                            }
                            else if (it->first < tl[i] + tw[i])
                            {
                                if (it->second <= tl[i] + tw[i])
                                {
                                    base += 2 * (it->second - it->first);
                                    base -= 2 * (th[i]);

                                    sln.erase(it);
                                }
                                else
                                {
                                    base += 2 * ((tl[i] + tw[i]) - it->first);

                                    sln.insert({tl[i] + tw[i], it->second});
                                    sln.erase(it);

                                    break;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                    }

                    p[i] = p[i - 1] + base;
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

// change inf

signed main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("A2.in", "r", stdin);
    freopen("A2.out", "w", stdout);
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