#include <bits/stdc++.h>

using namespace std;

ifstream fin("divingForGold_UVA990.in");
ofstream fout("divingForGold_UVA990.out");

const int inf = INT_MAX / 2;

struct treasure
{
    int d;
    int v;
};
treasure _treasure(int d, int v)
{
    treasure temp{d, v}; return temp;
}

struct pos
{
    int i;
    int j;
};
pos _pos(int i, int j)
{
    pos temp{i, j}; return temp;
}

int main()
{
    bool isFirst = true;
    while (true)
    {
        int t = 0, w = 0; fin >> t >> w;
        if (t + w == 0) break;

        if (isFirst == false) fout << '\n';
        isFirst = false;

        int n = 0; fin >> n;
        vector<treasure> a(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            fin >> a[i].d >> a[i].v;
        }

        vector<vector<int>> dp(n, vector<int>(t + 1, 0));
        pos _null{-1, -1}; vector<vector<pos>> f(n, vector<pos>(t + 1, _null));
        for (int i = 0; i <= n - 1; ++i)
        {
            int now = 3 * w * a[i].d;
            for (int j = 0; j <= t; ++j)
            {
                if (i == 0)
                {
                    if (j >= now) dp[i][j] = a[i].v;
                }
                else
                {
                    if (j >= now)
                    {
                        if (dp[i - 1][j - now] + a[i].v > dp[i - 1][j])
                        {
                            dp[i][j] = dp[i - 1][j - now] + a[i].v;
                            f[i][j] = _pos(i - 1, j - now);
                        }
                        else
                        {
                            dp[i][j] = dp[i - 1][j];
                            f[i][j] =  _pos(i - 1, j);
                        }
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                        f[i][j] =  _pos(i - 1, j);
                    }
                }
            }
        }

        fout << dp[n - 1][t] << '\n';

        pos now = {n - 1, t};
        vector<treasure> ans;
        while (now.i >= 0)
        {
            pos last = f[now.i][now.j];

            if (now.j > last.j && now.j >= 3 * w * a[now.i].d)
            {
                ans.push_back(a[now.i]);
            }

            now = last;
        }

        int size = ans.size();
        fout << size << '\n';
        for (int i = size - 1; i >= 0; --i)
        {
            fout << ans[i].d << ' ' << ans[i].v << '\n';
        }
    }

    return 0;
}
