#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;


int _find(int i, vector<int> & g, vector<int> & d)
{
    if (g[i] != i)
    {
        int last = g[i];
        g[i] = _find(g[i], g, d);
        d[i] += d[last];
    }
    return g[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int n; cin >> n;

    vector<int> g(n + 1), d(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
    }

    int ans = 2147483647;
    for (int i = 1; i <= n; i++)
    {
        int j; cin >> j;

        int fi = _find(i, g, d), fj = _find(j, g, d);

        if (fi != fj)
        {
            g[fi] = fj;
            d[i] = d[j] + 1;
        }
        else
        {
            ans = min(ans, d[i] + d[j] + 1);
        }
    }
    cout << ans << '\n';
   	cout.flush();
   	return 0;
}
