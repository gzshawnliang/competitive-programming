/*
===========================================================
* @Name:           1367F2 Flying Sort (Hard Version)
* @Author:         Shawn
* @create Time:    2020/6/16 22:35:39
* @url:            https://codeforces.com/contest/1367/problem/F2
* @Description:    
===========================================================
*/
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
  public:

    void solve()
    {
        int tct; cin >> tct;
        for (int tcc = 1; tcc <= tct; ++tcc)
        {
            int n; cin >> n;
            vector<pair<int, int>> b(n);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> b[i].first; b[i].second = i;
            }

            sort(b.begin(), b.end());

            int cnt = 0, lst = b[0].first;
            vector<int> a(n, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                if (b[i].first > lst)
                {
                    ++cnt;
                    lst = b[i].first;
                }
                a[b[i].second] = cnt;
            }

            vector<int> lstPos(n, -1), lm(n, -1), rm(n, -1), num(n, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                rm[a[i]] = i;
                if (lm[a[i]] == -1)
                {
                    lm[a[i]] = i;
                    lstPos[a[i]] = i;
                }

                ++num[a[i]];
            }

            int ans = 0;
            vector<vector<int>> f(n, vector<int>(3, 0));
            for (int i = 0; i <= n - 1; ++i)
            {
                f[i][0] = f[lstPos[a[i]]][0] + 1;
                f[i][1] = f[lstPos[a[i]]][1] + 1;
                if (a[i] - 1 >= 0) f[i][1] = max(f[i][1], max(f[lstPos[a[i] - 1]][0] + 1, f[lstPos[a[i] - 1]][2] + 1));

                if (i == rm[a[i]])
                {
                    f[i][2] = f[lm[a[i]]][1] + num[a[i]] - 1;
                }

                lstPos[a[i]] = i;

                for (int k = 0; k <= 2; ++k) ans = max(ans, f[i][k]);
            }

            cout << n - ans << '\n';
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1367F2_FlyingSort(HardVersion).in", "r", stdin);
    freopen("CF_1367F2_FlyingSort(HardVersion).out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solution sln1;
    sln1.solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}