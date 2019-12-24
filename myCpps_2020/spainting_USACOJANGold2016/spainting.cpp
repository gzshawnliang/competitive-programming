#include <bits/stdc++.h>

using namespace std;

ifstream fin("spainting.in");
ofstream fout("spainting.out");

using ll = long long;
const ll mod = 1e9 + 7;

int main()
{
    int n, m, k; fin >> n >> m >> k;

    vector<ll> dp(n + 1, 0);

    dp[0] = 1;
    ll sum = 0;
    for (int i = 1; i <= k - 1; ++i)
    {
        dp[i] = (dp[i - 1] * m) % mod;
        sum = (sum + dp[i]) % mod;
    }

    for (int i = k; i <= n; ++i)
    {
        dp[i] = (sum * (m - 1)) % mod;
        sum = (sum - dp[i - k + 1] + dp[i] + mod) % mod;
    }

    ll total = 1;
    for (int c = 1; c <= n; ++c)
    {
        total = (total * m) % mod;
    }

    fout << (total - dp[n] + mod) % mod <<'\n';

    return 0;
}
