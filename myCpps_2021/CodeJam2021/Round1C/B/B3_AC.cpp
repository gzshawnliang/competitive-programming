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

using ull = unsigned long long;

class solution
{
  public:
    void solve()
    {
        vector<ull> up3;
        for (ull x = 1LL; x <= 999999LL; ++x)
        {
            bool flg = false;
            ull tmpX = x;
            string s = to_string(tmpX);
            s += to_string(++tmpX);
            s += to_string(++tmpX);
            while (s.size() <= 19)
            {
                up3.push_back(stoull(s));
                s += to_string(++tmpX);
                flg = true;
            }

            if (!flg) break;
        }
        sort(up3.begin(), up3.end());

        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            ull askN; cin >> askN;
            
            auto getUp2=[&](ull x)
            {
                ull tmpX = x;
                string s = to_string(tmpX);
                s += to_string(++tmpX);
                return stoull(s);
            };

            ull l1 = 0LL, r1 = 999999999LL, ans1 = r1;
            while (true)
            {
                ull mid = (l1 + r1) / 2;

                if (r1 - l1 <= 1LL)
                {
                    ull tmp = getUp2(l1);
                    if (tmp > askN) ans1 = tmp;
                    else            ans1 = getUp2(r1);
                    break;
                }
                else
                {
                    if (getUp2(mid) > askN) r1 = mid;
                    else                    l1 = mid + 1;
                }
            }

            ull ans2 = *upper_bound(up3.begin(), up3.end(), askN);

            cout << "Case #" << tcc << ": " << min(ans1, ans2) << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("B3.in", "r", stdin);
    freopen("B3.out", "w", stdout);
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