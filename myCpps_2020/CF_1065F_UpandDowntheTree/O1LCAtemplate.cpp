/*
===========================================================
* @Name:           1065F Up and Down the Tree
* @Author:         Shawn
* @create Time:    2020/3/19 21:24:47
* @url:            https://codeforces.com/contest/1065/problem/F
* @Description:    
===========================================================
*/
#ifdef ONLINE_JUDGE
#define NDEBUG //ban assert when submit to online judge
#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
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

int queryMin(int i, int j, vector<int> & treNod, vector<int> & treNodDep, vector<vector<int>> & sta)
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
int queryLCA(int u, int v, vector<int> & treNod, vector<int> & treNodDep, vector<int> & firPos, vector<vector<int>> & sta)
{
    return queryMin(min(firPos[u], firPos[v]), max(firPos[u], firPos[v]), treNod, treNodDep, sta);
}

void buildSta(vector<int> & treNodDep, vector<vector<int>> & sta)
{
    int sizeTreNod = treNodDep.size(),
        log2SizeTreNod = log2(sizeTreNod);

    int pow2J = 1;
    for (int j = 0; j <= log2SizeTreNod; ++j)
    {
        for (int i = 0; i + pow2J - 1 <= sizeTreNod - 1; ++i)
        {
            if (j == 0)
                sta[i][j] = i;
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

void buildTreNod(int u, vector<int> & treNod, vector<int> & firPos, vector<int> & depth, vector<vector<int>> & g)
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

void buildPreOrd(int u, int & num, vector<int> & preOrd, vector<vector<int>> & g)
{
    preOrd[u] = num;
    ++num;

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

void solve()
{
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int u = 2; u <= n; ++u)
    {
        int las; cin >> las;
        g[las].push_back(u);
    }

    vector<int> treNod, firPos(n + 1, -1), depth(n + 1, -1);
    depth[rot] = 0;
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

    auto getLCA=[&](int nodA, int nodB)
    {
        return queryLCA(nodA, nodB, treNod, treNodDep, firPos, sta);
    };

    
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("CF_1065F_UpandDowntheTree.in", "r", stdin);
        freopen("CF_1065F_UpandDowntheTree.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}