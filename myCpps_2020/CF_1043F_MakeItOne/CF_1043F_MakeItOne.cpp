/*
===========================================================
* @Name:           1043F Make It One
* @Author:         Shawn
* @create Time:    2020/3/9 21:57:34
* @url:            https://codeforces.com/contest/1043/problem/F
* @Description:    
===========================================================
*/

#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;
const ill mod = 1e9 + 7, maxN = 300005;

ill quickPow(ill a, ill n, ill p)    //快速幂 a^n % p
{
    ill ans = 1;
    while(n)
    {
        if(n & 1) ans = ans * a % p;
        a = a * a % p;
        n >>= 1;
    }
    return ans;
}

ill ine(ill a, ill b)   //费马小定理求逆元
{
    return quickPow(a, b - 2, b);
}

ill C(ill a, ill b, vector<ill> &fac)    //计算C(a, b)
{
    if      (b > a)  return 0;
    else if (b == 0) return 1;
    else if (b == 1) return a;
    else             return fac[a] * ine(fac[b], mod) % mod * ine(fac[a - b], mod) % mod;
}

void solve()
{
    ill n; cin >> n;

    ill maxNum = 0;
    vector<ill> a(n), m(maxN + 1);
    for (ill i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
        ++m[a[i]];

        maxNum = max(maxNum, a[i]);
    }
    
    for (ill i = 1; i <= maxNum; ++i)
        for (ill j = i * 2; j <= maxNum; j += i)
            m[i] = m[i] + m[j];

    vector<ill> fac(maxN + 1, 1);
    for(ill i = 2; i <= maxN; ++i)
        fac[i] = fac[i - 1] * i % mod;

    bool flg = false;
    for (ill siz = 1; siz <= 7; ++siz)
    {
        vector<ill> f(maxNum + 1, 0);
        for (ill i = maxNum; i >= 1; --i)
        {
            if (m[i] < siz)
            {
                f[i] = 0; continue;
            }

            f[i] = C(m[i], siz, fac);
            for (ill j = i * 2; j <= maxNum; j += i)
                f[i] = (f[i] + mod - f[j]) % mod;
        }

        if (f[1] > 0)
        {
            cout << siz << '\n';
            flg = true;
            break;
        }
    }

    if (flg == false) cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1043F_MakeItOne.in", "r", stdin);
        freopen("CF_1043F_MakeItOne.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}