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
    int testCase = 0;
    while (true)
    {
        ++testCase;

        int n, m; cin >> n >> m;

        if (n + m == 0) break;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            p[i] = i;
        }

        for (int c = 1; c <= m; ++c)
        {
            int u, v; cin >> u >> v;

            p[_find(v, p)] = p[_find(u, p)];
        }

        set<int> s;
        for (int i = 1; i <= n; ++i)
        {
            s.insert(_find(i, p));
        }

        cout << "Case " << testCase << ": " << s.size() << '\n';
    }

   	cout.flush();
   	return 0;
}

