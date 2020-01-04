#include <bits/stdc++.h>

using namespace std;

ifstream fin("snakes.in");
ofstream fout("snakes.out");

const int inf = INT_MAX / 4;

int main()
{
    int n, k; fin >> n >> k;
    
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i];
    }

    vector<vector<int>> maxA(n + 1, vector<int>(n + 1, inf)),
                        sumA(n + 1, vector<int>(n + 1, 0));
    for (int i1 = 1; i1 <= n; ++i1)
    {
        int nowMax = 0;
        for (int i2 = i1; i2 <= n; ++i2)
        {
            nowMax = max(nowMax, a[i2]);
            maxA[i1][i2] = nowMax;

            sumA[i1][i2] = sumA[i1][i2 - 1] + a[i2];
        }
    }

    vector<vector<int>> f(k + 1, vector<int>(n + 1, inf));

    int sum;
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];

        f[0][i] = maxA[1][i] * i - sumA[1][i];
    }
    f[1][1] = 0;

    for (int j = 1; j <= k; ++j)
    {
        for (int i1 = 2; i1 <= n; ++i1)
        {
            f[j][i1] = f[j - 1][i1];
            for (int i2 = 1; i2 <= i1 - 1; ++i2)
            {
                f[j][i1] = min(f[j][i1], f[j - 1][i2] + maxA[i2 + 1][i1] * (i1 - i2) - sumA[i2 + 1][i1]);
            }
        }
    }

    fout << f[k][n] << '\n';

    return 0;
}
