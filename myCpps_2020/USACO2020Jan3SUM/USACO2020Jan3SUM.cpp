/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/12/22 22:59:00  (UTC+08:00)
* @Url:            
* @Description:    
-------------------------------------------------------------------
                                     /~\
                                    |oo )
                                    _\=/_
                    ___        #   /  _  \
                   / ()\        \\//|/.\|\\
                 _|_____|_       \/  \_/  ||
                | | === | |         |\ /| ||
                |_|  O  |_|         \_ _/  #
                 ||  O  ||          | | |
                 ||__*__||          | | |
                |~ \___/ ~|         []|[]
                /=\ /=\ /=\         | | |
________________[_]_[_]_[_]________/_]_[_\_________________________
*/

#include <bits/stdc++.h>

using namespace std;

ifstream fin("threesum.in");
ofstream fout("threesum.out");

const int maxN = 1e6;

using ill = long long;

int main()
{
    int n, m; fin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) fin >> a[i];

    vector<int> cntN(maxN * 4 + 1, 0);
    vector<vector<ill>> f(n + 1, vector<ill>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            f[i][j] = cntN[- a[i] - a[j] + maxN * 2];
            ++cntN[a[j] + maxN * 2];
        }

        for (int j = i + 1; j <= n; ++j)
            cntN[a[j] + maxN * 2] = 0;
    }
    for (int len = 3; len <= n; ++len)
    {
        for (int i = 1; i + len - 1 <= n; ++i)
        {
            int j = i + len - 1;
            f[i][j] += f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
        }
    }

    for (int c = 1; c <= m; ++c)
    {
        int p, q; fin >> p >> q;
        fout << f[p][q] << '\n';
    }

    return 0;
}
