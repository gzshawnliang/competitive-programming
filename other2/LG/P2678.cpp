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

ifstream fin("P2678.in");
ofstream fout("P2678.out");

bool solve(int l, int m, vector<int> & dis)
{
    int total = 0, n = dis.size(), last = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        if (dis[i] - dis[last] < l)
        {
            ++total;
        }
        else
        {
            last = i;
        }
    }

    return total <= m;
}

int main()
{
    int ld, n, m; fin >> ld >> n >> m;
    vector<int> dis(n + 2);
    for (int i = 1; i <= n; ++i)
    {
        fin >> dis[i];
    }
    dis[0] = 0;
    dis[n + 1] = ld;

    int l = 0, r = ld, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (solve(mid, m, dis) == true)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    fout << ans << '\n';

    return 0;
}