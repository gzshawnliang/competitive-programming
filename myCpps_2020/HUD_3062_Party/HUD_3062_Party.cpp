/*
===========================================================
* @Name:           Party
* @Author:         Shawn
* @create Time:    2020/02/03 18:49:00
* @url:            http://acm.hdu.edu.cn/showproblem.php?pid=3062
* @Description:    2-SAT模板,Tarjan SCC
===========================================================
*/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

using ll = long long;

int ano(int x)
{
    if (x % 2 == 0) return x + 1;
    else            return x - 1;
}

void dfs(int u, int &cnt, vector<int> &ids, vector<int> &low, vector<int> &inStack, stack<int> &stk, vector<vector<int>> &g)
{
    stk.push(u); inStack[u] = 1;
    
    ids[u] = cnt; low[u] = cnt; ++cnt;

    for (auto ite = g[u].begin(); ite != g[u].end(); ++ite)
    {   
        int v = *ite;
        if (ids[v] == -1) dfs(v, cnt, ids, low, inStack, stk, g);

        if (inStack[v] == true)
        {
            low[u] = min(low[u], low[v]);
        }
    }

    if (ids[u] == low[u])
    {
        while (stk.empty() == false)
        {
            int i = stk.top(); stk.pop();
            
            inStack[i] = 0;
            low[i] = ids[u];

            if (i == u) break;
        }
    }
}

void solve()
{
    while (true)
    {
        int n = 0; cin >> n;
        if (n == 0) break;

        vector<vector<int>> g(n * 2);

        int m; cin >> m;
        for (int c = 1; c <= m; ++c)
        {
            int a1, a2, c1, c2; cin >> a1 >> a2 >> c1 >> c2;

            int u = a1 * 2 + c1, v = a2 * 2 + c2;
            g[u].push_back(ano(v));
            g[v].push_back(ano(u));
        }

        int cnt = 0;
        vector<int> ids(n * 2, -1), low(n * 2, 0), inStack(n * 2, 0);
        stack<int> stk;

        for (int u = 0; u <= 2 * n - 1; ++u)
        {
            if (ids[u] == -1) dfs(u, cnt, ids, low, inStack, stk, g);
        }

        bool flg = true;
        for (int u = 0; u <= 2 * n - 2; u += 2)
        {
            if (low[u] == low[u + 1])
            {
                flg = false;
                break;
            }
        }

        if (flg == true) cout << "YES\n";
        else             cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE    //Submit to OJ in standard input/output,debug in local .in/.out file
        freopen("HUD_3062_Party.in", "r", stdin);
        freopen("HUD_3062_Party.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}