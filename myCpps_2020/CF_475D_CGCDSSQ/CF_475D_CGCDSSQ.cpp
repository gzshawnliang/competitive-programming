/*
===========================================================
* @Name:           475D CGCDSSQ
* @Author:         Shawn
* @create Time:    2020/2/8 21:53:56
* @url:            https://codeforces.com/contest/475/problem/D
* @Description:    sparse-table + 二分
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

ill _log2(ill x)
{
    ill p = 0;
    while ((1 << p) <= x)
    {
        ++p;
    }

    return p - 1;
}

ill _gcd(ill a, ill b)
{
    if (b == 0) return a;
    else        return _gcd(b, a % b);
}

ill query(ill l, ill r, vector<vector<ill>> &f) 
{ 
    ill k = _log2(r - l + 1); 
    return _gcd(f[l][k], f[r - (1 << k) + 1][k]); 
} 

void solve()
{
    ill n; cin >> n;
    ill log2N = _log2(n);

    vector<vector<ill>> f(n, vector<ill>(log2N + 2, 1));
    for (ill i = 0; i <= n - 1; ++i) cin >> f[i][0];

    for (ill p = 1; p <= log2N + 1; ++p)
    {
        for (ill i = 0; i + (1 << p) - 1 <= n - 1; ++i)
        {
            f[i][p] = _gcd(f[i][p - 1], f[i + (1 << (p - 1))][p - 1]);
        }
    }

    unordered_map<ill, ill> amp;
    for (ill i = 0; i <= n - 1; ++i)
    {
        ill nowP = i, nowGcd = 1;
        while (nowP <= n - 1)
        {
            nowGcd = query(i, nowP, f);
            ill l = nowP, r = n - 1, ans = -1;
            while (true)
            {
                ill mid = (l + r) / 2;
                if (r - l <= 1)
                {
                    if (query(i, r, f) == nowGcd) ans = r;
                    else                          ans = l;
                    break;
                }
                else
                {
                    if (query(i, mid, f) < nowGcd)
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid;
                    }
                }
            }

            amp[nowGcd] += (ans - nowP + 1);
            nowP = ans + 1;
        }
    }

    ill totQ; cin >> totQ;
    for (ill c = 1; c <= totQ; ++c)
    {
        ill x; cin >> x;
        cout << amp[x] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_475D_CGCDSSQ.in", "r", stdin);
        freopen("CF_475D_CGCDSSQ.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}