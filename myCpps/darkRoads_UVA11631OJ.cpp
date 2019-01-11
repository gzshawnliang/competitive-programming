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
#include <queue>
#include <map>

using namespace std;


struct edge
{
    int u;
    int v;
    int d;

    bool operator < (const edge temp) const
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

void _union(int u, int v, vector<int> & p)
{
    p[_find(u, p)] = _find(v, p);
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    while (true)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<int> p(n);
        vector<edge> roads;
        for (int i = 0; i <= n - 1; ++i)
        {
            p[i] = i;
        }

        int totalCost = 0;
        for (int c = 1; c <= m; ++c)
        {
            int u, v, d; cin >> u >> v >> d;
            totalCost += d;
            edge temp{u, v, d};
            roads.push_back(temp);
        }
        sort(roads.begin(), roads.end());

        int minCost = 0;
        for (int i = 0, j = 0; i <= n - 2 && j <= m - 1; ++j)
        {
            if (_find(roads[j].u, p) == _find(roads[j].v, p)) continue;

            _union(roads[j].u, roads[j].v, p);
            minCost += roads[j].d;

            ++i;
        }

        cout << totalCost - minCost << '\n';
    }

   	cout.flush();
   	return 0;
}
