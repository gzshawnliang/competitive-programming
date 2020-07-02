/*
-------------------------------------------------------------------
* @Name:           1374F Cyclic Shifts Sorting
* @Author:         Shawn
* @Create Time:    2020/6/28 22:35:17  (UTC+08:00)
* @Url:            https://codeforces.com/contest/1374/problem/F
* @File:           CF_1374F_CyclicShiftsSorting.cpp
* @Description:    
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
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
            
            vector<int> a(n, 0);
            vector<pair<int, int>> res(n);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i];
                res[i] = {a[i], i};
            }

            sort(res.begin(), res.end());
            for (int i = 0; i <= n - 1; ++i) a[res[i].second] = i;

            int cntR = 0;
            for (int i = 0; i <= n - 1; ++i)
                for (int j = i + 1; j <= n - 1; ++j)
                    cntR += a[j] < a[i];

            if (cntR % 2 == 1)
            {
                for (int i = 0; i <= n - 1; ++i)
                {
                    if (res[i].first == res[i + 1].first)
                    {
                        swap(a[res[i].second], a[res[i + 1].second]);
                        break;
                    }
                }
            }

            auto op=[&](int pos)
            {
                swap(a[pos + 1], a[pos + 2]);
                swap(a[pos], a[pos + 1]);
            };

            vector<int> ansO;
            for (int i = 0; i <= n - 3; ++i)
            {
                int pos = min_element(a.begin() + i, a.end()) - a.begin();

                while (pos > i + 1)
                {
                    op(pos - 2);
                    ansO.push_back(pos - 2);
                    
                    pos -= 2;
                }

                if (pos != i)
                {
                    op(i);
                    op(i);
                    ansO.push_back(i);
                    ansO.push_back(i);

                    pos = i;
                }
            }

            for (int i = 0; i <= 2; ++i)
            {
                if (is_sorted(a.begin(), a.end())) break;

                op(n - 3);
                ansO.push_back(n - 3);
            }

            if (is_sorted(a.begin(), a.end()) == false)
            {
                cout << "-1\n";
            }
            else
            {
                cout << ansO.size() << '\n';

                bool first = true;
                for (auto x:ansO)
                {
                    if (first) first = false;
                    else       cout << ' ';

                    cout << x + 1;
                }
                cout << '\n';
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1374F_CyclicShiftsSorting.in", "r", stdin);
    freopen("CF_1374F_CyclicShiftsSorting.out", "w", stdout);
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