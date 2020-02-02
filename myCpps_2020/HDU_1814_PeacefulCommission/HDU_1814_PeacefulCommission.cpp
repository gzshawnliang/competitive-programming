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
    if (x % 2 == 0) return x - 1;
    else            return x + 1;
}

bool dfs(int u, vector<int> &vis, vector<int> &pth, vector<vector<int> > &g)
{
    if (vis[ano(u)] == 1) return false;
    if (vis[u] == 1) return true;

    vis[u] = 1;
    pth.push_back(u);

    int siz = g[u].size();
    for (int i = 0; i <= siz - 1; ++i)
    {
        int v = g[u][i];
        if (dfs(v, vis, pth, g) == false) return false;
    }

    return true;
}

void solve()
{
    while (true)
    {
        int n = 0, m = 0; cin >> n >> m;
        if (n + m == 0) break;

        vector<vector<int> > g(n * 2 + 1);

        for (int c = 1; c <= m; ++c)
        {
            int u, v; cin >> u >> v;
            g[u].push_back(ano(v)); g[v].push_back(ano(u));
        }

        bool ans = true;
        vector<int> vis(n * 2 + 1, 0), pth;
        for (int u = 1; u <= n * 2; u += 2)
        {
            if (vis[u] == true || vis[u + 1] == true) continue;

            pth.clear();
            if (dfs(u, vis, pth, g) == false)
            {
                int siz = pth.size();
                for (int i = 0; i <= siz - 1; ++i) vis[pth[i]] = 0;

                pth.clear();
                if (dfs(u + 1, vis, pth, g) == false)
                {
                    ans = false;
                    break;
                }
            }
        }

        if (ans == false)
        {
            cout << "NIE\n";
        }
        else
        {
            for (int u = 1; u <= n * 2; ++u)
            {
                if (vis[u] == 1) cout << u << '\n';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    #ifndef ONLINE_JUDGE    //Submit to OJ in standard input/output,debug in local .in/.out file
        freopen("HDU_1814_PeacefulCommission.in", "r", stdin);
        freopen("HDU_1814_PeacefulCommission.out", "w", stdout);
    #endif    

    solve();


    cout.flush();
    return 0;
}