/*
===========================================================
* @Name:           900D Unusual Sequences
* @Author:         Shawn
* @create Time:    2020/3/6 23:09:46
* @url:            https://codeforces.com/contest/900/problem/D
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
    #define NDEBUG      //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ill = long long;

const ill mod = 1e9 + 7;

ill quickPow(ill a, ill b)
{
    a %= mod;

    ill ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans *= a; ans %= mod;
        }
        a *= a; a %= mod;

        b /= 2;
    }

    return ans;
}

ill searc(ill x, map<ill, ill> & mmp)
{
    if      (x == 1)           return 1;
    else if (mmp.count(x) > 0) return mmp[x];

    ill cnt = quickPow(2, x - 1);
    for (ill i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
                            cnt = (cnt + mod - searc(i, mmp)) % mod;
            if (i * i != x) cnt = (cnt + mod - searc(x / i, mmp)) % mod;
        }
    }
    cnt = (cnt + mod - searc(1, mmp)) % mod;

    mmp[x] = cnt;
    return cnt;
}

void solve()
{
    ill x, y; cin >> x >> y;

    if (y % x > 0)
    {
        cout << "0\n";
        return;
    }

    map<ill, ill> mmp; mmp[1] = 1;
    cout << searc(y / x, mmp) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_900D_UnusualSequences.in", "r", stdin);
        freopen("CF_900D_UnusualSequences.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}