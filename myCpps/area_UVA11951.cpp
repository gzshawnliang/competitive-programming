#include <bits/stdc++.h>

using namespace std;

ifstream fin("area_UVA11951.in");
ofstream fout("area_UVA11951.out");

int main()
{
    int testCase; fin >> testCase;
    for (int t = 1; t <= testCase; ++t)
    {
        long long n, m, k; fin >> n >> m >> k;
        vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0)), dp(n + 1, vector<long long>(m + 1, 0));

        for (int y = 1; y <= n; ++y)
        {
            for (int x = 1; x <= m; ++x)
            {
                fin >> a[y][x];

                dp[y][x] = dp[y][x - 1] + a[y][x];
            }
        }

        long long ansS = 0, ansC = 0;
        for (int x1 = 1; x1 <= m; ++x1)
        {
            for (int x2 = x1; x2 <= m; ++x2)
            {
                for (int y1 = 1; y1 <= n; ++y1)
                {
                    long long sum = 0;
                    for (int y2 = y1; y2 <= n; ++y2)
                    {
                        long long size = (x2 - x1 + 1) * (y2 - y1 + 1);

                        sum += dp[y2][x2] - dp[y2][x1 - 1];

                        if (sum > k)
                        {
                            break;
                        }
                        else if (ansS <= size)
                        {
                            if (ansS == size)
                            {
                                ansC = min(ansC, sum);
                            }
                            else
                            {
                                ansC = sum;
                            }
                            ansS = size;
                        }
                    }
                }
            }
        }

        fout << "Case #" << t << ": " << ansS << ' ' << ansC << '\n';
    }

    return 0;
}
