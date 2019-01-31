#include <bits/stdc++.h>

using namespace std;

ifstream fin("localizedSummingForBlurring_UVA983.in");
ofstream fout("localizedSummingForBlurring_UVA983.out");

int main()
{
    bool first = false;
    while (true)
    {
        int n = 0, m = 0; fin >> n >> m;
        if (n == 0) break;

        if (first == true) fout << '\n';
        first = true;

        vector<vector<long long>> a(n + 1, vector<long long>(n + 1, 0)),
                                  dpY(n + 1, vector<long long>(n + 1, 0)),
                                  dpX(n + 1, vector<long long>(n + 1, 0));

        for (int y = n; y >= 1; --y)
        {
            for (int x = 1; x <= n; ++x)
            {
                fin >> a[y][x];

                dpY[y][x] = dpY[y][x - 1] + a[y][x];
            }
        }

        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= n; ++y)
            {
                dpX[x][y] = dpX[x][y - 1] + a[y][x];
            }
        }

        int k = n - m + 1;
        vector<vector<long long>> ans(k + 1, vector<long long>(k + 1, 0));

        for (int y = 1; y <= k; ++y)
        {
            for (int x = 1; x <= k; ++x)
            {
                if (y == 1 && x == 1)
                {
                    for (int _y = 1; _y <= m; ++_y)
                    {
                        for (int _x = 1; _x <= m; ++_x)
                        {
                            ans[y][x] += a[_y][_x];
                        }
                    }
                }
                else
                {
                    if (x == 1)
                    {
                        ans[y][x] = ans[y - 1][x] - dpY[y - 1][x + m - 1] + dpY[m + y - 1][x + m - 1];
                    }
                    else
                    {
                        ans[y][x] = ans[y][x - 1] - (dpX[x - 1][m + y - 1] - dpX[x - 1][y - 1]) + (dpX[x + m - 1][m + y - 1] - dpX[x + m - 1][y - 1]);
                    }
                }
            }
        }

        int total = 0;
        for (int y = k; y >= 1; --y)
        {
            for (int x = 1; x <= k; ++x)
            {
                fout << ans[y][x] << '\n';
                total += ans[y][x];
            }
        }

        fout << total << '\n';
    }

    return 0;
}
