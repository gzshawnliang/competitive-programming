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
#include <queue>
#include <map>

using namespace std;


struct point
{
    int y;
    int x;

    bool operator < (const point & temp) const
    {
        return y < temp.y && x < temp.x;
    }
};

struct edge
{
    int u;
    int v;
    double d;

    bool operator < (const edge & temp) const
    {
        return d < temp.d;
    }
};

double distance(point & u, point & v)
{   
    return sqrt((u.y - v.y) * (u.y - v.y) + (u.x - v.x) * (u.x - v.x));
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
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int c = 1; c <= testCase; ++c)
    {
        int n, r; cin >> n >> r;
        vector<point> cities;
        vector<int> p(n);
        vector<edge> ways;
        for (int k = 0; k <= n - 1; ++k)
        {
            int y; int x; cin >> y >> x;
            point now{y, x};

            for (int i = 0; i <= k - 1; ++i)
            {
                edge temp{i, k, distance(now, cities[i])};
                ways.push_back(temp);
            }
            cities.push_back(now);
        }
        sort(ways.begin(), ways.end());
        for (int k = 0; k <= n - 1; ++k)
        {
            p[k] = k;
        }

        int sizeWays = ways.size(), totalStates = 1;
        double lengthRoads = 0.0, lengthRailroads = 0.0;
        for (int i = 0, j = 0; i <= n - 2 && j <= sizeWays - 1; ++j)
        {
            if (_find(ways[j].u, p) == _find(ways[j].v, p)) continue;

            _union(ways[j].u, ways[j].v, p);
            
            if (ways[j].d >= r)
            {
                ++totalStates;
                lengthRailroads += ways[j].d;
            }
            else
            {
                lengthRoads += ways[j].d;
            }

            ++i;
        }

        int out1 = (int)(lengthRoads + 0.5), out2 = (int)(lengthRailroads + 0.5);
        
        cout << "Case #" << c << ": " << totalStates << ' ' << out1 << ' ' << out2 << '\n';
    }

   	cout.flush();
   	return 0;
}
