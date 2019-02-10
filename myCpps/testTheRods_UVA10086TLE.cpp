#include <bits/stdc++.h>

using namespace std;

ifstream fin("testTheRods_UVA10086.in");
ofstream fout("testTheRods_UVA10086.out");

struct pos
{
    int i;
    int p;
    int q;
};

pos _pos(int i, int p, int q)
{
    pos temp{i, p, q}; return temp;
}

int main()
{
    while (true)
    {
        int t1 = 0, t2 = 0; fin >> t1 >> t2;
        if (t1 + t2 == 0) break;

        int n; fin >> n;
        vector<vector<int>> c1(n), c2(n);
        for (int i = 0; i <= n - 1; ++i)
        {
            int m; fin >> m;

            c1[i].push_back(0);
            for (int c = 1; c <= m; ++c)
            {
                int temp; fin >> temp;
                c1[i].push_back(temp);
            }

            c2[i].push_back(0);
            for (int c = 1; c <= m; ++c)
            {
                int temp; fin >> temp;
                c2[i].push_back(temp);
            }
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(t1 + 1, vector<int>(t2 + 1, INT_MAX / 2)));
        vector<vector<vector<pos>>> f(n, vector<vector<pos>>(t1 + 1, vector<pos>(t2 + 1, _pos(-1, -1, -1))));
        for (int i = 0; i <= n - 1; ++i)
        {
            int m = c1[i].size() - 1;
            for (int p = 0; p <= t1; ++p)
            {
                for (int q = 0; q <= t2; ++q)
                {
                    if (i == 0)
                    {
                        if (p + q <= m)
                        {
                            dp[i][p][q] = c1[i][p] + c2[i][q];
                            f[i][p][q] = _pos(i, p, q);
                        }
                    }
                    else
                    {

                        for (int a = 0; a <= p && a <= m; ++a)
                        {
                            for (int b = 0; b <= q && b <= m; ++b)
                            {
                                if (a + b > m)
                                {
                                    break;
                                }

                                int get = dp[i - 1][p - a][q - b] + c1[i][a] + c2[i][b];
                                if (dp[i][p][q] > get)
                                {
                                    dp[i][p][q] = get;
                                    f[i][p][q] = _pos(i - 1, p - a, q - b);
                                }
                            }
                        }
                    }
                }
            }
        }

        // for (int i = 0; i <= n - 1; ++i)
        // {
        //     int m = c1[i].size() - 1;
        //     for (int p = 0; p <= t1; ++p)
        //     {
        //         for (int q = 0; q <= t2; ++q)
        //         {
        //             fout << "dp[" << i << ' ' << p << ' ' << q << "] = " << dp[i][p][q] << "  "
        //                  << "f[" << i << ' ' << p << ' ' << q << "] = "
        //                  << f[i][p][q].i << ' ' << f[i][p][q].p << ' ' << f[i][p][q].q << '\n';
        //         }
        //     }
        // }
        // fout << "\n\n";

        fout << dp[n - 1][t1][t2] << '\n';

        vector<int> out;
        pos last{n - 1, t1, t2}, now{f[n - 1][t1][t2].i, f[n - 1][t1][t2].p, f[n - 1][t1][t2].q};

        //fout << '\n' << last.i << ' ' << last.p << ' ' << last.q << '\n'; // out

        while (f[now.i][now.p][now.q].i != now.i)
        {
            out.push_back(last.p - now.p);

            //fout << now.i << ' ' << now.p << ' ' << now.q << '\n'; // out

            last = now; now = _pos(f[now.i][now.p][now.q].i, f[now.i][now.p][now.q].p, f[now.i][now.p][now.q].q);
        }

        //fout << now.i << ' ' << now.p << ' ' << now.q << "\n\n"; // out

        out.push_back(last.p - now.p);
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
