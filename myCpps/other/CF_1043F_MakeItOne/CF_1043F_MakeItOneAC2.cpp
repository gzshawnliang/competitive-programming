/*
===========================================================
* @Name:           1043F Make It One
* @Author:         Shawn
* @create Time:    2020/3/8 11:49:59
* @url:            https://codeforces.com/contest/1043/problem/F
* @Description:    容斥原理，组合数比较大，Pascal公式超内存，需要逆元计算组合数o
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int maxA = 3e5 + 1;
const ll MOD = 1e9 + 7;

//计算组合数：从a个数中取b个处理有多少种方案（Pascal公式，帕斯卡恒等式）
class CombinationPascal
{
    private:
    vector<vector<ll>> c;
    /**
     * 从M个数中取N个处理有多少种方案,动态规划（Pascal公式，帕斯卡恒等式）
     * https://zhuanlan.zhihu.com/p/74787475
     */
    void InitData(ll M)
    {
        c[0][0] = 1;
        for (ll i = 0; i <= M; ++i)
        {
            for (ll j = 0; j <= i; ++j)
            {
                if (j == 0)
                    c[i][j] = 1;
                else if (i == 1)
                    c[i][j] = 1;
                else if (i == j)
                    c[i][j] = 1;
                else
                    c[i][j] = ((c[i - 1][j - 1] % MOD) + (c[i - 1][j] % MOD) % MOD) % MOD;
            }
        }
    }

    public:

    CombinationPascal(int m)
    {
        c.assign(m + 1, vector<ll>(m + 1, 0));
        InitData(m);
    }

    /**
     * 从a个数中取b个处理有多少种方案（Pascal公式，帕斯卡恒等式）
     */
    ll C(ll a, ll b)
    {
        if (b > a)
            return 0;
        else if (b == 0)
            return 1;
        else if (a == 1)
            return 1;
        else if (a == b)
            return 1;
        else
            return c[a][b];
    }


};

//计算组合数：从M个数中取N个处理有多少种方案（逆元,Modular Multiplicative Inverse）
//https://www.zybuluo.com/ArrowLLL/note/713749
class CombinationMMI
{
    private:
    vector<ll> factorial;

    void calFactorial()    //求maxA以内的数的阶乘
    {
        factorial[0] = 1;
        factorial[1] = 1;
        for(ll i = 2; i < maxA+1; ++i)
            factorial[i] = factorial[i - 1] * i % MOD;
    }

    //费马小定理求逆元
    ll pow(ll a, ll n, ll p)    //快速幂 a^n % p
    {
        ll ans = 1;
        while(n)
        {
            if(n & 1) ans = ans * a % p;
            a = a * a % p;
            n >>= 1;
        }
        return ans;
    }

    ll mmi(ll a, ll b)   //费马小定理求逆元
    {
        return pow(a, b - 2, b);
    }
    
    public:
    CombinationMMI()
    {
        factorial.assign(maxA+1,0);
        calFactorial();
    }

    ll C(ll a, ll b)    //计算C(a, b)
    {
        if(b>a)
            return 0;

        return (factorial[a] * mmi(factorial[b], MOD) % MOD * mmi(factorial[a - b], MOD) % MOD) % MOD;
    }
};

void solve()
{
    int n;
    cin >> n;
    //assert(n > 0);

    CombinationMMI CMMI;
    //CombinationPascal CPAS(n);

    vector<int> a(n, 0);
    

    int gcd = 0;
    int mx = 0;
    for (int i = 0; i <= n - 1; ++i)
    {
        cin >> a[i];
        //++m[a[i]];
        //++f[1][a[i]];
        gcd = __gcd(gcd, a[i]);
        mx = max(mx, a[i]);
    }
    //vector<vector<int>> f(7 + 1, vector<int>(mx + 1, 0));
    vector<int> f2(mx + 1, 0);
    vector<int> m(mx, 0);

    for (int i = 0; i <= n-1 ; ++i)
        ++m[a[i]];

    for (int i = 1; i <= mx; ++i)
        for (int j = i + i; j <= mx; j += i)
            m[i] += m[j];

    if (gcd > 1)
    {
        cout << -1 << '\n';
        return;
    }

    for (int i = 1; i <= 7; ++i)
    {
        for (int j = mx; j >= 1; --j)
        {
            f2[j] = 1ll * CMMI.C(m[j],i) % MOD;
            for (int k = j + j; k <= mx; k += j)
            {
                f2[j] -= f2[k];
                if (f2[j] < 0)
                    f2[j] += MOD;
            }
        }

        if (f2[1] > 0)
        {
            cout << i << '\n';
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1043F_MakeItOne.in", "r", stdin);
    //freopen("CF_1043F_MakeItOne.out", "w", stdout);
#endif

    solve();
    // int n=100;
    // CombinationMMI CMMI;
    // CombinationPascal CPAS(n);  
    // for (int i = 0; i <= n - 1; ++i)
    //     for (int j = 0; j <= i; ++j)
    //             cout << i << ":" <<setw(3)<< j << " " << CMMI.C(i,j) << " " <<setw(10)<< CPAS.C(i,j) << "\n";

    cout.flush();
    return 0;
}