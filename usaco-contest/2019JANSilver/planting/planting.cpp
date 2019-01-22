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

ifstream fin("planting.in");
ofstream fout("planting.out");

int main()
{
    int n, ans = 0; fin >> n;

    vector<int> g(n + 1);

    for (int c = 1; c <= n - 1; ++c)
    {
        int u, v; fin >> u >> v;

        ++g[u]; ++g[v];
        

        ans = max(ans, g[u] + 1);
        ans = max(ans, g[v] + 1);
    }

    fout << ans << '\n';

    return 0;
}
