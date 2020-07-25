#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif

#ifndef ONLINE_JUDGE
#include <chrono>
#endif

#include <bits/stdc++.h>

using namespace std;

using ill = long long; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

class solution
{
  public:
    void solve()
    {
        ill tct; cin >> tct;
        for (ill tcc = 1; tcc <= tct; ++tcc)
        {
            ill n; cin >> n;
            set<ill> kp;
            map<ill, ill> trees, f;
            for (ill i = 0; i <= n - 1; ++i)
            {
                ill p, h; cin >> p >> h;

                kp.insert(p);
                trees[p] = h;
            }

            ill ans = 0;
            for (auto p:kp)
            {
                ill h = trees[p];

                f[p + h] = max(f[p + h], f[p] + h);

                ans = max(ans, f[p] + h);

                if (f.count(p - h)) f[p] = max(f[p], f[p - h] + h);
                ans = max(ans, f[p]);
            }

            cout << "Case #" << tcc << ": " << ans << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
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