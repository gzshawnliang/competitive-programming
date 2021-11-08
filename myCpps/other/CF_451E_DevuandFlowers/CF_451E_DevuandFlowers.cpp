/*
===========================================================
* @Name:           451E Devu and Flowers
* @Author:         Shawn
* @create Time:    2020/3/12 21:07:16
* @url:            https://codeforces.com/contest/451/problem/E
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1e6 + 3;

//卢卡斯第二种实现办法
//https://www.lagou.com/lgeduarticle/52320.html
class CombinationMMI2
{
    
  private:
    //vector<ll> factorial;

    //费马小定理求逆元
    ll pow(ll a, ll n, ll p) //快速幂 a^n % p
    {
        ll ans = 1;
        while (n)
        {
            if (n & 1)
                ans = ans * a % p;
            a = a * a % p;
            n >>= 1;
        }
        return ans;
    }

    ll mmi(ll a, ll b) //费马小定理求逆元
    {
        return pow(a, b - 2, b);
    }

  public:
    CombinationMMI2()
    {
    }

    ll C(ll a, ll b) //计算C(a, b)
    {
        if (b > a)
            return 0;

        ll up = 1, down = 1; //分子分母;
        for (int i = a - b + 1; i <= a; ++i)
            up = up * i % MOD;
        for (int i = 1; i <= b; i++)
            down = down * i % MOD;
        return up * mmi(down, MOD) % MOD;
    }

    ll Lucas(ll a, ll b) //Lucas定理递归
    {
        if (b == 0) //递归终止条件
            return 1;
        else
            return C(a % MOD, b % MOD) * Lucas(a / MOD, b / MOD) % MOD;
    }
};


//todo:未完成
void solve()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> f(n);
    for (ll i = 0; i <= n - 1; ++i)
    {
        cin >> f[i];
    }
    CombinationMMI2 mmi;
    ll ans = mmi.Lucas(n + s - 1, n);

    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_451E_DevuandFlowers.in", "r", stdin);
    //freopen("CF_451E_DevuandFlowers.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}