#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 400, mod = 1000007;

ll fastmod(ll a, ll b, ll p) //费马小定理
{
    ll cnt = 1;
    while (b)
    {
        if (b & 1)
            cnt = (cnt * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return cnt;
}

ll Comb(ll a,ll b,ll p) //组合数
{
    ll ca = 1, cb = 1, tmp = 1;
    ;
    if (a < b)
        return 0;
    if (a == b)
        return 1;
    if (b > a - b)
        b = a - b;
        
    for (ll i = 0; i < b; ++i)
    {
        ca = (ca * (a - i)) % p;
        cb = (cb * (b - i)) % p;
    }
    tmp = (ca * fastmod(cb, p - 2, p)) % p; //除法转换求逆元
    return tmp;
}

ll Lucas(ll n, ll m, ll p,vector<vector<int>> & C) 
{
  if (m == 0) 
    return 1;
  return Comb(n % p,m % p,p) * Lucas(n / p, m / p, p,C) % p;
}



int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        //freopen("Lucas.in", "r", stdin);
        //freopen("Lucas.out", "w", stdout);
    #endif    

    vector<vector<int>> C(N + 1, vector<int>(N + 1, 0)); 
    C[0][0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
            }
        }
    }

    cout <<  Lucas(12,5,17,C) << "\n";


    cout.flush();
    return 0;
}