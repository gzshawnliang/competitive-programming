#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <vector>

using namespace std;

ifstream fin("comeAndGo_UVA11838.in");
ofstream fout("comeAndGo_UVA11838.out");

bool first;
bool ans;

void tarjan(int u, int & index, vector<int> & dfn, vector<int> & low, vector<bool> & inStack, stack<int> & stk, vector<vector<int>> & g)
{
    if (ans == 0) return;

    ++index;
    dfn[u] = index; low[u] = index;

    stk.push(u); inStack[u] = true;
    
    int size0 = g[u].size();

    for (int i = 0; i <= size0 - 1 && ans == 1; ++i)
    {
        int v = g[u][i];
        if (dfn[v] == -1)
        {
            tarjan(v, index, dfn, low, inStack, stk, g);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v] == true)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u])
    {
        if (first == true)
        {
            first = false;
        }
        else
        {
            ans = 0;
        }

        int t;
        do
        {
            t = stk.top();

            inStack[t] = false;
            stk.pop();
        }
        while (t != u);
    }
}

int main()
{
    while (true)
    {
        first = true;
        ans = 1;

        int n = 0, m = 0;
        fin >> n >> m;
        if (n + m == 0) break;

        vector<vector<int>> g(n + 1);
        for (int mC = 1; mC <= m; ++mC)
        {
            int u, v, p; fin >> u >> v >> p;

            g[u].push_back(v);
            if (p == 2)
            {
                g[v].push_back(u);
            }
        }

        int index = 0;
        vector<int> dfn(n + 1, -1), low(n + 1, -1);
        vector<bool> inStack(n + 1, false);
        stack<int> stk;
        for (int i = 1; i <= n && ans == 1; ++i)
        {
            if (dfn[i] == -1)
            {
                tarjan(i, index, dfn, low, inStack, stk, g);
            }
        }

        fout << ans << '\n';
    }

    return 0;
}