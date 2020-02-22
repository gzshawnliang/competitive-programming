/*
===========================================================
* @Name:           514D R2D2 and Droid Army
* @Author:         Shawn
* @create Time:    2020/2/22 20:31:23
* @url:            https://codeforces.com/contest/514/problem/D
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
    int n, m, k; cin >> n >> m >> k;
    int log2N = log2(n);

    vector<vector<int>> a(m, vector<int>(n, 0));
    vector<vector<vector<int>>> f(m, vector<vector<int>>(n, vector<int>(log2N + 1, 0)));
    for (int i = 0; i <= n - 1; ++i)
        for (int j = 0; j <= m - 1; ++j)
            cin >> a[j][i];

    for (int j = 0; j <= m - 1; ++j)
    {
        for (int p = 0; p <= log2N; ++p)
        {
            for (int i = 0; i <= n - 1; ++i)
            {
                if (i + (1 << p) - 1 > n - 1)
                {
                    break;
                }
                else if (p == 0)
                {
                    f[j][i][p] = i;
                    continue;
                }

                if (a[j][f[j][i][p - 1]] > a[j][f[j][i + (1 << (p - 1))][p - 1]]) f[j][i][p] = f[j][i][p - 1];
                else                                                              f[j][i][p] = f[j][i + (1 << (p - 1))][p - 1];
            }
        }
    }

    auto query = [=](int j, int l, int r)
    {
        if (l > r) swap(l, r);
        int log2S = log2(r - l + 1);

        return max(a[j][f[j][l][log2S]], a[j][f[j][r - (1 << log2S) + 1][log2S]]);
    };

    auto check = [=](vector<int> &returnAns, int mid)
    {
        if (mid == 0)
        {
            for (int j = 0; j <= m - 1; ++j) returnAns[j] = 0;
            
            return true;
        }

        for (int i = 0; i + mid - 1 <= n - 1; ++i)
        {
            int res = 0;
            for (int j = 0; j <= m - 1; ++j)
            {
                int nowMax = query(j, i, i + mid - 1);
                res += nowMax;
                returnAns[j] = nowMax;
            }

            if (res <= k) return true;
        }

        return false;
    };

    int lbd = 0, rbd = n;
    vector<int> ans(m, 0);
    while (true)
    {
        vector<int> tmp(m, 0);

        if (rbd - lbd <= 1)
        {
            if (check(tmp, rbd) == true)
            {
                ans = tmp;
            }
            else
            {
                check(tmp, lbd); ans = tmp;
            }
            break;
        }
        else
        {
            int mid = (lbd + rbd) / 2;
            if (check(tmp, mid) == true)
            {
                ans = tmp;
                lbd = mid;
            }
            else
            {
                rbd = mid - 1;
            }
        }
    }

    for (int j = 0; j <= m - 1; ++j)
    {
        if (j > 0) cout << ' ';
        cout << ans[j];
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_514D_R2D2andDroidArmy.in", "r", stdin);
        freopen("CF_514D_R2D2andDroidArmy.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}