/*
-------------------------------------------------------------------
* @Name:           
* @Author:         Shawn
* @Create Time:    2020/12/24 21:20:25  (UTC+08:00)
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

ifstream fin("fcolor.out");
ofstream fout("fcolorOutT.out");

int main()
{
    int u = 1, maxN = 1e5 + 1;
    vector<vector<int>> a(maxN + 1);

    int fa;
    while (fin >> fa)
    {
        a[fa].push_back(u);
        ++u;
    }

    for (int u = 1; u <= maxN; ++u)
    {
        if (a[u].size() == 0) break;

        fout << u << ": ";
        for (auto x:a[u])
            fout << x << ' ';
        fout << '\n';
    }

    // int n, m; fin >> n >> m;
    
    // vector<vector<int>> g(n + 1);
    // for (int c = 1; c <= m; ++c)
    // {
    //     int u, v; fin >> u >> v;
    //     fout << v << ' ' << u << '\n';
    // }

    return 0;
}
