#include <bits/stdc++.h>

using namespace std;

ifstream fin("nocross.in");
ofstream fout("nocross.out");

int main()
{
    int n; fin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        fin >> b[i];
    }

    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0)),
                        g(n + 1, vector<int>(n + 1, 0));
    f[0][0] = 0;
    g[0][0] = 0;

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (abs(a[i] - b[j]) <= 4)
            {
                int maxLast = 0;
                for (int k = 1; k <= i - 1; ++k)
                {
                    maxLast = max(maxLast, g[k][j - 1]);
                }

                f[i][j] = maxLast + 1;
            }

            g[i][j] = max(g[i][j - 1], f[i][j]);
            ans = max(ans, f[i][j]);
        }
    }

    fout << ans << '\n';

    return 0;
}
