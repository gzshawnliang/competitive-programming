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
            string s; cin >> s;
            int n = s.size();

            vector<int> posK;
            vector<string> ssK = {"K", "KI", "KIC", "KICK"};
            for (int i = 0; i <= n - 1 - 4; ++i)
            {
                string tmp = "";
                for (int j = i; j <= i + 3; ++j)
                {
                    tmp += s[j];
                    if (tmp != ssK[j - i])
                    {
                        break;
                    }
                    else if (j == i + 3)
                    {
                        posK.push_back(i);
                        break;
                    }
                }
            }

            vector<int> posS;
            vector<string> ssS = {"S", "ST", "STA", "STAR", "START"};
            for (int i = 0; i <= n - 1 - 4; ++i)
            {
                string tmp = "";
                for (int j = i; j <= i + 4; ++j)
                {
                    tmp += s[j];
                    if (tmp != ssS[j - i])
                    {
                        break;
                    }
                    else if (j == i + 4)
                    {
                        posS.push_back(i);
                        break;
                    }
                }
            }

            int ans = 0, sizS = posS.size();
            for (auto x:posK)
            {
                int cnt = upper_bound(posS.begin(), posS.end(), x) - posS.begin();

                ans += (sizS - cnt);
            }

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

signed main()
{
    FastIO;

#ifdef LOCAL_DEBUG
    freopen("PA.in", "r", stdin);
    freopen("PA.out", "w", stdout);
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