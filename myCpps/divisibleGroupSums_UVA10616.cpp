#include <bits/stdc++.h>

using namespace std;

ifstream fin("divisibleGroupSums_UVA10616.in");
ofstream fout("divisibleGroupSums_UVA10616.out");

int main()
{
    int t = 0;
    while (true)
    {
        ++t;

        int n = 0, q = 0; fin >> n >> q;
        if (n + q == 0) break;

        vector<long long> in(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> in[i];
        }

        fout << "SET " << t << ":\n";

        for (int qi = 1; qi <= q; ++qi)
        {
            int m, d; fin >> d >> m;

            long long _max = 0;
            vector<long long> a = in;

            for (int i = 0; i <= n - 1; ++i)
            {
                a[i] %= d;
                if (a[i] < 0)
                {
                    a[i] += d;
                }

                _max += a[i];
            }

            vector<vector<long long>> dp(n + 2, vector<long long>(_max * 2 + 1, 0));

            dp[0][0] = 1;
            for (int i = 0; i <= n - 1; ++i)
            {
                for (int c = n; c >= 0; --c)
                {
                    for (int s = 0; s <= _max; ++s)
                    {
                        dp[c + 1][s + a[i]] += dp[c][s];
                    }
                }
            }

            long long ans = 0;

            if (m <= n)
            {
                for (int s = 0; s <= _max; s += d)
                {
                    ans += dp[m][s];
                }
            }
            

            fout << "QUERY " << qi << ": " << ans << '\n';
        }
    }

    return 0;
}
