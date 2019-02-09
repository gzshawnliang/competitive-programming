#include <bits/stdc++.h>

using namespace std;

ifstream fin("aGroupingProblem_UVA11026.in");
ofstream fout("aGroupingProblem_UVA11026.out");

int main()
{
    while (true)
    {
        int n = 0, m = 0; fin >> n >> m;
        if (n + m == 0) break;

        long long sum = 0, ans = -1;
        vector<long long> a(n, 0), dp(n + 1, 0);

        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i];

            sum += (a[i] * a[i]);
            dp[1] += a[i];
        }

        ans = max(ans, dp[1] % m);
        for (int k = 2; k <= n; ++k)
        {
            

            ans = max(ans, dp[k] % m);
        }
    }

    return 0;
}
