#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stack>

using namespace std;

ifstream fin("callingCircles_UVA247.in");
ofstream fout("callingCircles_UVA247.out");

void tarjan(int u, int n, int & index, vector<int> & dfn, vector<int> & low, vector<bool> & inStack, vector<vector<int>> & g, stack<int> & stk, vector<string> & names)
{
    ++index;
    dfn[u] = index; low[u] = index;
    stk.push(u); inStack[u] = true;
    
    int ans = 0;
    int size0 = g[u].size();
    for (int i = 0; i <= size0 - 1; ++i)
    {
        int v = g[u][i];
        if (dfn[v] == -1)
        {
            tarjan(v, n, index, dfn, low, inStack, g, stk, names);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v] == true)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u])
    {
        bool first = true;

        int t;
        vector<int> temp;
        do
        {
            t = stk.top();

            if (first == true)
            {
                first = false;
            }
            else
            {
                fout << ", ";
            }
            fout << names[t];

            inStack[t] = false;
            stk.pop();
        }
        while (t != u);

        fout << '\n';
    }
}

int main()
{
    int _case = 0;
    int lastN = -1, lastM = -1;
    while (true)
    {
        ++_case;

        int n = 0, m = 0;
        fin >> n >> m;
        if (n + m == 0) break;

        if (_case == 98)
        {
            cout << "";
        }

        if (_case > 1 && lastN != 0 && lastM != 0)
        {
            fout << '\n';
        }

        if (n == 0 || m == 0)
        {
            fout << "Calling circles for data set " << _case << "\n";
            continue;
        }

        vector<vector<int>> g(n + 1);
        map<string, int> _map;
        vector<string> names(n + 1);
        int nameCount = 1;
        for (int c = 1; c <= m; ++c)
        {
            string in0, in1; fin >> in0 >> in1;
            if (_map[in0] == 0)
            {
                _map[in0] = nameCount;
                names[nameCount] = in0;
                ++nameCount;
            }

            if (_map[in1] == 0)
            {
                _map[in1] = nameCount;
                names[nameCount] = in1;
                ++nameCount;
            }

            g[_map[in0]].push_back(_map[in1]);
        }

        fout << "Calling circles for data set " << _case << ":\n";

        int zero = 0, _count = 0;
        vector<int> dfn(n + 1, -1), low(n + 1, -1);
        vector<bool> inStack(n + 1, false);
        stack<int> stk;
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            if (dfn[i] == -1)
            {
                tarjan(i, n, zero, dfn, low, inStack, g, stk, names);
            }
        }

        lastN = n;
        lastM = m;
    }

    return 0;
}