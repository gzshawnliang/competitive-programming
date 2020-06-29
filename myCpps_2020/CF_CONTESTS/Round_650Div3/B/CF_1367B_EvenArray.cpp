/*
===========================================================
* @Name:           1367B Even Array
* @Author:         Shawn
* @create Time:    2020/6/16 22:35:38
* @url:            https://codeforces.com/contest/1367/problem/B
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

        int cnt0 = 0, cntNM0 = 0;
        vector<int> a(n, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i]; a[i] %= 2;
            if (a[i] == 0)
            {
                ++cnt0;
                if (i % 2 == 1) ++cntNM0;
            }
        }
        
        if (cnt0 != n / 2 + n % 2)
        {
            cout << "-1\n";
        }
        else
        {
            cout << cntNM0 << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1367B_EvenArray.in", "r", stdin);
    freopen("CF_1367B_EvenArray.out", "w", stdout);
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