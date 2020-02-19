/*
===========================================================
* @Name:           488D Strip
* @Author:         Shawn
* @create Time:    2020/2/19 13:03:38
* @url:            https://codeforces.com/contest/488/problem/D
* @Description:    
===========================================================
*/

#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill inf = INT_MAX / 2;

ill queryMin(ill l, ill r, vector<ill> &a, vector<vector<ill>> &f1)
{
    ill log2A = log2(r - l + 1);
    return min(a[f1[l][log2A]], a[f1[r - (1 << log2A) + 1][log2A]]);
}

ill queryMax(ill l, ill r, vector<ill> &a, vector<vector<ill>> &f2)
{
    ill log2A = log2(r - l + 1);
    return max(a[f2[l][log2A]], a[f2[r - (1 << log2A) + 1][log2A]]);
}

void solve()
{
    ill n, s, l; cin >> n >> s >> l;
    ill log2N = log2(n + 1);

    vector<ill> a(n + 1, 0);
    for (ill i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<ill>> f1(n + 1, vector<ill>(log2N + 2, -1)), f2(n + 1, vector<ill>(log2N + 2, -1));
    for (ill p = 0; p <= log2N + 1; ++p)
    {
        for (ill i = 1; i <= n; ++i)
        {
            if (i + (1 << p) - 1 > n)
            {
                break;
            }

            if (p == 0) f1[i][p] = i;
            else
            {
                if (a[f1[i][p - 1]] < a[f1[i + (1 << (p - 1))][p - 1]]) f1[i][p] = f1[i][p - 1];
                else                                                    f1[i][p] = f1[i + (1 << (p - 1))][p - 1];
            }

            if (p == 0) f2[i][p] = i;
            else
            {
                if (a[f2[i][p - 1]] > a[f2[i + (1 << (p - 1))][p - 1]]) f2[i][p] = f2[i][p - 1];
                else                                                    f2[i][p] = f2[i + (1 << (p - 1))][p - 1];
            }
        }
    }

    vector<ill> f(n + 1, inf); f[0] = 0;
    for (ill i = l, j = 0; i <= n; ++i)
    {
        while ((queryMax(j + 1, i, a, f2) - queryMin(j + 1, i, a, f1) > s || f[j] == inf) && i - j >= l)
        {
            ++j;
        }
        
        if (i - j >= l) f[i] = min(f[i], f[j] + 1);
    }

    if (f[n] == inf) cout << "-1\n";
    else             cout << f[n] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_488D_Strip.in", "r", stdin);
        freopen("CF_488D_Strip.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}