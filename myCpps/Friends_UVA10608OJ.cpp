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
#include <set>
#include <map>

using namespace std;


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

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCaseTotal; cin >> testCaseTotal;
    
    for (int t = 1; t <= testCaseTotal; ++t)
    {
        int n, m; cin >> n >> m;

        vector<int> p(n + 1), g(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            p[i] = i;
        }

        for (int c = 1; c <= m; ++c)
        {
            int u, v; cin >> u >> v;

            p[_find(v, p)] = p[_find(u, p)];
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ++g[_find(i, p)];
            
            ans = max(ans, g[p[i]]);
        }

        cout << ans << '\n';
    }

   	cout.flush();
   	return 0;
}

