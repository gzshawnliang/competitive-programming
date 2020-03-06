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
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
std::map<int, int> mp;

int pow(int x, int p)
{
    int ret = 1;
    for (; p; p >>= 1, x = 1LL * x * x % mod)
        if (p & 1)
            ret = 1LL * ret * x % mod;
    return ret;
}
void upd(int & x, int y)
{
    x = (x + y) % mod;
}
int solve(int n)
{
    if (n == 1)
        return 1;
    if (mp.count(n))
        return mp[n];
    int ans = 0;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            upd(ans, solve(i));
            if (i * i != n)
                upd(ans, solve(n / i));
        }
    }
    upd(ans, solve(1));
    ans = (pow(2, n - 1) - ans + mod) % mod;
    return mp[n] = ans;
}
int _solve()
{
    int x, y;
    scanf("%d%d", &x, &y);
    if (y % x)
        return puts("0"), 0;
    printf("%d\n", solve(y / x));
    return 0;
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

    _solve();

    cout.flush();
    return 0;
}