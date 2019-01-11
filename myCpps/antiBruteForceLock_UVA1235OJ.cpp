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

int rollCount(string key0, string key1)
{
    int ans = 0;
    for (int i = 0; i <= 3; ++i)
    {
        ans += min(abs(key0[i] - key1[i]), 10 - abs(key0[i] - key1[i]));
    }

    return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int testCase; cin >> testCase;
    for (int c0 = 1; c0 <= testCase; ++c0)
    {
        int n, minToGet = 36; cin >> n;
        vector<string> keys(n);
        vector<int> p(n);
        vector<edge> ways;
        for (int i = 0; i <= n - 1; ++i)
        {
            cin >> keys[i];
            minToGet = min(minToGet, rollCount("0000", keys[i]));
            for (int j = 0; j <= i - 1; ++j)
            {
                edge temp{i, j, rollCount(keys[i], keys[j])};
                ways.push_back(temp);
            }
        }
        sort(ways.begin(), ways.end());
        for (int i = 0; i <= n - 1; ++i)
        {
            p[i] = i;
        }

        int total = 0, sizeWays = ways.size();
        for (int i = 0, j = 0; i <= n - 2 && j <= sizeWays - 1; ++j)
        {
            int res0 = _find(ways[j].u, p), res1 = _find(ways[j].v, p);
            if (res0 == res1)
            {
                continue;
            }


            p[res0] = p[res1];
            total += ways[j].d;

            ++i;
        }

        cout << minToGet + total << '\n';
    }

   	cout.flush();
   	return 0;
}
