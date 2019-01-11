#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <stack>

using namespace std;


void tarjan(int u, int n, int & index, vector<int> & dfn, vector<int> & low, vector<bool> & inStack, vector<vector<int>> & g, stack<int> & stk, vector<int> & res, int & _count)
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
            tarjan(v, n, index, dfn, low, inStack, g, stk, res, _count);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v] == true)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u])
    {
        ++_count;

        int t;
        vector<int> temp;
        do
        {
            t = stk.top();

            res[t] = _count;

            inStack[t] = false;
            stk.pop();
        }
        while (t != u);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    double totalTime=0;

    int testCase; cin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int n, m, finalAnswer = 0; cin >> n >> m;
        vector<vector<int>> g(n + 1);
         
        for (int k = 1; k <= m; ++k)
        {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
        }
        
        int zero = 0, _count = 0;
        vector<int> dfn(n + 1, -1), low(n + 1, -1);
        vector<bool> inStack(n + 1, false);
        stack<int> stk;
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            if (dfn[i] == -1)
            {
                tarjan(i, n, zero, dfn, low, inStack, g, stk, res, _count);
            }
        }

        vector<bool> inDegree0(_count + 1, true);

        for (int i = 1; i <= n; ++i)
        {
            int size = g[i].size();
            for (int j = 0; j <= size - 1; ++j)
            {
                if (res[i] != res[g[i][j]])
                {
                    inDegree0[res[g[i][j]]] = false;
                }
            }
        }

        for (int c = 1; c <= _count; ++c)
        {
            if (inDegree0[c] == true)
            {
                ++finalAnswer;
            }
        }

        cout << finalAnswer << '\n';
    }

   	cout.flush();
   	return 0;
}
