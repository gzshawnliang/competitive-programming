/*
===========================================================
* @Name:           1364C Ehab and Prefix MEXs
* @Author:         Shawn
* @create Time:    2020/6/13 23:05:31
* @url:            https://codeforces.com/contest/1364/problem/C
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
    int n; cin >> n;

    int maxN = 0;
    vector<int> a(n, 0), cntN(n + 2, 0);
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
        maxN = max(maxN, a[i]);
        cntN[a[i]] = 1;
    }

    int x = 0;

    for (int i = 0; i <= n - 1; ++i)
    {
        if (a[i] == a[i - 1] || i == 0)
        {
            while (cntN[x] == 1) ++x;
            if (i > 0) cout << ' ';
            cout << x;
            ++x;
        }
        else
        {
            cout << ' ' << a[i - 1];
        }
    }

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1364C_EhabandPrefixMEXs.in", "r", stdin);
    freopen("CF_1364C_EhabandPrefixMEXs.out", "w", stdout);
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