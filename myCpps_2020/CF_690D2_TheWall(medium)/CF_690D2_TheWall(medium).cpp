/*
===========================================================
* @Name:           690D2 The Wall (medium)
* @Author:         Shawn
* @create Time:    2020/3/11 21:48:11
* @url:            https://codeforces.com/contest/690/problem/D2
* @Description:    
===========================================================
*/

#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using ill = long long;
const ill mod = 1e6 + 3, maxN = 700005;

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
    ill n, w; cin >> n >> w;

    vector<ill> fac(maxN + 1, 1);
    for(ill i = 2; i <= maxN; ++i)
        fac[i] = fac[i - 1] * i % mod;

    ill ans = C(n + w, w, fac);

    ans = (ans + mod - 1) % mod;

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_690D2_TheWall(medium).in", "r", stdin);
        freopen("CF_690D2_TheWall(medium).out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}