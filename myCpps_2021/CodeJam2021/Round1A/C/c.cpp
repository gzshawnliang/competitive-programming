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
            int n, tolQ; cin >> n >> tolQ;

            vector<pair<string, int>> a(n);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i].first >> a[i].second;
            }

            vector<string> allS;
            for (int x1 = 0; x1 <= (1 << tolQ) - 1; ++x1)
            {
                bitset<11> b(x1);

                bool flg = true;
                for (int i = 0; i <= n - 1; ++i)
                {
                    int res = 0;
                    for (int j = 0; j <= tolQ - 1; ++j)
                    {
                        if ((b[j] == 1 && a[i].first[j] == 'T') || (b[j] == 0 && a[i].first[j] == 'F')) ++res;
                    }

                    if (res != a[i].second)
                    {
                        flg = false;
                        break;
                    }
                }

                if (flg)
                {
                    string tmp = "";
                    for (int j = 0; j <= tolQ - 1; ++j)
                    {
                        tmp += (b[j]? 'T':'F');
                    }
                    allS.push_back(tmp);
                }
            }

            int maxC = 0; string maxS = "-";
            for (int x1 = 0; x1 <= (1 << tolQ) - 1; ++x1)
            {
                bitset<11> b(x1);

                string now = "";
                for (int j = 0; j <= tolQ - 1; ++j)
                {
                    now += (b[j]? 'T':'F');
                }

                int res = 0;
                for (auto corrS:allS)
                {
                    for (int j = 0; j <= tolQ - 1; ++j)
                    {
                        if ((now[j] == corrS[j])) ++res;
                    }
                }

                if (res > maxC)
                {
                    maxC = res;
                    maxS = now;
                }
            }

            int sizAS = allS.size();
            int _gcd = std::gcd(maxC, sizAS);
            cout << "Case #" << tcc << ": " << maxS << ' ' << maxC / _gcd << '/' << sizAS / _gcd << '\n';
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