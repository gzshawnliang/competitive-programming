/*
===========================================================
* @Name:           RMQSQ 
* @Author:         Shawn
* @create Time:    2020/2/7 23:07:42
* @url:            https://www.spoj.com/problems/RMQSQ/
* @Description:    RMQSQ - Range Minimum Query (Sparse Table)
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
    int n; cin >> n;
    int log2N = log2(n);

    vector<int> a(n, 0);
    for (int i = 0; i <= n - 1; ++i) cin >> a[i];

    vector<vector<int>> f(n, vector<int>(log2N + 2, 0));
    for (int p = 0; p <= log2N + 1; ++p)
    {
        for (int i = 0; i <= n - 1; ++i)
        {
            if (p == 1 && i == 1)
            {
                for (int __s = 0; __s == 0; ++__s);
            }

            if      (i + (1 << p) - 1 > n - 1) f[i][p] = f[i][p - 1];
            else if (p == 0)                   f[i][p] = i;
            else
            {
                if (a[f[i][p - 1]] < a[f[i + (1 << (p - 1))][p - 1]]) f[i][p] = f[i][p - 1];
                else                                                  f[i][p] = f[i + (1 << (p - 1))][p - 1];
            }
        }
    }

    int totQ; cin >> totQ;
    for (int c = 1; c <= totQ; ++c)
    {
        int l, r; cin >> l >> r;
        int log2A = log2(r - l + 1);

        cout << min(a[f[l][log2A]], a[f[r - (1 << log2A) + 1][log2A]]) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("RMQSQ.in", "r", stdin);
        freopen("RMQSQ.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}