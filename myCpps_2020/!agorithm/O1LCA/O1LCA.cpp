/*
===========================================================
* @Name:           Problem 2. Milk Visits 
* @Author:         Shawn
* @create Time:    2020/1/18 18:21:23
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=970&lang=zh
* @Description:    USACO 2019 December Contest, Gold
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("O1LCA.in");
ofstream fout("O1LCA.out");

const int rot = 1;


int quickPow(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1) ans *= a;

        a *= a; b /= 2;
    }

    return ans;
}

int queryMin(int i, int j, vector<int> &treNod, vector<int> &treNodDep, vector<vector<int>> &sta)
{
    int l = j - i + 1,
        log2L = log2(l);

    int i2 = j - quickPow(2, log2L) + 1;
    if (treNodDep[sta[i][log2L]] > treNodDep[sta[i2][log2L]])
    {
        return treNod[sta[i2][log2L]];
    }
    else
    {
        return treNod[sta[i][log2L]];
    }
}
int queryLCA(int u, int v, vector<int> &treNod, vector<int> &treNodDep, vector<int> &firPos, vector<vector<int>> &sta)
{
    return queryMin(min(firPos[u], firPos[v]), max(firPos[u], firPos[v]), treNod, treNodDep, sta);
}

void buildSta(vector<int> &treNodDep, vector<vector<int>> &sta)
{
    int sizeTreNod = treNodDep.size(),
        log2SizeTreNod = log2(sizeTreNod);

    int pow2J = 1;
    for (int j = 0; j <= log2SizeTreNod; ++j)
    {
        for (int i = 0; i + pow2J - 1 <= sizeTreNod - 1; ++i)
        {
            if (j == 0) sta[i][j] = i;
            else
            {
                if (treNodDep[sta[i][j - 1]] > treNodDep[sta[i + pow2J / 2][j - 1]]) sta[i][j] = sta[i + pow2J / 2][j - 1];
                else                                                                 sta[i][j] = sta[i][j - 1];
            }
        }

        pow2J *= 2;
    }
}

void buildTreNod(int u, vector<int> &treNod, vector<int> &firPos, vector<int> &depth, vector<vector<int>> &g)
{
    treNod.push_back(u);
    firPos[u] = treNod.size() - 1;

    int siz = g[u].size();
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];

        if (depth[v] == -1)
        {
            depth[v] = depth[u] + 1;
            buildTreNod(v, treNod, firPos, depth, g);

            treNod.push_back(u);
        }
    }
}

int main()
{
    int n; fin >> n;
    vector<vector<int>> g(n + 1);
    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v; fin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

        vector<int> treNod, firPos(n + 1, -1), depth(n + 1, -1); depth[rot] = 0;
    buildTreNod(rot, treNod, firPos, depth, g);
        int sizeTreNod = treNod.size(),
            log2SizeTreNod = log2(sizeTreNod);
        vector<int> treNodDep(sizeTreNod, 0);
    for (int i = 0; i <= sizeTreNod - 1; ++i) treNodDep[i] = depth[treNod[i]];

        vector<vector<int>> sta(sizeTreNod, vector<int>(log2SizeTreNod + 1, -1));
    buildSta(treNodDep, sta);

    auto lca=[&](int a, int b)
    {
        return queryLCA(a, b, treNod, treNodDep, firPos, sta);
    };

    fout << lca(8, 9) << '\n';

    return 0;
}