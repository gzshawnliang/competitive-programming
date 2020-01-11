/*
===========================================================
* @Name:           Problem 3. Fenced In 
* @Author:         Shawn
* @create Time:    2020/1/11 22:53:07
* @url:            http://www.usaco.org/index.php?page=viewproblem2&cpid=623&lang=en
* @Description:    USACO 2016 February Contest, Gold
===========================================================
*/
#include <bits/stdc++.h>

using namespace std;

ifstream fin("fencedin.in");
ofstream fout("fencedin.out");

struct edge
{
    int u;
    int v;
    int d;

    bool operator < (const edge & temp) const
    {
        return d < temp.d;
    }
};
edge _edge(int u, int v, int d)
{
    edge temp{u, v, d}; return temp;
}

int _find(int u, vector<int> & p)
{
    if (p[u] == u)
    {
        return u;
    }
    else
    {
        int ans = _find(p[u], p);
        p[u] = ans;
        return ans;
    }
}

void _union(int u, int v, vector<int> & p)
{
    p[_find(u, p)] = _find(v, p);
}


int main()
{
    int nx, ny, n, m; fin >> nx >> ny >> n >> m;

    vector<int> vw(n), hw(m);
    for (int i = 0; i <= n - 1; ++i) fin >> vw[i];
    for (int i = 0; i <= m - 1; ++i) fin >> hw[i];

    vw.push_back(0); vw.push_back(nx); n += 2;
    hw.push_back(0); hw.push_back(ny); m += 2;

    sort(vw.begin(), vw.end());
    sort(hw.begin(), hw.end());

    vector<edge> doors;
    for (int i = 0; i <= n - 2; ++i)
    {
        for (int j = 0; j <= m - 2; ++j)
        {
            int nowN = j * (n - 1) + i;

            if (i < n - 2)
            {
                int nextI = i + 1, nextJ = j, nextN = nextJ * (n - 1) + nextI;

                doors.push_back(_edge(nowN, nextN, hw[j + 1] - hw[j]));
            }

            if (j < m - 2)
            {
                int nextI = i, nextJ = j + 1, nextN = nextJ * (n - 1) + nextI;

                doors.push_back(_edge(nowN, nextN, vw[i + 1] - vw[i]));
            }
        }
    }
    sort(doors.begin(), doors.end());

    vector<int> p((n - 1) * (m - 1), 0);
    for (int i = 0; i <= (n - 1) * (m - 1) - 1; ++i)
    {
        p[i] = i;
    }

    int minCst = 0, sizD = doors.size();
    for (int i = 0, j = 0; i <= (n - 1) * (m - 1) - 1 && j <= sizD - 1; ++j)
    {
        if (_find(doors[j].u, p) == _find(doors[j].v, p)) continue;

        _union(doors[j].u, doors[j].v, p);
        minCst += doors[j].d;

        ++i;
    }

    fout << minCst << '\n';

    return 0;
}
