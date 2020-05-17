/*
===========================================================
* @Name:           1355B Young Explorers
* @Author:         Shawn
* @create Time:    2020/5/16 19:35:30
* @url:            https://codeforces.com/contest/1355/problem/B
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    int tct; cin >> tct;
    for (int tcc = 1; tcc <= tct; ++tcc)
    {
        int n; cin >> n;
        vector<int> a(n, 0), numCnt(n + 1, 0);
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> a[i];
            ++numCnt[a[i]];
        }

        sort(a.begin(), a.end());

        int ans = 0;
        for (int x = 1; x <= n; ++x)
        {
            ans += (numCnt[x] / x);
            if (x < n) numCnt[x + 1] += (numCnt[x] % x);
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
        freopen("CF_1355B_YoungExplorers.in", "r", stdin);
        freopen("CF_1355B_YoungExplorers.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}