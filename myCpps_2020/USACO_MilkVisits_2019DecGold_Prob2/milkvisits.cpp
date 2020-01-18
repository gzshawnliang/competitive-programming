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

ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

const int rot = 1;

int quickPow(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans *= a;
        }
        a *= a;

        b /= 2;
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
                if (treNodDep[sta[i][j - 1]] > treNodDep[sta[i + pow2J / 2][j - 1]])
                {
                    sta[i][j] = sta[i + pow2J / 2][j - 1];
                }
                else
                {
                    sta[i][j] = sta[i][j - 1];
                }
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

void buildPreOrd(int u, int &num, vector<int> &preOrd, vector<vector<int>> &g)
{
    preOrd[u] = num; ++num;
    
    int siz = g[u].size();
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];

        if (preOrd[v] == -1)
        {
            buildPreOrd(v, num, preOrd, g);
        }
    }
}

void buildPosOrd(int u, int &num, vector<int> &posOrd, vector<vector<int>> &g)
{
    posOrd[u] = -2;

    int siz = g[u].size();
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];

        if (posOrd[v] == -1)
        {
            buildPosOrd(v, num, posOrd, g);
        }
    }

    posOrd[u] = num; ++num;
}

bool isPar(int u, int v, vector<int> &preOrd, vector<int> &posOrd)
{
    return preOrd[u] <= preOrd[v] && posOrd[u] >= posOrd[v];
}

int main()
{
    int n, m; fin >> n >> m;

    vector<vector<int>> flavs(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int fla; fin >> fla;
        flavs[fla].push_back(i);
    }

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
    for (int i = 0; i <= sizeTreNod - 1; ++i)
    {
        treNodDep[i] = depth[treNod[i]];
    }

    vector<vector<int>> sta(sizeTreNod, vector<int>(log2SizeTreNod + 1, -1));
    buildSta(treNodDep, sta);

    int _num;

    _num = 0;
    vector<int> preOrd(n + 1, -1);
    buildPreOrd(rot, _num, preOrd, g);

    _num = 0;
    vector<int> posOrd(n + 1, -1);
    buildPosOrd(rot, _num, posOrd, g);

    for (int c_m = 1; c_m <= m; ++c_m)
    {
        int nodA, nodB, fla; fin >> nodA >> nodB >> fla;

        int LCA_AB = queryLCA(nodA, nodB, treNod, treNodDep, firPos, sta);

        bool ans = 0;
        int siz = flavs[fla].size();
        for (int i = 0; i <= siz - 1 && ans == 0; ++i)
        {
            int nowNod = flavs[fla][i];

            if (depth[nowNod] >= depth[LCA_AB] && (isPar(nowNod, nodA, preOrd, posOrd) || isPar(nowNod, nodB, preOrd, posOrd)))
            {
                ans = 1;
            }
        }

        fout << ans;
    }
    fout << '\n';

    return 0;
}
