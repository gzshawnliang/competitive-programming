/*
===========================================================
* @Name:           690D2 The Wall (medium)
* @Author:         Thomas
* @create Time:    2020/3/10 21:32:56
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

const int maxA = 1e6 + 1;
const ll MOD = 1e6 + 3;

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

    ll Lucas(ll a,ll b)     //Lucas定理递归   
    {  
        if (b == 0)         //递归终止条件
            return 1;  
        else  
            return C(a % MOD , b % MOD) * Lucas(a / MOD , b / MOD) % MOD;  
    }  
    
};

//卢卡斯第二种实现办法
//https://www.lagou.com/lgeduarticle/52320.html
class CombinationMMI2
{
    private:
    vector<ll> factorial;

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
    CombinationMMI2()
    {
    }

    ll C(ll a, ll b)    //计算C(a, b)
    {
        if (b > a)
            return 0;

        ll up = 1, down = 1;        //分子分母;
        for (int i = a - b + 1; i <= a; ++i)
            up = up * i % MOD;

        for (int i = 1; i <= b; ++i)
            down = down * i % MOD;
            
        return up * mmi(down,MOD) % MOD;
    }

    ll Lucas(ll a,ll b)     //Lucas定理递归   
    {  
        if (b == 0)         //递归终止条件
            return 1;  
        else  
            return C(a % MOD , b % MOD) * Lucas(a / MOD , b / MOD) % MOD;  
    }
};

void solve()
{
    int n,C;
    cin >> n >> C;
    CombinationMMI CMMI;
    // //逆元求大组合数：AC
    // cout << CMMI.C(n+C,C) -1 << "\n";

    // //Lucas定理求大组合数：AC
    // cout << CMMI.Lucas(n+C,C) -1 << "\n";

    CombinationMMI2 CMMI2;
    cout << CMMI2.Lucas(n+C,C) -1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_690D2_TheWall(medium).in", "r", stdin);
        //freopen("CF_690D2_TheWall(medium).out", "w", stdout);
    #endif    

    solve();

    cout.flush();
    return 0;
}