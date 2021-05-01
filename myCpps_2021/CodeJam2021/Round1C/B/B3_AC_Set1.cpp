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
    vector<ull> a;

    void genData()
    {
        for (int i = 1; i <= 998; ++i)
        {
            int j = i;
            ++j;
            string s = to_string(i) + to_string(j);
            while (s.length() <= 7)
            {

                a.push_back(stoll(s));
                ++j;
                s += to_string(j);
            }
        }

        sort(a.begin(), a.end());
        
        // cerr << a.size() << "\n";
        // for (int i = 0, len = a.size(); i <= len - 1; ++i)
        // {
        //     cerr << a[i] << "\n";
        // }

        return;
    }

  public:
    void solve()
    {
        genData();

        int t;
        cin >> t;
        for (int i = 1; i <= t; ++i)
        {
            int Y;
            cin >> Y;
            auto ret = lower_bound(a.begin(), a.end(), Y);
            if ((*ret) == (ull)Y)
                ++ret;

            cout << "Case #" << i << ": " << *ret << "\n";
        }

        return;
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