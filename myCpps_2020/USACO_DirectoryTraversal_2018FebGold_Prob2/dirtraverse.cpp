/*
===========================================================
* @Name:           Problem 2. Directory Traversal 
* @Author:         Shawn
* @create Time:    2020/1/19 13:35:29
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=814&lang=zh
* @Description:    USACO 2018 February Contest, Gold
===========================================================
*/

#include <bits/stdc++.h>

using namespace std;

ifstream fin("dirtraverse.in");
ofstream fout("dirtraverse.out");

using ill = long long;

const ill rot = 1, inf = LLONG_MAX / 2;

ill dfsNO1(ill u, ill dis, vector<ill> &lefCount, vector<ill> &namL, vector<vector<ill>> &g)
{
    ill siz = g[u].size();
    if (siz == 0)
    {
        lefCount[u] = 1;
        return dis;
    }

    ill res = 0;
    for (ill i = 0; i <= siz - 1; ++i)
    {
        ill v = g[u][i];

        res += dfsNO1(v, dis + namL[v] + 1, lefCount, namL, g);

        lefCount[u] += lefCount[v];
    }

    if (u == rot) res -= lefCount[rot];
    return res;
}

void dfsNO2(ill u, vector<ill> &totDis, vector<ill> &fat, vector<ill> &lefCount, vector<ill> &namL, vector<vector<ill>> &g)
{
    ill siz = g[u].size();
    if (siz == 0)
    {
        return;
    }
    else if (u != rot)
    {
        totDis[u] = totDis[fat[u]] + 3 * (lefCount[rot] - lefCount[u]) - (namL[u] + 1) * lefCount[u];
    }

    for (ill i = 0; i <= siz - 1; ++i)
    {
        ill v = g[u][i];
        dfsNO2(v, totDis, fat, lefCount, namL, g);
    }
}

int main()
{
    ill n; fin >> n;

    vector<ill> namL(n + 1, 0), fat(n + 1, 0);
    vector<vector<ill>> g(n + 1);
    for (ill u = 1; u <= n; ++u)
    {
        string nam; fin >> nam;
        namL[u] = nam.size();

        ill siz; fin >> siz;
        vector<ill> tmp(siz);
        for (ill i = 0; i <= siz - 1; ++i)
        {
            fin >> tmp[i];
            fat[tmp[i]] = u;
        }

        g[u] = tmp;
    }

    vector<ill> lefCount(n + 1, 0), totDis(n + 1, inf);
    totDis[rot] = dfsNO1(rot, 0, lefCount, namL, g);

    dfsNO2(rot, totDis, fat, lefCount, namL, g);

    fout << *min_element(totDis.begin(), totDis.end()) << '\n';

    return 0;
}
