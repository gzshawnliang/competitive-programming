#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int ans, n, a[100], f[100], mx, b[200];

void solve()
{
    cin >> n, b[0] = 1;
    for (int i = 1; i <= n; ++i)
        b[i] = 2ll * b[i - 1] % mod;

    for (int i = 1, x; i <= n; ++i)
        cin >>x, a[x]++, mx = max(mx, x);

    for (int i = 1; i <= mx; ++i)
        for (int j = i + i; j <= mx; j += i)
            a[i] += a[j];

    for (int i = mx; i >= 2; --i)
    {
        f[i] = 1ll * b[a[i] - 1] * a[i] % mod;
        for (int j = i + i; j <= mx; j += i)
            f[i] = (f[i] - f[j]) % mod;

        ans = (ans + 1ll * f[i] * i) % mod;
    }

    cout << (ans + mod) % mod << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("CF839D.in", "r", stdin);
    //freopen("UVa11806_Cheerleaders.out", "w", stdout);
#endif

    solve();
    return 0;
}