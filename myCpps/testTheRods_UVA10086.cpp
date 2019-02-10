#include <bits/stdc++.h>

using namespace std;

ifstream fin("testTheRods_UVA10086.in");
ofstream fout("testTheRods_UVA10086.out");

struct pos
{
    int p;
    int q;

    bool operator == (const pos & temp) const
    {
        return p == temp.p && q == temp.q;
    }
};

pos _pos(int p, int q)
{
    pos temp{p, q}; return temp;
}

int main()
{
    while (true)
    {
        int t1, t2; fin >> t1 >> t2;
        if (t1 == 0 && t2 == 0) break;

        int n = 0; fin >> n;
        
        vector<vector<int>> dp(t1 + 1, vector<int>(t2 + 1, INT_MAX / 2));
        vector<vector<pos>> f(t1 + 1, vector<pos>(t2 + 1));

        for (int p = 0; p <= t1; ++p)
        {
            for (int q = 0; q <= t2; ++q)
            {
                f[p][q] = _pos(p, q);
            }
        }

        dp[0][0] = 0;
        int _count = 0;

        for (int i = 0; i <= n - 1; ++i)
        {
            int m; fin >> m;

            vector<int> c1(m + 1), c2(m + 1);

            for (int j = 1; j <= m; ++j)
            {
                fin >> c1[j];
            }

            for (int j = 1; j <= m; ++j)
            {
                fin >> c2[j];
            }

            c1[0] = 0; c2[0] = 0;

            for (int c = 0; c <= m; ++c)
            {
                for (int p = 0; p <= _count; ++p)
                {
                    int nowP = p + c, nowCount = _count + m;
                    if (nowP <= t1 && nowCount - nowP <= t2)
                    {
                        int get = dp[p][_count - p] + c1[c] + c2[m - c];
                        if (dp[nowP][nowCount - nowP] > get)
                        {
                            dp[nowP][nowCount - nowP] = get;
                            f[nowP][nowCount - nowP] = _pos(p, _count - p);
                        }
                    }
                }
            }

            _count += m;
        }

        fout << dp[t1][t2] << '\n';

        pos now{t1, t2};
        vector<int> out;

        while (!(f[now.p][now.q] == _pos(now.p, now.q)))
        {
            out.push_back(now.p - f[now.p][now.q].p);

            now = f[now.p][now.q];
        }
        out.push_back(now.p);

        for (int i = n - 1; i >= 0; --i)
        {
            if (i != n - 1) fout << ' ';
            fout << out[i];
        }

        fout << "\n\n";
    }
    return 0;
}
