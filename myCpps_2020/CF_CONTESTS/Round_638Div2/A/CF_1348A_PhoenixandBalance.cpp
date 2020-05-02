/*
===========================================================
* @Name:           1348A Phoenix and Balance
* @Author:         Shawn
* @create Time:    2020/5/1 22:35:42
* @url:            https://codeforces.com/contest/1348/problem/A
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

void solve()
{
    ill tct; cin >> tct;
    for (ill tcc = 1; tcc <= tct; ++tcc)
    {
        ill n; cin >> n;
        if (n == 2)
        {
            cout << "2\n";
            continue;
        }

        ill tol = (1 << (n + 1)) - 2, firstH = 0;
        for (ill p = 1; p <= n / 2 - 1; ++p) firstH += (1 << p);

        cout << 2 * (firstH + (1 << n)) - tol << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1348A_PhoenixandBalance.in", "r", stdin);
        freopen("CF_1348A_PhoenixandBalance.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}