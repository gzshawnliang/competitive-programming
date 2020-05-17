
// https://codeforces.com/contest/1355/submission/80323017
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve()
{
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll ret = 0;
    ll nall = (C - B + 1) * (D - C + 1);
    for (ll x = A; x <= B; ++x)
    {
        if (x > D - B) 
        {
            ret += nall;
        }
        else if (x >= D - C and x >= C - B)
        {
            ll n = D - B - x + 1;
            ret += nall - n * (n + 1) / 2;
        }
        else if (x < D - C and x >= C - B)
        {
            ll h = x - (C - B);
            ret += h * (1 + C - B) + 1LL * (C - B) * (C - B + 1) / 2;
        }
        else if (x >= D - C and x < C - B)
        {
            ret += nall - (C - B - x + 1) * (D - C + 1) - (D - C) * (D - C + 1) / 2;
        }
        else
        {
            ret += 1LL * x * (x + 1) / 2;
        }
    }
    cout << ret << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("CF_1355C_CountTriangles.in", "r", stdin);
    //freopen("CF_1355C_CountTriangles.out", "w", stdout);
#endif

    solve();

    cout.flush();
    return 0;
}