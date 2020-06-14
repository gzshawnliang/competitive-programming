/*
===========================================================
* @Name:           1364B Most socially-distanced subsequence
* @Author:         Shawn
* @create Time:    2020/6/13 23:05:31
* @url:            https://codeforces.com/contest/1364/problem/B
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
        for (int i = 0; i <= n - 1; ++i) cin >> a[i];

        int ans = 2;
        vector<int> pos;
        for (int i = 1; i <= n - 2; ++i)
        {
            if ((a[i - 1] < a[i] && a[i] > a[i + 1]) || (a[i - 1] > a[i] && a[i] < a[i + 1]))
            {
                ++ans;
                pos.push_back(i);
            }
        }

        cout << ans << '\n';

        cout << a[0] << ' ';
        for (auto x:pos)
        {
            cout << a[x] << ' ';
        }
        cout << a.back() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1364B_Mostsocially_distancedsubsequence.in", "r", stdin);
    freopen("CF_1364B_Mostsocially_distancedsubsequence.out", "w", stdout);
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