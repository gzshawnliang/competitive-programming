/*
===========================================================
* @Name:           Problem 1. Snow Boots 
* @Author:         Shawn
* @create Time:    2020/1/21 16:54:34
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=813&lang=zh
* @Description:    USACO 2018 February Contest, Gold
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

struct snow
{
    int dep;
    int id;

    bool operator < (const snow & tmp) const
    {
        return dep > tmp.dep;
    }
};

struct boot
{
    int dep;
    int dis;
    int id;

    bool operator < (const boot & tmp) const
    {
        return dep > tmp.dep;
    }
};

int main()
{
    int n, m; fin >> n >> m;

    snow nulS{0 ,0};
    boot nulB{0, 0, 0};

    vector<snow> a(n + 1, nulS);
    vector<boot> b(m + 1, nulB);
    for (int i = 1; i <= n; ++i)
    {
        fin >> a[i].dep; a[i].id = i;
    }
    for (int i = 1; i <= m; ++i)
    {
        fin >> b[i].dep >> b[i].dis; b[i].id = i;
    }

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    vector<int> nex(n + 2), las(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        nex[i] = i + 1; las[i] = i - 1;
    }

    int j = 1, maxD = 1;
    vector<int> ans(m + 1, 0);
    for (int i = 1; i <= m; ++i)
    {
        while (j <= n && a[j].dep > b[i].dep)
        {
            nex[las[a[j].id]] = nex[a[j].id];
            las[nex[a[j].id]] = las[a[j].id];

            maxD = max(maxD, nex[a[j].id] - las[a[j].id]);

            ++j;
        }

        ans[b[i].id] = (b[i].dis >= maxD);
    }

    for (int i = 1; i <= m; ++i)
    {
        fout << ans[i] << '\n';
    }

    return 0;
}
