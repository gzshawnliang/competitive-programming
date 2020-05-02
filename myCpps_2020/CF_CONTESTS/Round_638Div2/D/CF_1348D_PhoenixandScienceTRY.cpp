/*
===========================================================
* @Name:           1348D Phoenix and Science
* @Author:         Shawn
* @create Time:    2020/5/1 22:35:42
* @url:            https://codeforces.com/contest/1348/problem/D
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
    while (true)
    {
        int n = -1; cin >> n;
        if (n == -1) break;

        int tol = 1, nowSiz = 1;
        for (int c = 1; c <= n; ++c)
        {
            int x; cin >> x;
            nowSiz += x;
            tol += nowSiz;
        }

        cout << tol << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1348D_PhoenixandScience.out", "r", stdin);
        freopen("CF_1348D_PhoenixandScienceTRY.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}