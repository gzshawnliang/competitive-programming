/*
===========================================================
* @Name:           1367F1 Flying Sort (Easy Version)
* @Author:         Shawn
* @create Time:    2020/6/16 22:35:39
* @url:            https://codeforces.com/gym/1367/problem/F1
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

void solve()
{
    int tct; cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc)
    {
        int n; cin >> n;

        vector<int> a(n, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];
        }

        int ans = n - 1;
        for (int i = 0; i <= n - 1; ++i)
        {
            for (int j = i + 1; j <= n - 1; ++j)
            {
                if (a[i] > a[j]) continue;

                vector<int> tmp;
                for (int k = i + 1; k <= j - 1; ++k)
                {
                    if (a[i] <= a[k] && a[k] <= a[j])
                    {
                        tmp.push_back(a[k]);
                    }
                }

                bool ok = true;
                int sizT = tmp.size();
                for (int k = 0; k <= sizT - 2 && ok == true; ++k)
                {
                    if (tmp[k] > tmp[k + 1]) ok = false;
                }
            
                if (ok) ans = min(ans, n - sizT - 2);
            }
        }

        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1367F1_FlyingSort(EasyVersion).in", "r", stdin);
    freopen("CF_1367F1_FlyingSort(EasyVersion).out", "w", stdout);
    auto startTime = std::chrono::high_resolution_clock::now();
#endif

    solve();
    cout.flush();

#ifndef ONLINE_JUDGE
    auto endTime = std::chrono::high_resolution_clock::now();
    std::cerr << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
              << " ms" << std::endl;
#endif

    return 0;
}