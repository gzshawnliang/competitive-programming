#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

ifstream fin("audiophobia_UVA10048.in");
ofstream fout("audiophobia_UVA10048.out");

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

int path(int from_u,int u, int end, int ans, vector<vector<int>> & q, vector<vector<int>> & a, vector<bool> & visit,vector<vector<int>> & bottleNeckValue)
{
    if (u == end)
    {
        return ans;
    }
    else if (visit[u] == true)
    {
        return -1;
    }

    visit[u] = true;

    int size0 = q[u].size(), finalAnswer = -1;
    for (int i = 0; i <= size0 - 1; ++i)
    {
        int result= max(ans, a[u][q[u][i]]);
        int res = path(from_u,q[u][i], end,result, q, a, visit,bottleNeckValue);
        
        bottleNeckValue[from_u][q[u][i]]=result;

        //无向图，i到j的瓶颈和j到i的一样
        bottleNeckValue[q[u][i]][from_u]=result;
        
        if (res != -1)
        {
            finalAnswer = res;
            break;
        }
    }
    
    return finalAnswer;
}

int main()
{
    int caseC = 0;
    while (true)
    {
        ++caseC;

        int ct = 0, st = 0, qt = 0;
        fin >> ct >> st >> qt;
        if (ct + st + qt == 0) break;

        if (caseC > 1)
        {
            fout << '\n';
        }

        vector<edge> ways;
        vector<int> p(ct + 1);
        for (int sc = 1; sc <= st; ++sc)
        {
            int u, v, d; fin >> u >> v >> d;

            edge temp{u, v, d};
            ways.push_back(temp);
        }
        sort(ways.begin(), ways.end());
        for (int cc = 1; cc <= ct; ++cc)
        {
            p[cc] = cc;
        }

        vector<vector<int>> q(ct + 1);
        vector<vector<int>> a(ct + 1, vector<int>(ct + 1, -1));
        
        for (int i = 0, j = 0; i <= ct - 2 && j <= st - 1; ++j)
        {
            int res0 = _find(ways[j].u, p), res1 = _find(ways[j].v, p);
            if (res0 == res1)
            {
                continue;
            }

            p[res0] = res1;
            q[ways[j].u].push_back(ways[j].v);
            q[ways[j].v].push_back(ways[j].u);
            a[ways[j].u][ways[j].v] = ways[j].d;
            a[ways[j].v][ways[j].u] = ways[j].d;

            ++i;
        }

        fout << "Case #" << caseC << '\n';

        //bottleNeckValue[i][j]——代表从i到j的瓶颈
        vector<vector<int>> bottleNeckValue(ct + 1, vector<int>(ct + 1, -1));

        for (int qc = 1; qc <= qt; ++qc)
        {
            int u, f, res; fin >> u >> f;
            vector<bool> visit(ct + 1, false);

            res=bottleNeckValue[u][f];

            if(res==-1)
            {
                //没找到存储的瓶颈，深度搜索一次
                res = path(u,u, f, -1, q, a, visit,bottleNeckValue);
            }
            
            if (res == -1)
            {
                fout << "no path\n";
            }
            else
            {
                fout << res << '\n';
            }
        }
    }

    return 0;
}