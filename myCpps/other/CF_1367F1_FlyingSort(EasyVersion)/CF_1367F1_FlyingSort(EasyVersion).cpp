/*
===========================================================
* @Name:           1367F1 Flying Sort (Easy Version)
* @Author:         Shawn
* @create Time:    2020/6/19 14:20:19
* @url:            https://codeforces.com/contest/1367/problem/F1
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
        int t;
        cin >> t;
        assert(t > 0);
        while (t--)
        {
            int n;
            cin >> n;
            vector<pair<int, int>> a(n);
            for (int i = 0; i <= n - 1; ++i)
            {
                cin >> a[i].first;
                a[i].second = i + 1;
            }
            sort(a.begin(), a.end());

            vector<int> b(n);
            vector<int> use(n, 0);
            for (int i = 0; i <= n - 1; ++i)
            {
                // b[i]=a[i].second;
                b[a[i].second - 1] = i + 1;
            }
            int maxLen = 0;
            int i = 0;
            while (i <= n)
            {
                int len = 0;
                int lastId = i;
                for (int j = lastId + 1; j <= n - 1; ++j)
                {
                    if (use[j] == 1)
                        continue;

                    if (b[j] - b[lastId] == 1)
                    {

                        lastId = j;
                        use[lastId] = 1;
                        ++len;
                    }
                }
                maxLen = max(maxLen, len);
                ++i;
            }
            ++maxLen;
            cout << n - maxLen << "\n";
            assert(n > 0);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1367F1_FlyingSort(EasyVersion).in", "r", stdin);
    //freopen("CF_1367F1_FlyingSort(EasyVersion).out", "w", stdout);
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